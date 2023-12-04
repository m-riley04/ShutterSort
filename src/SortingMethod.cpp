#include "SortingMethod.h"
#include <string>
#include <functional>

//----- CLASS METHODS ------------------------------------------------------
// Default constructor
SortingMethod::SortingMethod()
    : name("Sorting Method"), tag("Exif.Image.Brightness"), min(std::any(double(0))), max(std::any(double(1))), status(ENABLED) {
}

// Parameterized constructor
SortingMethod::SortingMethod(std::string name, std::string tag, std::any min, std::any max)
    : name(name), tag(tag), min(min), max(max), status(ENABLED) {
}

/* --- GETTERS --- */
std::string SortingMethod::getName() {
    return this->name;
}

std::string SortingMethod::getTag() {
    return this->tag;
}

std::any& SortingMethod::getMin() {
    return this->min;
}

std::any& SortingMethod::getMax() {
    return this->max;
}

std::any* SortingMethod::getBounds() {
    static std::any bounds[2] = {this->min, this->max};
    return bounds;
}

int SortingMethod::getStatus() {
    return this->status;
}

/* --- SETTERS --- */
void SortingMethod::setName(std::string name) {
    this->name = name;
}

void SortingMethod::setTag(std::string tag) {
    this->tag = tag;
}

void SortingMethod::setMin(std::any min) {
    this->min = min;
}

void SortingMethod::setMax(std::any max) {
    this->max = max;
}

void SortingMethod::setStatus(int status) {
    this->status = status;
}
