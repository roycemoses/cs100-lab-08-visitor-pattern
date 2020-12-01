#ifndef ITERATOR_TESTS_HPP
#define ITERATOR_TESTS_HPP

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "pow.hpp"

TEST(CreateIteratorTests, IterateAdd)
{
    Base* two = new Op(2);
    Base* four = new Op(4);
    Base* add = new Add(two, four);

    EXPECT_EQ(add->evaluate(), 6);
    EXPECT_EQ(add->stringify(), "2.000000 + 4.000000");
    Iterator* it = add->create_iterator();
    EXPECT_FALSE(it->is_done());
    EXPECT_EQ(it->current()->evaluate(), 2);
    EXPECT_EQ(it->current()->stringify(), "2.000000");
    it->next();
    EXPECT_FALSE(it->is_done());    
    EXPECT_EQ(it->current()->evaluate(), 4);
    EXPECT_EQ(it->current()->stringify(), "4.000000");
    it->next();
    EXPECT_TRUE(it->is_done());
    EXPECT_TRUE(it->current() == nullptr);    
}

TEST(CreateIteratorTests, IterateMult)
{
    Base* three = new Op(3);
    Base* five = new Op(5);
    Base* mult = new Mult(three, five);

    EXPECT_EQ(mult->evaluate(), 15);
    EXPECT_EQ(mult->stringify(), "3.000000 * 5.000000");
    Iterator* it = mult->create_iterator();
    EXPECT_FALSE(it->is_done());
    EXPECT_EQ(it->current()->evaluate(), 3);
    EXPECT_EQ(it->current()->stringify(), "3.000000");
    it->next();
    EXPECT_FALSE(it->is_done());
    EXPECT_EQ(it->current()->evaluate(), 5);
    EXPECT_EQ(it->current()->stringify(), "5.000000");
    it->next();
    EXPECT_TRUE(it->is_done());
    EXPECT_TRUE(it->current() == nullptr);
}

TEST(CreateIteratorTests, IteratePow)
{
    Base* two = new Op(2);
    Base* six = new Op(6);
    Base* pow = new Pow(two, six);

    EXPECT_EQ(pow->evaluate(), 64);
    EXPECT_EQ(pow->stringify(), "2.000000 ** 6.000000");
    Iterator* it = pow->create_iterator();
    EXPECT_FALSE(it->is_done());
    EXPECT_EQ(it->current()->evaluate(), 2);
    EXPECT_EQ(it->current()->stringify(), "2.000000");
    it->next();
    EXPECT_FALSE(it->is_done());
    EXPECT_EQ(it->current()->evaluate(), 6);
    EXPECT_EQ(it->current()->stringify(), "6.000000");
    it->next();
    EXPECT_TRUE(it->is_done());
    EXPECT_TRUE(it->current() == nullptr);
}

TEST(CreateIteratorTests, IterateOp)
{
    Base* two = new Op(2);

    EXPECT_EQ(two->evaluate(), 2);
    EXPECT_EQ(two->stringify(), "2.000000");
    Iterator* it = two->create_iterator();
}


#endif // ITERATOR_TESTS_HPP