#ifndef SORTINGMETHOD_H
#define SORTINGMETHOD_H

#include <string>
#include <functional>

#define DISABLED 0
#define ENABLED 1

class SortingMethod {
    private:
        std::string name;
        std::string tag;
        int min;
        int max;
        int status;
        std::function<bool()> method;

    public:
        // Constructor for the SortingMethod class
        SortingMethod();
        SortingMethod(std::string name, std::string tag, int min, int max, std::function<bool()> method);

        /* --- GETTERS --- */
        // Returns the name of the folder that this sotring method's metadata tag belongs to
        std::string getName();

        // Returns the metadata tag
        std::string getTag();

        // Returns the minimum bound
        int getMin();

        // Returns the maximum bound
        int getMax();

        // Returns an array containing the upper and lower bounds
        int *getBounds();

        /* Returns the status of the sorting method. 0 = disabled, 1 = enabled */
        int getStatus();

        // Returns the sorting function
        std::function<bool()> getMethod();

        /* --- SETTERS --- */
        // Sets the name of the sorting method (and the corresponding folder)
        void setName(std::string name);

        // Sets the metadata tag
        void setTag(std::string tag);

        // Sets the minimum bound
        void setMin(int min);

        // Sets the maximum bound
        void setMax(int max);

        // Sets the status (0 = disabled, 1 = enabled)
        void setStatus(int status);

        // Sets the sorting function
        void setMethod(std::function<bool()> method);
};

#endif