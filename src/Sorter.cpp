#include "Sorter.h"
#include <exiv2/exiv2.hpp>
#include <iostream>

Sorter::Sorter() {}

Sorter::~Sorter() {}

// Returns the std::list of sorting methods
std::list<SortingMethod>& Sorter::getMethods() {
    return this->methods;
}

void Sorter::printMethods() {
    std::cout << "-- Methods --" << std::endl;
    int counter = 0;
    for (auto & i : methods) {
        try {
            double min = std::any_cast<double>(i.getMin());
            double max = std::any_cast<double>(i.getMax());
            std::cout << ++counter << ") Name: " << i.getName() << "; Tag: " << i.getTag() << "; Min: " << min << "; Max: " << max << "; Status: " << i.getStatus() << std::endl;

        } catch (int e) {
            std::cout << "Unable to print method " << i.getName() << " with current min/max values (unable to cast to double)" << std::endl;
        }
    }
}

void Sorter::setMethodsList(std::list<SortingMethod>& methods) {
    this->methods = methods;
}
