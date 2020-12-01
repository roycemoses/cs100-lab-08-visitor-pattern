#ifndef __LIST_CONTAINER_HPP__
#define __LIST_CONTAINER_HPP__

#include "container.hpp"
#include "base.hpp"
#include <stdexcept>
#include <iostream>

class ListContainer : public Container {
    protected:
        Base** list;
        int sz;
        int capacity;

    public:
        /* Constructors */
        ListContainer() : Container()
        {
            sz = 0;
            capacity = 1;
            list = new Base*[capacity];
        }
        ListContainer(Sort* function) : Container()
        {
            sz = 0;
            capacity = 1;
            list = new Base*[capacity];
        }
        ~ListContainer();

        /* Non Virtual Functions */
        void expand();

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

#endif //__LIST_CONTAINER_HPP__
