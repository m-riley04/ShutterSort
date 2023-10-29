#ifndef SORTINGMETHOD_H
#define SORTINGMETHOD_H

#include <string>

#define DISABLED 0;
#define ENABLED 1;

class SortingMethod {
    private:
        std::string tag;
        int minValue;
        int maxValue;

        int status = DISABLED;

    public:
        /* Default constructor */
        SortingMethod();

        /* Parameterized constructor */
        SortingMethod(std::string &tag);

        /* Returns the SortingMethod's tag/name */
        std::string getTag();
};

#endif