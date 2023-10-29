#include <iostream>
#include <filesystem>
#include <thread>
#include <Windows.h>
#include <cstring>

using namespace std;
namespace fs = filesystem;

/* Checks for any new files in the input folder. If there are files, moves them to the output folder. Checks after a certain time interval passes.*/
void updateDirectory(const fs::path input, const fs::path output, const int milliseconds)
{
    while (1)
    {
        // Check if the directory is empty. If it is, do nothing.
        bool empty = fs::is_empty(input);
        if (empty)
        {
            Sleep(milliseconds);
            continue;
        }

        /* Move all non-image entries to the miscellaneous directory (Colin's function)*/
        //foo(bar)

        // Loop through every file in the input directory with a directory_iterator
        for (fs::path const &dir_entry : std::filesystem::directory_iterator{input}) {
            fs::path newOutput = output;
            fs::path name = dir_entry.filename();
            
            // Concat file name to output path
            newOutput /= name;

            // Print moving file
            cout << "File found: " << name << endl;

            /*  This is where the sorting part will take place. */
            // Create LocalImage object 
            //Exiv2::Image exivImage = Exiv2::ImageFactory(dir_entry);
            //LocalImage image(dir_entry, exivImage)

            // Move file to the output directory
            fs::rename(dir_entry, newOutput);
        }

        // Tell the user it is finished updating
        cout << "Updated directory." << input.string() << endl;
        Sleep(milliseconds);
    }
}

int main()
{
    // Set your input folder path
    const fs::path inputDirectory{"C:\\Users\\vex10\\Desktop\\TestingDirectory"};

    // Set your output folder path
    const fs::path outputDirectory{"C:\\Users\\vex10\\Desktop\\OutputDirectory"};

    // Initialize thread
    thread sortingThread(updateDirectory, inputDirectory, outputDirectory, 1000);

    // Sorting status
    bool isRunning = true;

    // Get user input to control sorting
    int userInput = 0;
    while (userInput != 2)
    {
        cout << "1) Start/Stop Sorting\n2) Quit" << endl << ">> ";
        cin >> userInput;

        if (userInput == 1 && !isRunning)
        {
            //thread sortingThread(updateDirectory, inputDirectory, outputDirectory, 1000);
            cout << "Sorting has been started." << endl;
            isRunning = true;
        }
        else if (userInput == 1 && isRunning)
        {
            //sortingThread.detach();
            cout << "Sorting has been stopped." << endl;
            isRunning = false;
        }
    }

    // Detach sorting thread
    sortingThread.detach();

    // Wait before immedietly closing program
    cout << "Thank you for sorting!" << endl;
    std::cin.ignore();
    
    return 0;
}