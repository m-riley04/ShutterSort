#include "anchor.h"
#include "localimage.h"
#include "sorter.h"
#include <string>
#include <thread>
#include <iostream>
#include <any>

using namespace std;
namespace fs = filesystem;

// Constructor
Anchor::Anchor(){};
Anchor::Anchor(std::string directory, std::string outputDirectory, Sorter& sorter, int interval) {
    this->directory = std::filesystem::path(directory);
    this->outputDirectory = std::filesystem::path(outputDirectory);
    this->sorter = sorter;
    this->interval = interval;
}
Anchor::Anchor(std::filesystem::path directory, std::filesystem::path outputDirectory, Sorter& sorter, int interval) {
    this->directory = directory;
    this->outputDirectory = outputDirectory;
    this->sorter = sorter;
    this->interval = interval;
}

std::filesystem::path Anchor::getDirectory() {
    return directory;
}

std::filesystem::path Anchor::getOutputDirectory() {
    return outputDirectory;
}


Sorter& Anchor::getSorter() {
    return sorter;
}

// Returns the update interval for an anchor
int Anchor::getInterval() {
    return interval;
}

//----- VALUE SORTING METHODS ------------------------------------------------------

// Sorts a target integer between 2 values
bool sort_int(int target, int minRange, int maxRange) {
    if (minRange <= target && target <= maxRange) { return true; }
    return false;
}

// Sorts a target double between 2 values
bool sort_double(double target, double minRange, double maxRange) {
    if (minRange <= target && target <= maxRange) { return true; }
    return false;
}

// Sorts a target float between 2 values
bool sort_float(float target, float minRange, float maxRange) {
    if (minRange <= target && target <= maxRange) { return true; }
    return false;
}

// Checks if a string is within another string
bool sort_string(std::string target, std::string str) {
    if (str.find(target) > 0) { return true; }
    return false;
}
//----------------------------------------------------------------------------------

// Iterates through an anchor, checks for any changes, and calls on the sorter to sort if there are.
void update(Anchor anchor)
{
    std::cout << "Checking for changes in Anchor" << std::endl;

    // Check if the directory is empty. If it is, do nothing.
    if (fs::is_empty(anchor.getDirectory()))
    {
        std::cout << "Anchor is empty." << std::endl;
        return;
    }

    // TODO: Make a copy of all images within the folder


    // TODO: Move all non-image entries to the miscellaneous directory


    // Loop through every file in the input directory with a directory_iterator
    for (fs::path const &dir_entry : std::filesystem::directory_iterator{ anchor.getDirectory() }) {
        // Get the name of the current file
        fs::path filename = dir_entry.filename();

        // Print file that is being moved
        std::cout << "File found: " << filename << endl;

        // Create LocalImage object to be loaded
        LocalImage image(dir_entry);
        Metadata metadata = image.getMetadata();

        // Call on the sorter to check all sorting methods
        bool matches = true;
        for (SortingMethod& sortingMethod : anchor.getSorter().getMethods())
        {
            // Print the current sorting method being checked
            std::cout << "Current Sorting Method: " << sortingMethod.getName() << std::endl;
 
            //----
            //TODO - Check type from string (instead of only doing integers)
            //----

            // Initialize the variables for sorting
            const string tag = sortingMethod.getTag();
            const string name = sortingMethod.getName();
            const std::any min = sortingMethod.getMin();
            const std::any max = sortingMethod.getMax();
            const auto& val = metadata.get(tag);

            // Check if tag exists in metadata
            if (!metadata.contains(tag))
            {
                matches = false;
                std::cout << "ERROR: Metadata for '" << name << "'does not contain tag '" << tag << "'." << std::endl;
                break;
            }

            // Type-check
            bool passed;

            if (!val.has_value()) {
                std::cout << "No value for tag: " << tag << std::endl;
                matches = false;
                break;
            }   

            if (val.type() == typeid(double)) {
                passed = sort_double(std::any_cast<double>(val), std::any_cast<double>(min), std::any_cast<double>(max));
            }
            else if (val.type() == typeid(int)) {
                passed = sort_int(std::any_cast<int>(val), std::any_cast<int>(min), std::any_cast<int>(max));
            }
            else if (val.type() == typeid(float)) {
                passed = sort_float(std::any_cast<float>(val), std::any_cast<float>(min), std::any_cast<float>(max));
            }
            else if (val.type() == typeid(std::string)) {
                passed = sort_string(std::any_cast<std::string>(val), std::any_cast<std::string>(min));
            }
            else {
                std::cout << "Unsupported type for metadata tag '" << tag << "'." << std::endl;
                matches = false;
                break;
            }

            // Test the sorting function
            if (!passed)
            {
                matches = false;
                std::cout << "Failed Sorting Method Test: " << name << std::endl;
                break;
            }
        }

        // Get the sorted folder name
        fs::path output = anchor.getOutputDirectory();

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

    // Remove temporary copies

}