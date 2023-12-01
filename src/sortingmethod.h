#ifndef SORTINGMETHOD_H
#define SORTINGMETHOD_H

#include <string>
#include <functional>
#include <any>

#define DISABLED 0
#define ENABLED 1


class SortingMethod {
    private:
        std::string name;
        std::string tag;
        std::any min;
        std::any max;
        int status;

    public:
        // Constructor for the SortingMethod class
        SortingMethod();
        SortingMethod(std::string name, std::string tag, std::any min, std::any max);

        /* --- GETTERS --- */
        // Returns the name of the folder that this sotring method's metadata tag belongs to
        std::string getName();

        // Returns the metadata tag
        std::string getTag();

        // Returns the minimum bound
        std::any& getMin();

        // Returns the maximum bound
        std::any& getMax();

        // Returns an array containing the upper and lower bounds
        std::any* getBounds();

        /* Returns the status of the sorting method. 0 = disabled, 1 = enabled */
        int getStatus();

        /* --- SETTERS --- */
        // Sets the name of the sorting method (and the corresponding folder)
        void setName(std::string name);

        // Sets the metadata tag
        void setTag(std::string tag);

        // Sets the minimum bound
        void setMin(std::any min);

        // Sets the maximum bound
        void setMax(std::any max);

        // Sets the status (0 = disabled, 1 = enabled)
        void setStatus(int status);
};

#endif