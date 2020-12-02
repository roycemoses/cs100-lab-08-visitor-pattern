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

TEST(CountVisitorTests, CountManyMults)
{
    CountVisitor cv;
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* mult1 = new Mult(one, two); // 1 Mult, 1 * 2
    Base* mult2 = new Mult(mult1, mult1); // 3 Mults, 2 * 2
    Base* mult3 = new Mult(mult2, mult2); // 7 Mults, 4 * 4
    Base* mult4 = new Mult(mult3, mult3); // 15 Mults, 16 * 16

    EXPECT_EQ(mult4->evaluate(), 256);
    EXPECT_EQ(mult4->stringify(), 
        "1.000000 * 2.000000 * 1.000000 * 2.000000 * 1.000000 * 2.000000 * 1.000000 * 2.000000 * "
        "1.000000 * 2.000000 * 1.000000 * 2.000000 * 1.000000 * 2.000000 * 1.000000 * 2.000000");

    Iterator* it = new PreorderIterator(mult4);
    it->first();
    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.mult_count(), 14);
    EXPECT_EQ(cv.op_count(), 16);
}

TEST(CountVisitorTests, CountManyPows)
{
    CountVisitor cv;
    Base* two = new Op(2);
    Base* four = new Pow(two, two); // 1 Pow, 2 ** 2
    Base* sixteen = new Pow(two, four); // 2 Pows, 2 ** 4
    Base* result = new Pow(two, sixteen); // 3 Pows, 2 * 16

    EXPECT_EQ(result->evaluate(), 65536);
    EXPECT_EQ(result->stringify(), 
        "2.000000 ** 2.000000 ** 2.000000 ** 2.000000");

    Iterator* it = new PreorderIterator(result);
    it->first();
    do {
        it->current()->accept(&cv);
        it->next();
    } while (!it->is_done());

    EXPECT_EQ(cv.pow_count(), 2);
    EXPECT_EQ(cv.op_count(), 4);
}
#endif // COUNT_VISITOR_TESTS_HPP