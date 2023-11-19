#include "metadata.h"
#include <exiv2/exiv2.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <codecvt>
#include <locale>

// Adds or updates a metadata value.
void Metadata::set(const std::string& key, const std::string& value) {
    data[key] = value;
}

// Retrieves a metadata value, returns an empty string if not found.
std::string Metadata::get(const std::string& key) {
    auto it = data.find(key);
    if (it != data.end()) {
        return it->second;
    }
    return "";
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

// Function to convert a UCS-2 encoded byte value to a UTF-8 string
std::string ucs2ToUtf8(const std::string& ucs2Str) {
    std::u16string utf16String;

    for (size_t i = 0; i + 1 < ucs2Str.size(); i += 2) {
        char16_t utf16Char = static_cast<char16_t>(static_cast<unsigned char>(ucs2Str[i])
            | (static_cast<unsigned char>(ucs2Str[i + 1]) << 8));
        utf16String.push_back(utf16Char);
    }

    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    return convert.to_bytes(utf16String);
}

// Helper for Metadata load() function
void Metadata::load_helper(Exiv2::ExifData data) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it->value().count() > 0) { // Ensuring the value is not empty
            std::string key = it->key();
            std::string value;

            switch (it->value().typeId()) {
            case Exiv2::signedByte:
            case Exiv2::unsignedShort:
            case Exiv2::signedShort:
            case Exiv2::unsignedLong:
            case Exiv2::signedLong:
            case Exiv2::unsignedRational:
            case Exiv2::signedRational:
                // Handle numeric and rational types
                value = numericValueToString(*it);
                break;
            case Exiv2::unsignedByte:
                // Special handling for UCS-2 encoded byte values
                value = ucs2ToUtf8(it->value().toString());
                break;
            case Exiv2::asciiString:
                // Handle ASCII strings directly
                value = it->value().toString();
                break;
            case Exiv2::undefined:
                // Handle undefined (binary) data
                value = binaryToHexString(it->value().toString());
                break;
            default:
                // Fallback for other types
                value = it->value().toString();
                break;
            }

            set(key, value);
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
    return data.find(key) != data.end();
}

// Removes a metadata key-value pair.
void Metadata::remove(const std::string& key) {
    data.erase(key);
}

// Function to clear all metadata.
void Metadata::clear() {
    data.clear();
}

// Function to get the total number of metadata entries.
size_t Metadata::size() {
    return data.size();
}

// A function to print all metadata for debugging purposes.
void Metadata::printAll() {
    for (const auto& kv : data) {
        std::cout << kv.first << ": " << kv.second << std::endl;
    }
}