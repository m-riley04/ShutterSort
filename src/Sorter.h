#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <fstream> 
#include <string> 
#include <filesystem>

class Sorter {
    public:
        /* Returns the filesystem::path object for the image */
        void sortToMisc(const std::string& origionalDirectory, const std::string& miscDirectory);
};

#endif