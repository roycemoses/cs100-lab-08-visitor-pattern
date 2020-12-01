#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    public:
        Op(double value) : Base() { this->setValue(value); }
        virtual double evaluate() { return this->getValue(); }
        virtual std::string stringify() { return std::to_string(evaluate()); }
        virtual Iterator* create_iterator() { return new NullIterator(this); }
        virtual Base* get_left() { return nullptr; }
        virtual Base* get_right() { return nullptr; }
        virtual void accept(CountVisitor* cv) { cv->visit_op(); }
};

#endif //__OP_HPP__