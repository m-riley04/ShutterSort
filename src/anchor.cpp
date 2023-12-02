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
Anchor::Anchor(std::string directory, std::string outputDirectory, Sorter& sorter) {
    this->directory         = std::filesystem::path(directory);
    this->outputDirectory   = std::filesystem::path(outputDirectory);
    this->sorter            = sorter;
}
Anchor::Anchor(std::filesystem::path directory, std::filesystem::path outputDirectory, Sorter& sorter) {
    this->directory         = directory;
    this->outputDirectory   = outputDirectory;
    this->sorter            = sorter;
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


//----- MISCELANEOUS FILE SORTING --------------------------------------------------
// Sort a given path's contents to an output file's directory based on if they are not an image filetype
void sortToMisc(const std::string& originalDirectory, const std::string& outputDirectory) {
    int filesMoved                  = 0; // Counter for the number of files moved
    std::string imageExtensions[12]  = { ".jpg", ".jpeg", ".JPG", ".JPEG", ".gif", ".bmp", ".ico", ".png", ".ps", ".svg", ".tif", ".tiff" }; // Currently supported file extensions

    // Loop through directory's contents 1 by 1
    for (fs::directory_entry entry : fs::directory_iterator(originalDirectory)) {
        if (entry.is_regular_file()) {
            std::string file        = entry.path().filename().string();
            std::string extension   = entry.path().extension().string();

            // Create imageExtensions iterator
            auto it = std::find(std::begin(imageExtensions), std::end(imageExtensions), extension);
            
            // If the iterator reached the end, then the extension is not within imageExtensions
            if (it == std::end(imageExtensions)) {
                if (!fs::exists(fs::path(outputDirectory) /= "Miscellaneous"))
                {
                    fs::create_directory(fs::path(outputDirectory) /= "Miscellaneous");
                }
                fs::rename(entry.path(), outputDirectory + "/Miscellaneous/" + file);
                std::cout << "Moved the non-images: " << file << std::endl;
                filesMoved++;
            }
        }
    }

    // Print results
    if (filesMoved == 0) {
        std::cout << "No files were moved to miscellaneous." << std::endl;
    }
    else {
        std::cout << filesMoved << " files moved to miscellaneous." << std::endl;
    }
}

void makeTempCopy(const std::string& sourcePath, const std::string& destPath) {
    std::filesystem::path sourceDir(sourcePath);
    std::filesystem::path destDir(destPath);

    try {

        //Check if the directory exists
        if (std::filesystem::exists(sourceDir) && std::filesystem::is_directory(sourceDir)) {

            std::filesystem::create_directory(destDir); //Create destination directory if it doesn't exist

            int filesCopied     = 0;
            //Iterate through the files in the source directory
            for (const auto& entry : std::filesystem::directory_iterator(sourceDir)) {

                if (std::filesystem::is_regular_file(entry)) {
                    //get the files name 
                    std::filesystem::path sourceFile = entry.path();
                    //append the files name to the destination directory
                    std::filesystem::path destFile = destDir / sourceFile.filename();

                    //copy file to the destination directory
                    std::filesystem::copy_file(sourceFile, destFile, std::filesystem::copy_options::overwrite_existing);

                    std::cout << "Copied: " << sourceFile << " to " << destFile << std::endl;
                    filesCopied++;
                }
            }

            if (filesCopied != 0)
                std::cout << "All files copied successfully." << std::endl;
            else
                std::cout << "No files copied" << std::endl;

        }
        else {
            std::cerr << "Source directory doesn't exist or is not a directory." << std::endl;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}

void deleteTempCopy(const std::string& destPath) {
    fs::path tempDir(destPath);
    try {
        fs::remove_all(tempDir); // Deletes the directory and its contents
    }
    catch (const fs::filesystem_error& e) {
        std::cerr << "Error deleting directory: " << e.what() << std::endl;
    }
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
    for (fs::path const &dir_entry : fs::directory_iterator(anchorDirectory)) {

        // Check if the current entry is a folder
        if (fs::is_directory(dir_entry))
        {
            // Sort all within subfolder with recursion
            Anchor subanchor(anchorDirectory /= dir_entry.filename(), anchorOutputDirectory, anchorSorter);
            update(subanchor);
            
            // subfolder output folder
            anchorOutputDirectory /= "Empty Folders";

            // Check if folder for empty folders exists
            if (!fs::exists(anchorOutputDirectory)) {
                fs::create_directory(anchorOutputDirectory);
            }
            
            // Move subfolder
            fs::rename(anchorDirectory,  anchorOutputDirectory /= dir_entry.filename());
            continue;
        }

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