#include <iostream>
#include <fstream> 
#include <string> 
#include <filesystem> 


void sortToMisc(const std::string& origionalDirectory, const std::string& miscDirectory){

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

int main(){
    std::string origionalDirectory = "path"; //This is the directory that contains all files 
    std::string miscDirectory = "path"; // Directory to put miscellaneous files 

    sortToMisc(origionalDirectory, miscDirectory);

    return 0;
}