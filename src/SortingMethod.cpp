// #include <string>
// #include "SortingMethod.h"

// SortingMethod::SortingMethod() {}

// SortingMethod::SortingMethod(std::string &name, std::string &tag, int min, int max) {

// }
#include "SortingMethod.h"
#include <string>

// Default constructor
SortingMethod::SortingMethod()
    : name(""), tag(""), min(0), max(0), status(DISABLED) {
}

// Parameterized constructor
SortingMethod::SortingMethod(std::string &name, std::string &tag, int min, int max)
    : name(name), tag(tag), min(min), max(max), status(DISABLED) {
}

/* --- GETTERS --- */
std::string SortingMethod::getName() {
    return name;
}

std::string SortingMethod::getTag() {
    return tag;
}

int SortingMethod::getMin() {
    return min;
}

int SortingMethod::getMax() {
    return max;
}

int *SortingMethod::getBounds() {
    static int bounds[2];
    bounds[0] = min;
    bounds[1] = max;
    return bounds;
}

int SortingMethod::getStatus() {
    return status;
}

/* --- SETTERS --- */
void SortingMethod::setName(std::string name) {
    this->name = name;
}

void SortingMethod::setTag(std::string tag) {
    this->tag = tag;
}

void SortingMethod::setMin(int min) {
    this->min = min;
}

void SortingMethod::setMax(int max) {
    this->max = max;
}

void SortingMethod::setStatus(int status) {
    this->status = status;
}
