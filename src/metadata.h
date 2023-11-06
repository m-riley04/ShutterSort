#ifndef METADATA_H
#define METADATA_H

#include <string>
#include <map>
#include <iostream>
#include <exiv2/exiv2.hpp>

class Metadata {
    private:
    // Using a map to store key-value pairs of metadata.
    std::map<std::string, std::string> data;

    public:
        // Adds or updates a metadata value.
        void set(const std::string& key, const std::string& value);

        // Retrieves a metadata value, returns an empty string if not found.
        std::string get(const std::string& key);

        // Loads a metadata with values
        void load(std::string path);
        void load(Exiv2::ExifData data);

        // Checks if a metadata key exists.
        bool contains(const std::string& key);

        // Removes a metadata key-value pair.
        void remove(const std::string& key);

        // Function to clear all metadata.
        void clear();

        // Function to get the total number of metadata entries.
        size_t size();

        // A function to print all metadata for debugging purposes.
        void printAll();
};

#endif