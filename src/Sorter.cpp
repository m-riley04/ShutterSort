#include "Sorter.h"
#include <exiv2/exiv2.hpp>


// Sorts files other than images to a miscellaneous directory
void Sorter::sortToMisc(const std::string& origionalDirectory, const std::string& miscDirectory) {

    for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(origionalDirectory)){ // A "for each" loop that iterates through each entry

        if (entry.is_regular_file()){  // <filesystem> function that checks if the file status is normal

            std::string file = entry.path().filename().string(); // gets the name of the file
            std::string extension = entry.path().extension().string(); // get the extension of the file 
            
            if (extension != ".jpg" && extension != ".png" && extension != ".bmp"){ // checks that the file is a photo
                std::filesystem::rename(entry.path(), miscDirectory + "/" + file); // moves the file that is not a photo to a different directory
                std::cout << "Moved the non-images: " << file << std::endl;
            }
        }
    }
}

void Sorter::makeTempCopy(const std::string& sourcePath, const std::string& destPath){
    std::filesystem::path sourceDir(sourcePath);
    std::filesystem::path destDir(destPath);

    try {
        
        //Check if the directory exists
        if (std::filesystem::exists(sourceDir) && std::filesystem::is_directory(sourceDir)) {

            std::filesystem::create_directory(destDir); //Create destination directory if it doesn't exist

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
                }
            }

            std::cout << "All files copied successfully." << std::endl;

        } else {
            std::cerr << "Source directory doesn't exist or is not a directory." << std::endl;
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}

void Sorter::deleteTempCopy(const std::string& destPath){
    std::filesystem::path tempDir(destPath);
     for (const auto& entry : std::filesystem::directory_iterator(tempDir)) {
        try {
        std::filesystem::remove_all(tempDir); // Deletes the directory and its contents
        } 
        catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error deleting directory: " << e.what() << std::endl;
        }

     }
}
/*
bool Sorter::sort(const std::string& filename, int minRange, int maxRange) {
    try {
        // Open the image file and read metadata
        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
        if (image.get() == 0) {
            std::cerr << "Error opening image file: " << filename << std::endl;
            return false;
        }

        image->readMetadata();

        // Get the metadata
        Exiv2::ExifData &exifData = image->exifData();
        
        // Check if the integer is in the specified range
        if (exifData.empty()) {
            std::cerr << "No metadata found in the image: " << filename << std::endl;
            return false;
        } else {
            Exiv2::ExifData::const_iterator it = exifData.begin();
            Exiv2::ExifData::const_iterator end = exifData.end();

            for (; it != end; ++it) {
                try {
                    int value = it->toLong();
                    if (value >= minRange && value <= maxRange) {
                        std::cout << "Found an integer in the range [" << minRange << ", " << maxRange << "] in metadata of " << filename << std::endl;
                        return true;
                    }
                } catch (Exiv2::BasicError<char>& e) {
                    // Handle non-integer values if necessary
                }
            }
        }
    } catch (Exiv2::AnyError& e) {
        std::cerr << "Caught Exiv2 exception: " << e.what() << std::endl;
        return false;
    }

    std::cout << "Did not find an integer in the range [" << minRange << ", " << maxRange << "] in metadata of " << filename << std::endl;
    return false;
}


bool Sorter::sort(const std::string& filename, const std::string& searchString){
    try {
        // -- Open the image file and read metadata -- 
        Exiv2::Image::AutoPtr image = Exiv2::ImageFactory::open(filename);
        if (image.get() == 0) {
            std::cerr << "Error opening image file: " << filename << std::endl;
            return false;
        }

        image->readMetadata();

        // -- Get the metadata -- 
        Exiv2::ExifData &exifData = image->exifData();
        
        // -- Check if the searchString is in the metadata -- 
        if (exifData.empty()) {
            std::cerr << "No metadata found in the image: " << filename << std::endl;
            return false;
        } else {
            Exiv2::ExifData::const_iterator it = exifData.begin();
            Exiv2::ExifData::const_iterator end = exifData.end();

            for (; it != end; ++it) {
                std::string value = it->toString();
                if (value.find(searchString) != std::string::npos) {
                    std::cout << "Found '" << searchString << "' in metadata of " << filename << std::endl;
                    return true;
                }
            }
        }
    } catch (Exiv2::AnyError& e) {
        std::cerr << "Caught Exiv2 exception: " << e.what() << std::endl;
        return false;
    }

    std::cout << "Did not find '" << searchString << "' in metadata of " << filename << std::endl;
    return false;
}
*/
/*
int main(){
    std::string origionalDirectory; //This is the directory that contains all files 
    std::string miscDirectory; // Directory to put miscellaneous files 

    Sorter sorter;
    sorter.sortToMisc(origionalDirectory, miscDirectory);

    return 0;
}
*/