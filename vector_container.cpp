#include "vector_container.hpp"

/* Virtual Functions */
// push the top pointer of the tree into container
void VectorContainer::add_element(Base* element) { this->v.push_back(element); }

// iterate through trees and output the expressions (use stringify())
void VectorContainer::print() 
{
    for (int i = 0; i < v.size(); ++i) 
    {
        std::cout << v.at(i)->stringify();
        if (i < v.size() - 1)
            std::cout << ", ";
    }  
    std::cout << std::endl;
}

// calls on the previously set sorting-algorithm. Checks if sort_function is not null, throw exception if otherwise
void VectorContainer::sort() 
{ 
    std::invalid_argument ia("Uninitialized sort_function pointer");
    if (this->sort_function == nullptr) 
        throw ia;
    
    this->sort_function->sort(this);

}

/* Essentially the only functions needed to sort */
//switch tree locations
void VectorContainer::swap(int i, int j) 
{ 
    Base* temp = v.at(i); 
    v.at(i) = v.at(j); 
    v.at(j) = temp; 
}

// get top ptr of tree at index i
Base* VectorContainer::at(int i) { return v.at(i); }

// return container size
int VectorContainer::size() { return v.size(); }