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

    // CLI Debug
    std::cout << "0. Exit\n1. Manually Update Anchor\n2. Start Auto-Sort\n3. Stop Auto-Sort\n4. Print test metadata" << std::endl;
    std::string userInput;
    while (userInput != "0") {
        std::cout << ">> ";
        std::cin >> userInput;
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
            default:
                std::cout << "Please choose from the menu options above." << std::endl;
                break;
        }
    }
}