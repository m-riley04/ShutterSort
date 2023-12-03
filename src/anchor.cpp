#include "anchor.h"
#include "sorter.h"
#include <string>


using namespace std;
namespace fs = filesystem;

int Anchor::idCounter = 0;

// Constructor
Anchor::Anchor() { id = ++idCounter; }
Anchor::Anchor(std::string directory, std::string outputDirectory, Sorter& sorter) {
    this->directory         = std::filesystem::path(directory);
    this->outputDirectory   = std::filesystem::path(outputDirectory);
    this->sorter            = sorter;
    this->id                = ++idCounter;
}
Anchor::Anchor(std::filesystem::path directory, std::filesystem::path outputDirectory, Sorter& sorter) {
    this->directory         = directory;
    this->outputDirectory   = outputDirectory;
    this->sorter            = sorter;
    this->id                = ++idCounter;
}

std::filesystem::path Anchor::getDirectory() {
    return directory;
}

std::filesystem::path Anchor::getOutputDirectory() {
    return outputDirectory;
}

Sorter& Anchor::getSorter() {
    return sorter;
}

int Anchor::getID() {
    return this->id;
}

void Anchor::setDirectory(std::string path) {
    this->directory         = std::filesystem::path(path);
}

void Anchor::setDirectory(std::filesystem::path path) {
    this->directory         = path;
}

void Anchor::setOutputDirectory(std::string path) {
    this->outputDirectory = std::filesystem::path(path);
}

void Anchor::setOutputDirectory(std::filesystem::path path) {
    this->outputDirectory = path;
}

void Anchor::setSorter(Sorter& sorter) {
    this->sorter = sorter;
}
