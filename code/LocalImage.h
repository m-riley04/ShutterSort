#ifndef LOCALIMAGE
#define LOCALIMAGE

#include <string>
class LocalImage {
    private:
        std::string path;
        std::string tag;

    public:
        std::string getPath(){};
        std::string getTag(){};
};

#endif