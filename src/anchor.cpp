#include "anchor.h"
#include "localimage.h"
#include "sorter.h"
#include <string>
#include <thread>
#include <iostream>

using namespace std;
namespace fs = filesystem;

// Constructor
Anchor::Anchor(){};
Anchor::Anchor(std::string directory, std::string outputDirectory, Sorter& sorter, int updateInterval) {
    this->directory = std::filesystem::path(directory);
    this->outputDirectory = std::filesystem::path(outputDirectory);
    this->sorter = sorter;
    this->updateInterval = updateInterval;
}
Anchor::Anchor(std::filesystem::path directory, std::filesystem::path outputDirectory, Sorter& sorter, int updateInterval) {
    this->directory = directory;
    this->outputDirectory = outputDirectory;
    this->sorter = sorter;
    this->updateInterval = updateInterval;
}

// Iterates through the anchor directory, checks for any changes, and calls on the sorter to sort if there are.
void Anchor::update()
{
    std::cout << "Checking for changes in Anchor" << std::endl;

    // Check if the directory is empty. If it is, do nothing.
    if (fs::is_empty(directory))
    {
        std::cout << "Anchor is empty." << std::endl;
        return;
    }

    // TODO: Make a copy of all images within the folder

    // TODO: Move all non-image entries to the miscellaneous directory

    // Loop through every file in the input directory with a directory_iterator
    for (fs::path const &dir_entry : std::filesystem::directory_iterator{directory}) {
        // Get the name of the current file
        fs::path filename = dir_entry.filename();

        // Print file that is being moved
        std::cout << "File found: " << filename << endl;

        // Create LocalImage object to be loaded
        LocalImage image(dir_entry);
        Metadata metadata = image.getMetadata();

        // Call on the sorter to check all sorting methods
        bool matches = true;
        for (SortingMethod& sortingMethod : this->sorter.getMethods())
        {
            // Print the current sorting method being checked
            std::cout << "Current Sorting Method: " << sortingMethod.getName() << std::endl;
 
            //----
            //TODO - Check type from string (instead of only doing integers)
            //----

            // Initialize the variables for sorting
            std::function<bool(int, int, int)> method = sortingMethod.getMethod();
            string tag = sortingMethod.getTag();
            string name = sortingMethod.getName();
            int min = sortingMethod.getMin();
            int max = sortingMethod.getMax();
            int val;

            // Check if tag exists in metadata
            if (!metadata.contains(tag))
            {
                matches = false;
                std::cout << "ERROR: Metadata for '" << name << "'does not contain tag '" << tag << "'." << std::endl;
                break;
            }
            val = std::stoi(metadata.get(tag));


            // Test the sorting function
            if (!method(val, min, max))
            {
                matches = false;
                std::cout << "Failed Sorting Method Test: " << name << std::endl;
                break;
            }
        }

        // Get the sorted folder name
        fs::path output = this->outputDirectory;

        // Concat an unsorted folder name if all sorting methods do not match
        if (!matches)
        {
            // Check if an unsorted folder exists. If it doesn't, create it.
            output /= "Unsorted";
            if (!fs::exists(output))
            {
                fs::create_directory(output);
            }
        }

        // Concat file name to final output folder
        output /= filename;

        // Move file to the main output folder
        fs::rename(dir_entry, output);
        std::cout << "File '" << filename << "' was moved." << std::endl;
    }

    // Tell the user it is finished updating
    std::cout << "Updated Anchor." << std::endl;
}