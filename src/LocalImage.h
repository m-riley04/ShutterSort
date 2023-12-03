#ifndef LOCALIMAGE_H
#define LOCALIMAGE_H

#include <filesystem>
#include "metadata.h"

class LocalImage {
    private:
        std::string path;
        Metadata metadata;

    public:
        // Constructor for the LocalImage class
        LocalImage();
        LocalImage(std::string path);
        LocalImage(std::filesystem::path path);

        /* --- GETTERS --- */
        // Returns the path to the image file 
        std::string getPath();

        // Returns the metadata object
        Metadata getMetadata();

        /* --- SETTERS ---*/
        // Sets the path to the image file
        void setPath(std::string& path);
        void setPath(char path[]);

        // Sets the metadata
        void setMetadata(Metadata metadata);
};

#endif
