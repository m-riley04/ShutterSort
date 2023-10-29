#include <filesystem>
#include <cstring>
//#include <exiv2/exiv2.hpp>
#include "localimage.h"

// Default constructor
LocalImage::LocalImage() {

    path = std::filesystem::path();
}

// Parameterized constructor with std::string
LocalImage::LocalImage(std::string &p) {
    path = std::filesystem::path(p);
}

// Parameterized constructor with filesystem::path
LocalImage::LocalImage(std::filesystem::path &p) {
    path = p;
}

std::filesystem::path LocalImage::getPath() {

    return path;
}