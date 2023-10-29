#include <filesystem>
#include <cstring>
//#include <exiv2/exiv2.hpp> // Exiv2 is having errors within the Docker container, so I am commenting out Exiv2 segments for now.

#include "localimage.h"

// Default constructor
LocalImage::LocalImage() {}

// Parameterized constructor using filesystem::path
LocalImage::LocalImage(std::filesystem::path &p) {
    path = p;
}

// Parameterized constructor using std::string
LocalImage::LocalImage(std::string &p) {
    path = std::filesystem::path(p);
}

/* --- GETTERS --- */
// Returns a filesystem::path object
std::filesystem::path LocalImage::getPath() {
    return path;
}

/* --- SETTERS --- */
// Set the path variable given a filesystem::path object
void LocalImage::setPath(std::filesystem::path &path) {
    path = path;
}

// Set the path variable given a string
void LocalImage::setPath(std::filesystem::path &path) {

}

// Set the path variable given an array of characters (string)
void LocalImage::setPath(char path[]) {

}