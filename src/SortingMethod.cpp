#include "SortingMethod.h"
#include <string>
#include <functional>

// Default constructor
SortingMethod::SortingMethod()
    : name(""), tag(""), min(0), max(0), status(DISABLED) {
}

// Parameterized constructor
SortingMethod::SortingMethod(std::string name, std::string tag, int min, int max, std::function<bool(int, int, int)> method)
    : name(name), tag(tag), min(min), max(max), status(DISABLED), method(method) {
}

/* --- GETTERS --- */
std::string SortingMethod::getName() {
    return this->name;
}

std::string SortingMethod::getTag() {
    return this->tag;
}

int SortingMethod::getMin() {
    return this->min;
}

int SortingMethod::getMax() {
    return this->max;
}

int* SortingMethod::getBounds() {
    static int bounds[2] = {this->min, this->max};
    return bounds;
}

int SortingMethod::getStatus() {
    return this->status;
}

std::function<bool(int, int, int)>& SortingMethod::getMethod() {
    return this->method;
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

void SortingMethod::setMethod(std::function<bool(int, int, int)> method) {
    this->method = method;
}