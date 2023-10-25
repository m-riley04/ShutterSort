#ifndef LOCALIMAGE
#define LOCALIMAGE

#include <filesystem>
#include <cstring>
class LocalImage {
    private:
        std::filesystem::path path;
        std::string tag;

    public:
        std::string getPath(){};
        std::string getTag(){};
};

#endif