#include "metadata.h"
#include <exiv2/exiv2.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <codecvt>
#include <locale>
#include <cstdint>
#include <map>

// Adds or updates a metadata value.
void Metadata::set(const std::string& key, const std::any& value) {
    this->data[key] = value;
}

// Retrieves a metadata value, returns an empty string if not found.
std::any Metadata::get(const std::string& key) {
    auto it = this->data.find(key);
    if (it != this->data.end()) {
        return std::any(it->second);
    }
    return std::any();
}

// Convert numeric values to a string representation
std::string numericValueToString(const Exiv2::Exifdatum& datum) {
    std::ostringstream oss;
    oss << datum.value();
    return oss.str();
}

// Function to convert binary data to a hexadecimal string
std::string binaryToHexString(const std::string& binaryData) {
    std::ostringstream oss;
    for (unsigned char c : binaryData) {
        oss << std::hex << std::uppercase << std::setfill('0') << std::setw(2) << static_cast<int>(c) << " ";
    }
    return oss.str();
}

// Parses a USC2 encoded string into a normal std::string
std::string parseUcs2String(const std::string& input) {
    std::istringstream iss(input);
    std::vector<uint16_t> ucs2data;
    int number;

    // Parse the input string into numbers and store them as UCS-2 data
    while (iss >> number) {
        if (number < 0 || number > 255) {
            std::cerr << "Invalid number in input: " << number << std::endl;
            continue; // Skip invalid numbers
        }
        ucs2data.push_back(static_cast<uint16_t>(number));
    }

    // Check if the UCS-2 data is correct
    if (ucs2data.size() % 2 != 0) {
        std::cerr << "Incomplete UCS-2 data. Odd number of elements." << std::endl;
        return ""; // Return an empty string or handle the error as appropriate
    }

    std::string ucs2String;
    for (size_t i = 0; i < ucs2data.size(); i += 2) {
        uint16_t wc = ucs2data[i] | (ucs2data[i + 1] << 8);
        ucs2String.push_back(static_cast<char>(wc & 0xFF));
        ucs2String.push_back(static_cast<char>((wc >> 8) & 0xFF));
    }

    return ucs2String;
}

// Function to convert a UCS-2 encoded byte value to a UTF-8 string
std::string ucs2leToUtf8(const std::string& ucs2le) {
    std::string utf8;
    for (size_t i = 0; i < ucs2le.size(); i += 2) {
        if (i + 1 >= ucs2le.size()) {
            break;
        }

        uint16_t wc = static_cast<unsigned char>(ucs2le[i]) | (static_cast<unsigned char>(ucs2le[i + 1]) << 8);

        if (wc >= 0xD800 && wc <= 0xDFFF) {
            continue; // Skip surrogate pairs (not handled)
        }
        else if (wc < 0x0080) {
            utf8 += static_cast<char>(wc);
        }
        else if (wc < 0x0800) {
            utf8 += 0xC0 | ((wc >> 6) & 0x1F);
            utf8 += 0x80 | (wc & 0x3F);
        }
        else {
            utf8 += 0xE0 | ((wc >> 12) & 0x0F);
            utf8 += 0x80 | ((wc >> 6) & 0x3F);
            utf8 += 0x80 | (wc & 0x3F);
        }
    }

    return utf8;
}

std::string checkTagMap(std::string& tag) {
    std::map<std::string, std::string> tagMap = {
        {"Exif.Sony2.0x1003", "Exif.Sony2.Panorama"},
        {"Exif.Sony2.0x2001", "Exif.Sony2.PreviewImage"},
        {"Exif.Sony2.0x2002", "Exif.Sony2.Rating"},
        {"Exif.Sony2.0x2004", "Exif.Sony2.Contrast"},
        {"Exif.Sony2.0x2005", "Exif.Sony2.Saturation"},
        {"Exif.Sony2.0x2006", "Exif.Sony2.Sharpness"},
        {"Exif.Sony2.0x2007", "Exif.Sony2.Brightness"},
    };

    auto it = tagMap.find(tag);
    if (it != tagMap.end()) {
        // Found the tag, process it
        tag = tagMap[tag];
    }

    return tag;
}

// Helper for Metadata load() function
void Metadata::load_helper(Exiv2::ExifData data) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it->value().count() > 0) { // Ensuring the value is not empty
            std::string key = it->key();
            std::any value;

            switch (it->value().typeId()) {
                case Exiv2::signedByte:
                case Exiv2::unsignedShort:
                case Exiv2::signedShort:
                case Exiv2::unsignedLong:
                case Exiv2::signedLong:
                case Exiv2::unsignedRational:
                case Exiv2::signedRational:
                    // Handle numeric and rational types
                    value = std::any(double(it->value().toFloat())); // numericValueToString(*it);
                    break;
                case Exiv2::unsignedByte:
                    // Special handling for UCS-2 encoded byte values
                    value = std::any(ucs2leToUtf8(parseUcs2String(it->value().toString())));
                    break;
                case Exiv2::asciiString:
                    // Handle ASCII strings directly
                    value = std::any(it->value().toString());
                    break;
                case Exiv2::undefined:
                    // Handle undefined (binary) data
                    value = std::any(it->value().toString());//binaryToHexString(it->value().toString());
                    break;
                default:
                    // Fallback for other types
                    value = std::any(it->value().toString());
                    break;
            }

            set(checkTagMap(key), value);
        }
    }
}

// Loads metadata from a file path string
void Metadata::load(std::string path) {
    // Read metadata of specific image
    Exiv2::Image::UniquePtr image = Exiv2::ImageFactory::open(path);
    if (image.get() == nullptr) {
        std::cerr << "Error opening image file!" << std::endl;
        return;
    }

    image->readMetadata();
    Exiv2::ExifData& data = image->exifData();

    this->load_helper(data);
}

// Loads metadata from an exiv2 object
void Metadata::load(Exiv2::ExifData data) {
    this->load_helper(data);
}

// Checks if a metadata key exists.
bool Metadata::contains(const std::string& key) {
    return this->data.find(key) != this->data.end();
}

// Removes a metadata key-value pair.
void Metadata::remove(const std::string& key) {
    this->data.erase(key);
}

// Function to clear all metadata.
void Metadata::clear() {
    this->data.clear();
}

// Function to get the total number of metadata entries.
size_t Metadata::size() {
    return this->data.size();
}

// A function to print all metadata for debugging purposes.
void Metadata::printAll() {
    // Blacklist for all incompatable Exif tags
    std::string blacklist[] = {
        "Exif.Photo.0xea1c", 
        "Exif.Image.0xea1c", 
        "Exif.Image.PrintImageMatching", 
        "Exif.Image.XMLPacket",
        "Exif.Photo.MakerNote",
        };
    int n = sizeof(blacklist) / sizeof(*blacklist);

    for (const auto& kv : data) {
        const auto& val = kv.second;

        if (val.type() == typeid(std::string)) {
            std::cout << kv.first << ": " << std::any_cast<std::string>(val) << std::endl;
        }
        else if (val.type() == typeid(double)) {
            std::cout << kv.first << ": " << std::any_cast<double>(val) << std::endl;
        }
        else if (val.type() == typeid(int)) {
            std::cout << kv.first << ": " << std::any_cast<int>(val) << std::endl;
        }
        else if (val.type() == typeid(float)) {
            std::cout << kv.first << ": " << std::any_cast<float>(val) << std::endl;
        }
        else {
            std::cout << kv.first << ": [Unsupported type]" << std::endl;
        }
    }
}