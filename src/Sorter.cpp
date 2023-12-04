#include "Sorter.h"
#include <exiv2/exiv2.hpp>
#include <iostream>

// Returns the std::list of sorting methods
std::list<SortingMethod>& Sorter::getMethods() {
    return this->methods;
}

void Sorter::printMethods() {
    std::cout << "-- Methods --" << std::endl;
    int counter = 0;
    for (auto & i : methods) {
        try {
            std::string min = std::any_cast<std::string>(i.getMin());
            std::string max = std::any_cast<std::string>(i.getMax());
            std::cout << ++counter << ") Name: " << i.getName() << "; Tag: " << i.getTag() << "; Min: " << min << "; Max: " << max << "; Status: " << i.getStatus() << std::endl;

        } catch (int e) {
            std::cout << "Unable to print method " << i.getName() << " with current min/max values (unable to convert type to std::string)" << std::endl;
        }
    }
}
