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

TEST(CountVisitorTests, CountSub)
{
    CountVisitor cv;
    Base* value1 = new Op(2);
    Base* value2 = new Op(1);
    Base* sub = new Sub(value1, value2);
    Base* rand = new Rand();

    Base* dummy = new Sub(sub, rand);
    Iterator* it = new PreorderIterator(dummy);
    it->first();

    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.sub_count(), 1);
    EXPECT_EQ(cv.op_count(), 2);
    EXPECT_EQ(cv.rand_count(), 1);
}

TEST(CountVisitorTests, CountSubs)
{
    CountVisitor cv;
    Base* value1 = new Op(2);
    Base* value2 = new Op(1);
    Base* sub = new Sub(value1, value2); // 2 - 1
    Base* sub2 = new Sub(value2, sub); // 1 - (2 - 1)
    Base* sub3 = new Sub(value1, sub2); // 2 - (1 - (2 - 1))
    Base* rand = new Rand();

    Base* dummy = new Sub(sub3, rand);
    Iterator* it = new PreorderIterator(dummy);
    it->first();

    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.sub_count(), 3);
    EXPECT_EQ(cv.op_count(), 4);
    EXPECT_EQ(cv.rand_count(), 1);
}

TEST(CountVisitorTests, CountRand)
{
    CountVisitor cv;
    Base* value1 = new Op(1);
    Base* rand = new Rand();

    Base* dummy = new Sub(value1, rand);
    Iterator* it = new PreorderIterator(dummy);
    it->first();

    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.op_count(), 1);
    EXPECT_EQ(cv.rand_count(), 1);
}

TEST(CountVisitorTests, CountDivs)
{
    CountVisitor cv;
    Base* value1 = new Op(2);
    Base* value2 = new Op(1);
    Base* div = new Div(value1, value2); // 2 / 1
    Base* div2 = new Div(value2, div); // 1 / (2 / 1)
    Base* div3 = new Div(value1, div2); // 2 / (1 / (2 / 1))
    Base* rand = new Rand();

    Base* dummy = new Sub(div3, rand);
    Iterator* it = new PreorderIterator(dummy);
    it->first();

    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.div_count(), 3);
    EXPECT_EQ(cv.op_count(), 4);
    EXPECT_EQ(cv.rand_count(), 1);
}


TEST(CountVisitorTests, CountNoSubs)
{
    CountVisitor cv;
    Base* value1 = new Rand();
    Base* rand = new Rand();

    Base* dummy = new Sub(value1, rand);
    Iterator* it = new PreorderIterator(dummy);
    it->first();

    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.sub_count(), 0);
    EXPECT_EQ(cv.rand_count(), 2);
}

TEST(CountVisitorTests, CountNoDivs)
{
    CountVisitor cv;
    Base* value1 = new Rand();
    Base* rand = new Rand();

    Base* dummy = new Sub(value1, rand);
    Iterator* it = new PreorderIterator(dummy);
    it->first();

    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.div_count(), 0);
    EXPECT_EQ(cv.rand_count(), 2);
}

TEST(CountVisitorTests, CountNoRands)
{
    CountVisitor cv;
    Base* value1 = new Op(1);
    Base* value2 = new Op(1);

    Base* dummy = new Sub(value1, value2);
    Iterator* it = new PreorderIterator(dummy);
    it->first();

    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.op_count(), 2);
    EXPECT_EQ(cv.rand_count(), 0);
}

#endif // COUNT_VISITOR_TESTS_HPP