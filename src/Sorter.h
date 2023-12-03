#ifndef SORTER_H
#define SORTER_H

#include <string>
#include <list>
#include <iostream>
#include "sortingmethod.h"

class Sorter {
    private:
        // List/stack of sorting methods
        std::list<SortingMethod> methods;

    public:
        /* Returns the filesystem::path object for the image */
        void sortToMisc(const std::string& origionalDirectory, const std::string& miscDirectory);
        void makeTempCopy(const std::string& sourcePath, const std::string& destPath);
        void deleteTempCopy(const std::string& destPath);
        bool sort(int target, int minRange, int maxRange); // integer
        //bool sort(Metadata data, float minRange, float maxRange, const std::string & key);//float
        //bool sort(Metadata data, const std::string& str, const std::string & key);//string
        //bool sort();//date
        //bool sort();//time

        /* --- GETTERS --- */
        std::list<SortingMethod>& getMethods();

};

#endif
