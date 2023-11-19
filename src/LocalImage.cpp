#include <filesystem>
#include <cstring>

#include "localimage.h"

// Default constructor
LocalImage::LocalImage() {}

// Parameterized constructor using std::string
LocalImage::LocalImage(std::string path) {
    this->path = path;

    this->metadata.load(path);
}

LocalImage::LocalImage(std::filesystem::path path) {
    this->path = path.string();

    this->metadata.load(this->path);
}

/* --- GETTERS --- */
// Returns a filesystem::path object
std::string LocalImage::getPath() {
    return this->path;
}

// Returns a Metadata object
Metadata LocalImage::getMetadata() {
    return this->metadata;
}

/* --- SETTERS --- */
// Set the path variable given a string
void LocalImage::setPath(std::string &path) {
    this->path = path;
}

// Set the path variable given an array of characters (string)
void LocalImage::setPath(char path[]) {
    this->path = std::string(path);
}

// Sets the metadata of the image using a Metadata object
void LocalImage::setMetadata(Metadata metadata) {
    this->metadata = metadata;
}