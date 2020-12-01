#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() { this->setValue(value); }
        virtual double evaluate() { return this->getValue(); }
        virtual std::string stringify() { return std::to_string(evaluate()); }
        virtual Iterator* create_iterator() {};
        virtual Base* get_left() {};
        virtual Base* get_right() {};
};

#endif //__OP_HPP__