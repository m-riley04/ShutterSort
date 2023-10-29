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
        // Constructor for the LocalImage class
        LocalImage();
        LocalImage(std::filesystem::path &p);
        LocalImage(std::string &p);

        /* --- GETTERS --- */
        // Returns the path to the image file 
        std::filesystem::path getPath();

        // Returns the Exiv2::Image object
        //Exiv2::Image getImage();

        /* --- SETTERS ---*/
        // Sets the path to the image file
        void setPath(std::filesystem::path &path);
        void setPath(std::string &path);
        void setPath(char path[]);
};

#endif