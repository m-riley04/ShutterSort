#include <filesystem>
#include <cstring>

#include "localimage.h"

// Default constructor
LocalImage::LocalImage() {}

// Parameterized constructor using std::string
LocalImage::LocalImage(std::string path) {
    _path = path;

    _metadata.load(path);
}

/* --- GETTERS --- */
// Returns a filesystem::path object
std::string LocalImage::getPath() {
    return _path;
}

// Returns a Metadata object
Metadata LocalImage::getMetadata() {
    return _metadata;
}

/* --- SETTERS --- */
// Set the path variable given a string
void LocalImage::setPath(std::string &path) {
    _path = path;
}

// Set the path variable given an array of characters (string)
void LocalImage::setPath(char path[]) {
    _path = std::string(path);
}

// Sets the metadata of the image using a Metadata object
void LocalImage::setMetadata(Metadata metadata) {
    _metadata = metadata;
}