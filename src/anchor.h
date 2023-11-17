#ifndef ANCHOR_H
#define ANCHOR_H

#include <filesystem>
#include "sorter.h"

class Anchor {
    private:
        std::filesystem::path directory;
        std::filesystem::path outputDirectory;
        int updateInterval = 1000;
        Sorter sorter;

    public:
        // Default constructor
        Anchor();
        
        /*  
            Checks for any new files in the anchor folder. 
            If there are files, calls on the sorter and moves them to the output folder. 
        */
        void update();

        /* 
            Checks for any new files in the given input folder. 
            If there are files, calls on the sorter and moves them to the given output folder. 
        */
        void update(const std::filesystem::path input, const std::filesystem::path output);

        // Returns the path to the anchor directory
        void getPath();

        // Returns the update interval (in milliseconds)
        void getInterval();
};

#endif