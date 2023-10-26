#ifndef LOCALIMAGE_H
#define LOCALIMAGE_H

#include <filesystem>
#include <cstring>
//#include <exiv2/exiv2.h>
class LocalImage {
    private:
        std::filesystem::path path;
        //Exiv2::Image image;

    public:
        /*Constructor for the LocalImage class*/
        LocalImage(std::filesystem::path &p);

        /*Returns the filesystem::path object for the image*/
        std::filesystem::path getPath();

        /*Returns an Exiv2::Image object for the image*/
        //Exiv2::Image getImage(){};
};

#endif