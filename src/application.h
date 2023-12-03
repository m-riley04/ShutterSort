#ifndef APPLICATION_H
#define APPLICATION_H

#include <string>
#include "anchor.h"
#include <list>
#include "sorttimer.h"

class Application
{
private:
    std::list<Anchor> anchors;
    SortTimer timer;

public:
    Application();

    // Returns the list of Anchors created for the program
    std::list<Anchor>& getAnchors();

    // Returns the sort timer object
    SortTimer& getTimer();

    // Sets the timer object
    void setTimer(std::chrono::milliseconds interval, std::function<void(Anchor)> func, Anchor anchor);

    // Adds an anchor point to the list of anchors
    void addAnchor(std::string directoryPath, std::string outputDirectoryPath, Sorter& sorter);

    // Removes an anchor point from the list of anchors
    void removeAnchor(int index);
    void removeAnchor(const Anchor& anchor);

    // Prints a list of all currently-established Anchor points
    void printAnchors();

    //----- DEBUGGING/TESTING METHODS ---------------
    // Starts a CLI version of ShutterSort with barebones functionalities and pre-generated sorting methods
    void run_cli();

    // Populates the application with a test anchor with test sorting methods
    void _debug_populate();

};
bool sort_int(int target, int minRange, int maxRange);
bool sort_double(double target, double minRange, double maxRange);
bool sort_string(std::string target, std::string str);

#endif
