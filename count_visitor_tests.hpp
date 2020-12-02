#ifndef COUNT_VISITOR_TESTS_HPP
#define COUNT_VISITOR_TESTS_HPP

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "rand.hpp"

TEST(CountVisitorTests, CountOp)
{
    CountVisitor cv;
    Base* two = new Op(2);
    Base* four = new Op(4);
    Base* add = new Add(two, four);
    Base* dummy = new Add(add, add);
    Iterator* it = new PreorderIterator(dummy);
    it->first();
    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.add_count(), 2);
    EXPECT_EQ(cv.op_count(), 4);
}

TEST(CountVisitorTests, CountAdd)
{
    CountVisitor cv;
    Base* rand = new Rand;
    Base* two = new Op(2);
    Base* four = new Op(4);
    Base* add = new Add(two, four);
    Base* dummy = new Add(add, rand);
    Iterator* it = new PreorderIterator(dummy);
    it->first();
    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.add_count(), 1);
    EXPECT_EQ(cv.op_count(), 2);
    EXPECT_EQ(cv.rand_count(), 1);
}

TEST(CountVisitorTests, CountMult)
{
    CountVisitor cv;
    Base* rand = new Rand;
    Base* two = new Op(2);
    Base* four = new Op(4);
    Base* mult = new Mult(two, four);
    Base* dummy = new Add(mult, rand);
    Iterator* it = new PreorderIterator(dummy);
    it->first();
    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.mult_count(), 1);
    EXPECT_EQ(cv.op_count(), 2);
    EXPECT_EQ(cv.rand_count(), 1);
}

TEST(CountVisitorTests, CountPow)
{
    CountVisitor cv;
    Base* rand = new Rand;
    Base* two = new Op(2);
    Base* four = new Op(4);
    Base* pow = new Pow(two, four);
    Base* dummy = new Add(pow, rand);
    Iterator* it = new PreorderIterator(dummy);
    it->first();
    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.pow_count(), 1);
    EXPECT_EQ(cv.op_count(), 2);
    EXPECT_EQ(cv.rand_count(), 1);
}

TEST(CountVisitorTests, CountManyAdds)
{
    CountVisitor cv;
    Base* two = new Op(2);
    Base* four = new Op(4);
    Base* six = new Add(two, four); // 1 Add
    Base* twelve = new Add(six, six); // 3 Adds
    Base* twenty_four = new Add(twelve, twelve); // 7 Adds
    Base* forty_eight = new Add(twenty_four, twenty_four); // 15 Adds

    EXPECT_EQ(forty_eight->evaluate(), 48);
    EXPECT_EQ(forty_eight->stringify(), 
        "2.000000 + 4.000000 + 2.000000 + 4.000000 + 2.000000 + 4.000000 + 2.000000 + 4.000000 + "
        "2.000000 + 4.000000 + 2.000000 + 4.000000 + 2.000000 + 4.000000 + 2.000000 + 4.000000");

    Iterator* it = new PreorderIterator(forty_eight);
    it->first();
    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.add_count(), 14);
    EXPECT_EQ(cv.op_count(), 16);
}


#endif // COUNT_VISITOR_TESTS_HPP