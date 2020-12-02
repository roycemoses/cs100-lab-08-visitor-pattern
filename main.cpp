#include <iostream>

#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "rand.hpp"
#include "iterator.hpp"

using namespace std;

int main(int, char**) 
{
    // view main.png to see the diagram of this implementation
    Base* zero = new Op(0);
    Base* one = new Op(1);
    Base* two = new Op(2);

    Base* add = new Add(zero, two);
    Base* pow = new Pow(two, one);
    Base* sub1 = new Sub(two, one);
    Base* sub2 = new Sub(zero, zero);
    
    Base* mult = new Mult(add, pow);
    Base* sub3 = new Sub(sub1, sub2);

    Base* div = new Div(mult, sub3);
    Base* rand = new Rand();

    Base* dummy = new Add(div, rand);

    CountVisitor cv;
    Iterator* it = new PreorderIterator(dummy);
    it->first();

    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    cout << "op_count: " << cv.op_count() << endl;
    cout << "add_count: " << cv.add_count() << endl;
    cout << "sub_count: " << cv.sub_count() << endl; 
    cout << "mult_count: " << cv.mult_count() << endl;
    cout << "div_count: " << cv.div_count() << endl;
    cout << "pow_count: " << cv.pow_count() << endl; 
    cout << "rand_count: " << cv.rand_count() << endl << endl;

    cout << "root->stringify(): " << div->stringify() << endl;
    cout << "root->evaluate(): " << div->evaluate() << endl;
    cout << "(does NOT include dummy node and its value)" << endl << endl;
}
