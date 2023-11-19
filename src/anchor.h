#ifndef ANCHOR_H
#define ANCHOR_H

#include <filesystem>
#include <string>
#include "sorter.h"

class Anchor {
    private:
        std::filesystem::path directory;
        std::filesystem::path outputDirectory;
        Sorter sorter;
        int updateInterval = 1000;
        
    public:
        // Default constructor
        Anchor();
        Anchor(std::string directory, std::string outputDirectory, Sorter& sorter, int updateInterval = 1000);
        Anchor(std::filesystem::path directory, std::filesystem::path outputDirectory, Sorter& sorter, int updateInterval = 1000);
        
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


        /* --- GETTERS --- */
        // Returns the path to the anchor directory
        std::filesystem::path getDirectory();

        // Returns the output directory for the anchor
        std::filesystem::path getOutputDirectory();
        
        // Returns the sorter object for the anchor
        Sorter getSorter();

        // Returns the update interval (in milliseconds)
        int getInterval();
};

#endif