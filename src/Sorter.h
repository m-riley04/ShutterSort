#ifndef SORTER_H
#define SORTER_H

#include <iostream>
#include <fstream> 
#include <string>
#include <filesystem>
#include "metadata.cpp"

class Sorter {
    public:
        /* Returns the filesystem::path object for the image */
        void sortToMisc(const std::string& origionalDirectory, const std::string& miscDirectory);
        void makeTempCopy(const std::string& sourcePath, const std::string& destPath);
        void deleteTempCopy(const std::string& destPath);
        void sort(Metadata data, int minRange, int maxRange,const std::string & key);//int 
        void sort(Metadata data, float minRange, float maxRange, const std::string & key);//float
        void sort(Metadata data, const std::string& str, const std::string & key);//string
        void sort();//date
        void sort();//time

};

#endif