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
        void makeTempCopy(const std::string& sourcePath, const std::string& destPath);
        void deleteTempCopy(const std::string& destPath);
        //bool sort(const std::string& filename, int minRange, int maxRange);//int 
        //bool sort(const std::string& filename, const std::string& searchString);//string
        //void sort();//float
        //void sort();//date
        //void sort();//time

};

#endif