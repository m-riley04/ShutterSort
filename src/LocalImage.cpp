#include <filesystem>
#include <cstring>
//#include <exiv2/exiv2.hpp>
#include "LocalImage.h"

// Default constructor
LocalImage::LocalImage() {

    path = std::filesystem::path();
}

// Parameterized constructor
LocalImage::LocalImage(std::filesystem::path &p) {
    path = p;
}

std::filesystem::path LocalImage::getPath() {

    return path;
}