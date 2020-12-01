#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "base.hpp"

class Div : public Base {
    private:
        Base* value1;
        Base* value2;
    public:
        Div(Base* value1, Base* value2) : value1(value1), value2(value2), Base() { this->setValue(evaluate()); }
        virtual double evaluate() { return value1->getValue() / value2->getValue(); }
        virtual std::string stringify() { return value1->stringify() + std::string(" / ") + value2->stringify(); }
        virtual Iterator* create_iterator() { return new BinaryIterator(this); }
        virtual Base* get_left() { return value1; }
        virtual Base* get_right() { return value2; }
};

#endif // __DIV_HPP__