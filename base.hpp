#ifndef __BASE_HPP__
#define __BASE_HPP__

#include <string>
#include "iterator.hpp"

class Base {
    private:
        double value;
    public:
        /* Constructors */
        Base() { };

        /* Pure Virtual Functions */
        virtual double evaluate() = 0;
        virtual std::string stringify() = 0;
        virtual Iterator* create_iterator() = 0;

        /* Public Functions */
        double getValue() { return this->value; }
        void setValue(double value) { this->value = value; }
};

#endif //__BASE_HPP__
