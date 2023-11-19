// Include all main classes for clarity (Will be modified/removed later)
#include "localimage.h"
#include "sorter.h"
#include "sortingmethod.h"
#include "anchor.h"
#include "metadata.h"

#include <exiv2/exiv2.hpp>
#include <iostream>
#include <regex>

int main(){
    // Test to see if main executes successfully.
    printf("Hello, world!\n");

    // Get image path
    std::string imgPath = "TestCases/cat.jpg";

    // Load metadata object
    Metadata myMetadata;
    myMetadata.load(imgPath);
    
    LocalImage image(imgPath);
    image.getMetadata().printAll();

    // Wait to close program
    std::cin.ignore();

    return 0;
}

