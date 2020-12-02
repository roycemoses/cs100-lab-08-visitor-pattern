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

#endif // COUNT_VISITOR_TESTS_HPP