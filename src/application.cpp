#include "application.h"
#include "localimage.h"
#include "metadata.h"
#include "sortingfunctions.h"
#include <QDebug>

//----- CLASS METHODS ----------------------------------------------------------------
Application::Application() {}

std::list<Anchor>& Application::getAnchors() {
    return anchors;
}

SortTimer& Application::getTimer() {
    return timer;
}

void Application::setTimer(std::chrono::milliseconds interval, std::function<void(Anchor)> func, Anchor anchor) {
    this->timer.setInterval(interval);
    this->timer.setFunction(func);
    this->timer.setAnchor(anchor);
}

void Application::addAnchor(std::string directoryPath, std::string outputDirectoryPath, Sorter& sorter) {

}

void Application::removeAnchor(int index) {

}
void Application::removeAnchor(const Anchor& anchor) {

}

void Application::printAnchors() {
    int counter = 0;
    for (Anchor& anchor : this->anchors) {
        qDebug() << ++counter << ") Anchor #" << anchor.getID();
    }
}

//----- DEBUG METHODS ----------------------------------------------------------------
// Starts the main CLI application loop
void Application::run_cli() {
/*
    // Test to see if main executes successfully.
    printf("ShutterSort has started successfully.\n");

    // Populate the anchor list with at least 1 anchor
    this->_debug_populate();

    // Check if anchor list is empty
    if (this->anchors.empty()) {
        std::cout << "ERROR: Main Anchor list is empty. Please populate the Anchor list before calling again." << std::endl;
        return;
    }

    // Set anchor value
    Anchor & anchor = this->anchors.front();

    // Initialize timer
    SortTimer timer(std::chrono::milliseconds(1000), update_anchor, anchor);

    //----- CLI Debug----------------------------------------------------------------------------------------------------------------
    std::cout << "0. Exit\n1. Manually Update Anchor\n2. Start Auto-Sort\n3. Stop Auto-Sort\n4. Print test metadata\n5. Set new Anchor path\n6. Set new Anchor output path" << std::endl;
    std::string userInput;
    
    // Main command loop
    while (userInput != "0") {
        std::cout << ">> ";
        std::cin >> userInput;

        try {
            stoi(std::string(userInput));
        }
        catch (const std::invalid_argument &ex) {
            std::cout << "ERROR: Please type a valid integer from the list of commands." << std::endl;
            continue;
        }

        switch (stoi(userInput)) {
            case 0:
                // Stop the timer before the thread is closed
                timer.stop();
                break;
            case 1:
                printf("Manual update initiated.\n");
                update_anchor(anchor);
                break;
            case 2:
                printf("Started auto-sorting...\n");
                timer.start();
                break;
            case 3:
                printf("Stopped auto-sorting.\n");
                timer.stop();
                break;
            case 4:
            {
                // Get image path
                std::string imgPath = "TestCases/cat.jpg";

                // Load metadata object
                Metadata myMetadata;
                myMetadata.load(imgPath);

                // Create local image
                LocalImage image(imgPath);

                // Print all metadata from local image
                image.getMetadata().printAll();
            }
                break;
            case 5:
            {
                std::cout << "(Press 0 to cancel operation)" << std::endl;
                std::string path;
                while (path != "0") {
                    std::cout << "Please give a valid Anchor path:\n>> ";
                    std::cin >> path;
                    std::cout << std::endl;

                    // Test the path
                    if (!std::filesystem::exists(std::filesystem::path(path))) {
                        std::cout << "ERROR: Invalid path '" << path << "'. Please try again." << std::endl;
                    }
                    else {
                        // Set the Anchor path
                        anchor.setDirectory(std::filesystem::path(path));
                        std::cout << "New Anchor path '" << path << "' for Anchor #" << anchor.getID() << "." << std::endl;
                    }
                }
                
            }
                break;

            case 6:
            {
                std::cout << "(Press 0 to cancel operation)" << std::endl;
                std::string path;
                while (path != "0") {
                    std::cout << "Please give a valid output path:\n>> ";
                    std::cin >> path;
                    std::cout << std::endl;

                    // Test the path
                    if (!std::filesystem::exists(std::filesystem::path(path))) {
                        std::cout << "ERROR: Invalid path '" << path << "'. Please try again." << std::endl;
                    }
                    else {
                        // Set the Anchor path
                        anchor.setOutputDirectory(std::filesystem::path(path));
                        std::cout << "New output path '" << path << "' for Anchor #" << anchor.getID() << "." << std::endl;
                    }
                }

            }
            break;
            default:
                std::cout << "Please choose from the menu options above." << std::endl;
                break;
        }
    }
*/
}

// Populates the application with a test anchor with test sorting methods
void Application::_debug_populate() {
    // Create template sortingmethods
    SortingMethod method_1("Method 1", "Exif.Image2.Compression", std::any(double(0)), std::any(double(9)));
    SortingMethod method_2("Method 2", "Exif.Image.Compression", std::any(double(3)), std::any(double(7)));

    // Create sorter and populate with dummy sorting methods
    Sorter sorter;
    sorter.getMethods().push_back(method_1);
    sorter.getMethods().push_back(method_2);

    // Test Anchor
    Anchor anchor;
    try {
        std::string anchorDir       = "C:/Users/vex10/Desktop/InputDirectory";
        std::string anchorOutput    = "C:/Users/vex10/Desktop/OutputDirectory";
        anchor.setDirectory(anchorDir);
        anchor.setOutputDirectory(anchorOutput);
        anchor.setSorter(sorter);
    }
    catch (int e) {
        std::cout << "ERROR: An exception has occurred when reading in the test Anchor #" << anchor.getID() << ". Exception #: " << e << std::endl;
        std::cout << "-- Failed to populate application with test anchor --" << std::endl;
        return;
    }

    // If the anchor is fine, push it to the main anchor list
    this->anchors.push_front(anchor);
}
