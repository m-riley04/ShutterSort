#include "application.h"
#include "shuttersort.h"

//----- VALUE SORTING METHODS ------------------------------------------------------

// Sorts a target integer between 2 values
bool sort_int(int target, int minRange, int maxRange) {
    if (minRange <= target && target <= maxRange) { return true; }
    return false;
}

//--- CLASS METHODS ----------------------------------------------------------------
// Starts the main application loop
void Application::run() {

    // Test to see if main executes successfully.
    printf("ShutterSort has started successfully.\n");

    // Get image path
    std::string imgPath = "TestCases/cat.jpg";

    // Load metadata object
    Metadata myMetadata;
    myMetadata.load(imgPath);

    // Create local image
    LocalImage image(imgPath);

    // Create template sortingmethods
    SortingMethod method_1("Method 1", "Exif.Image2.Compression", 0, 9, sort_int);
    SortingMethod method_2("Method 2", "Exif.Image.Compression", 3, 7, sort_int);

    // Create sorter and populate with dummy sorting methods
    Sorter sorter;
    sorter.getMethods().push_back(method_1);
    sorter.getMethods().push_back(method_2);

    // Test Anchor
    Anchor anchor(std::string("C:/Users/vex10/Desktop/InputDirectory"), std::string("C:/Users/vex10/Desktop/OutputDirectory"), sorter);

    // CLI Debug
    std::cout << "0. Exit\n1. Update Anchor\n2. Print test metadata";
    std::string userInput;
    while (userInput != "0") {
        std::cin >> userInput;
        switch (stoi(userInput)) {
            case 1:
                anchor.update();
                break;
            case 2:
                // Create test local image and print it
                image.getMetadata().printAll();
                break;
            default:
                std::cout << "Please choose from the menu options above." << std::endl;
                break;
        }
    }

    // Wait to close program
    std::cin.ignore();
}