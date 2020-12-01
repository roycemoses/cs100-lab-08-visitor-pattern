#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    private:
        Base* value1;
        Base* value2;
    public:
        Mult(Base* value1, Base* value2) : value1(value1), value2(value2), Base() { this->setValue(evaluate()); }
        virtual double evaluate() { return value1->getValue() * value2->getValue(); }
        virtual std::string stringify() { return value1->stringify() + std::string(" * ") + value2->stringify(); }
};

#endif // __MULT_HPP__