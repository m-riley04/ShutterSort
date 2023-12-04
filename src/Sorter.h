#ifndef SORTER_H
#define SORTER_H

#include <list>
#include "sortingmethod.h"

class Sorter {
    private:
        // List/stack of sorting methods
        std::list<SortingMethod> methods;

    public:

        /* --- GETTERS --- */
        std::list<SortingMethod>& getMethods();

};

#endif
