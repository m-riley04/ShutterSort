#ifndef SORTER_H
#define SORTER_H

#include <list>
#include "sortingmethod.h"

class Sorter {
    private:
        // List/stack of sorting methods
        std::list<SortingMethod> methods;

    public:
        void printMethods();

        /* --- GETTERS --- */
        std::list<SortingMethod>& getMethods();

};

#endif
