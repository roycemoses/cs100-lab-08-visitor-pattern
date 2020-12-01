#ifndef __BUBBLE_SORT_HPP__
#define __BUBBLE_SORT_HPP__

#include "sort.hpp"

class BubbleSort : public Sort {
    public:
        /* Constructors */
        BubbleSort() : Sort() { };

        /* Pure Virtual Functions */
        virtual void sort(Container* container);
};

#endif //__BUBBLE_SORT_HPP__
