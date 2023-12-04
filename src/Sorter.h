#ifndef SORTER_H
#define SORTER_H

#include <list>
#include "sortingmethod.h"

class Sorter {
    private:
        // List/stack of sorting methods
        std::list<SortingMethod> methods;

    public:
        Sorter();
        ~Sorter();
        void printMethods();

        /* --- GETTERS --- */
        std::list<SortingMethod>& getMethods();

        /* --- SETTERS --- */
        void setMethodsList(std::list<SortingMethod>& methods);

};

#endif
