#include "metadata.h"
#include <exiv2/exiv2.hpp>

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

// Loads metadata from a file path string
void Metadata::load(std::string path) {
    // Read metadata of specific image
    auto image = Exiv2::ImageFactory::open(path);
    if (image.get() == nullptr) {
        std::cerr << "Error opening image file!" << std::endl;
        return;
    }

    image->readMetadata();
    Exiv2::ExifData& data = image->exifData();

    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it->value().count() > 0) { // Ensuring the value is not empty
            std::string key = it->key();
            std::string value = it->value().toString();
            set(key, value);
        }
    }
}

// Loads metadata from an exiv2 object
void Metadata::load(Exiv2::ExifData data) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it->value().count() > 0) { // Ensuring the value is not empty
            std::string key = it->key();
            std::string value = it->value().toString();
            set(key, value);
        }
    }
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