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
        
        int id;
        static int idCounter;
        
    public:
        // Default constructor
        Anchor();
        Anchor(std::string directory, std::string outputDirectory, Sorter& sorter);
        Anchor(std::filesystem::path directory, std::filesystem::path outputDirectory, Sorter& sorter);

        /* --- GETTERS --- */
        // Returns the path to the anchor directory
        std::filesystem::path getDirectory();

        // Returns the output directory for the anchor
        std::filesystem::path getOutputDirectory();
        
        // Returns the sorter object for the anchor
        Sorter& getSorter();

        // Returns the Anchor's ID
        int getID();

        /* --- SETTERS --- */
        // Sets the path to the anchor directory
        void setDirectory(std::string path);
        void setDirectory(std::filesystem::path path);

        // Sets the path to the output directory
        void setOutputDirectory(std::string path);
        void setOutputDirectory(std::filesystem::path path);

        // Sets the sorter object for the anchor
        void setSorter(Sorter& sorter);
};

// Iterates through an anchor, checks for any changes, and calls on the sorter to sort if there are.
void update(Anchor anchor);

#endif