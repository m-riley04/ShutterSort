#include "Sorter.h"
#include <exiv2/exiv2.hpp>


// Sorts files other than images to a miscellaneous directory
void Sorter::sortToMisc(const std::string& originalDirectory, const std::string& miscDirectory) {
    int filesMoved = 0; // Counter for the number of files moved

    for (std::filesystem::directory_entry entry : std::filesystem::directory_iterator(originalDirectory)) {
        if (entry.is_regular_file()) {
            std::string file = entry.path().filename().string();
            std::string extension = entry.path().extension().string();

            if (extension != ".jpg" && extension != ".png" && extension != ".bmp") {
                std::filesystem::rename(entry.path(), miscDirectory + "/" + file);
                std::cout << "Moved the non-images: " << file << std::endl;
                filesMoved++;
            }
        }
    }

    if (filesMoved == 0) {
        std::cout << "No files were moved." << std::endl;
    }
}

void Sorter::makeTempCopy(const std::string& sourcePath, const std::string& destPath){
    std::filesystem::path sourceDir(sourcePath);
    std::filesystem::path destDir(destPath);

    try {
        
        //Check if the directory exists
        if (std::filesystem::exists(sourceDir) && std::filesystem::is_directory(sourceDir)) {

            std::filesystem::create_directory(destDir); //Create destination directory if it doesn't exist

            int filesCopied = 0;
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

            if(filesCopied != 0)
                std::cout << "All files copied successfully." << std::endl;
            else
                std::cout << "No files copied" << std::endl;

        } else {
            std::cerr << "Source directory doesn't exist or is not a directory." << std::endl;
        }
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
}

void Sorter::deleteTempCopy(const std::string& destPath){
    std::filesystem::path tempDir(destPath);
        try {
        std::filesystem::remove_all(tempDir); // Deletes the directory and its contents
        } 
        catch (const std::filesystem::filesystem_error& e) {
        std::cerr << "Error deleting directory: " << e.what() << std::endl;
        }
}

void Sorter::sort(Metadata data, int minRange, int maxRange, const std::string & key){
    if (data.get() == "") {
        std::cerr << "Error opening image file: " << filename << std::endl;
        return false;
    }
       
    if (data.contains(key)==false) {
        std::cerr << "No metadata found in the image: " << filename << std::endl;
        return false;

    } else {
        meta = data.load();
        if (meta.get(key) >= minRange && meta.get(key) <= maxRange){
            //put the file into the sorted directory 
        }
    }
}

void Sorter::sort(Metadata data, float minRange, float maxRange, const std::string & key){
    if (data.get() == "") {
        std::cerr << "Error opening image file: " << filename << std::endl;
        return false;
    }
       
    if (data.contains(key)==false) {
        std::cerr << "No metadata found in the image: " << filename << std::endl;
        return false;

    } else {
        meta = data.load();
        if (meta.get(key) >= minRange && meta.get(key) <= maxRange){
            //put the file into the sorted directory 
        }
    }
}



void Sorter::sort(Metadata data, const std::string& str, const std::string & key){
    if (data.get() == "") {
        std::cerr << "Error opening image file: " << filename << std::endl;
        return false;
    }
       
    if (data.contains(key)==false) {
        std::cerr << "No metadata found in the image: " << filename << std::endl;
        return false;

    } else {
        meta = data.load();
        if (meta.get(key) == str){
            //put the file into the sorted directory 
        }
    }
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
