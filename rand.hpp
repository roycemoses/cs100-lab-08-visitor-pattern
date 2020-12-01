#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"

class Rand : public Base {
    public:
        Rand() : Base() { this->setValue(rand() % 100); }
        virtual double evaluate() { return this->getValue(); }
        virtual std::string stringify() { return std::to_string(evaluate()); }
        virtual Iterator* create_iterator() { return new NullIterator(this); }
        virtual Base* get_left() { return nullptr; }
        virtual Base* get_right() { return nullptr; }
};

#endif //__RAND_HPP__