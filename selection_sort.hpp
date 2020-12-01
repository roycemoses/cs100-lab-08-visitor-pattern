#ifndef __SELECTION_SORT_HPP__
#define __SELECTION_SORT_HPP__

#include "sort.hpp"

class SelectionSort : public Sort {
    public:
        /* Constructors */
        SelectionSort() : Sort() { };

        /* Pure Virtual Functions */
        virtual void sort(Container* container);
};

#endif //__SELECTION_SORT_HPP__
