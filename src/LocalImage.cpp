#include <filesystem>
#include <cstring>
//#include <exiv2/exiv2.hpp>
#include "LocalImage.h"

LocalImage::LocalImage(std::filesystem::path &p) : path(p) {

    printf("Hello world!");
}

std::filesystem::path LocalImage::getPath() {

    return path;
}