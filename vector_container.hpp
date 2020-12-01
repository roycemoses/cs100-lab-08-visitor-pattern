#ifndef __VECTOR_CONTAINER_HPP__
#define __VECTOR_CONTAINER_HPP__

#include "container.hpp"
#include <vector>
#include <stdexcept>
#include <iostream>

using std::vector;

class VectorContainer: public Container {
    protected:
        vector<Base*> v;

    public:
        /* Constructors */
        VectorContainer() : Container() { };
        VectorContainer(Sort* function) : Container() { };

        /* Virtual Functions */
        // push the top pointer of the tree into container
        virtual void add_element(Base* element);
        // iterate through trees and output the expressions (use stringify())
        virtual void print();
        // calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
        virtual void sort();

        /* Essentially the only functions needed to sort */
        //switch tree locations
        virtual void swap(int i, int j);
        // get top ptr of tree at index i
        virtual Base* at(int i);
        // return container size
        virtual int size();
};

#endif //__VECTOR_CONTAINER_HPP__
