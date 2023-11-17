#include <thread>
#include <iostream>
#include "anchor.h"
#include "localimage.h"
//#include "sorter.h"

using namespace std;
namespace fs = filesystem;

Anchor::Anchor() {

}

// Iterates through the anchor directory, checks for any changes, and calls on the sorter to sort if there are.
void Anchor::update()
{
    // Check if the directory is empty. If it is, do nothing.
    if (fs::is_empty(directory))
    {
        return;
    }

    /* Move all non-image entries to the miscellaneous directory (Colin's function)*/
    //foo(bar)

    // Loop through every file in the input directory with a directory_iterator
    for (fs::path const &dir_entry : std::filesystem::directory_iterator{directory}) {
        // Get the name of the current file
        fs::path name = dir_entry.filename();

        // Print file that is being moved
        std::cout << "File found: " << name << endl;

        // Create LocalImage object 
        LocalImage image(dir_entry);

        // Call on the sorter to check all sorting methods
        //this->sorter;

        // Get the sorted folder name
        //fs::path output = output;

        // Concat file name to sorted folder
        //outputFolder /= name;

        // Concat sorted folder to main output folder
        //newOutput /= output;

        // Move file to the main output folder
        //fs::rename(dir_entry, newOutput);
    }

    // Tell the user it is finished updating
    //cout << "Updated directory." << input.string() << endl;
}

/*// Iterates through a given input and output directory and calls on the sorter to sort. 
void Anchor::update(const fs::path input, const fs::path output)
{
    // Check if the directory is empty. If it is, do nothing.
    if (fs::is_empty(input))
    {
        break;
    }

    //--- Move all non-image entries to the miscellaneous directory (Colin's function)
    //foo(bar)

    // Loop through every file in the input directory with a directory_iterator
    for (fs::path const &dir_entry : std::filesystem::directory_iterator{input}) {
        fs::path newOutput = output;
        fs::path name = dir_entry.filename();
        
        // Concat file name to output path
        newOutput /= name;

        // Print moving file
        cout << "File found: " << name << endl;

        //--- This is where the sorting part will take place. 
        // Create LocalImage object 
        //Exiv2::Image exivImage = Exiv2::ImageFactory(dir_entry);
        //LocalImage image(dir_entry, exivImage)

        // Move file to the output directory
        fs::rename(dir_entry, newOutput);
    }

    // Tell the user it is finished updating
    cout << "Updated directory." << input.string() << endl;
}
*/