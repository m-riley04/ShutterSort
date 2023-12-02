#include "application.h"
#include "shuttersort.h"
#include "sorttimer.h"

//--- CLASS METHODS ----------------------------------------------------------------
// Starts the main application loop
void Application::run() {

    // Test to see if main executes successfully.
    printf("ShutterSort has started successfully.\n");

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
        std::string anchorDir       = "C:/Users/riley/Desktop/InputDirectory";
        std::string anchorOutput    = "C:/Users/riley/Desktop/OutputDirectory";
        anchor.setDirectory(anchorDir);
        anchor.setOutputDirectory(anchorOutput);
        anchor.setSorter(sorter);
    }
    catch (int e) {
        std::cout << "ERROR: An exception has occurred when reading in the test Anchor #" << anchor.getID() << ".Exception #: " << e << std::endl;
        return;
    }

    // Initialize timer
    SortTimer timer(std::chrono::milliseconds(1000), update, anchor);

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
                update(anchor);
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
}