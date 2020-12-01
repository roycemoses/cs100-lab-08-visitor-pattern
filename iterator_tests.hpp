#ifndef ITERATOR_TESTS_HPP
#define ITERATOR_TESTS_HPP

#include "gtest/gtest.h"
#include "op.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "rand.hpp"

TEST(CreateIteratorTests, IterateSub)
{
    Base* value1 = new Op(2);
    Base* value2 = new Op(1);
    Base* sub = new Sub(value1, value2);
    
    EXPECT_EQ(sub->evaluate(), 1);
    EXPECT_EQ(sub->stringify(), "2.000000 - 1.000000");

    Iterator* it = sub->create_iterator();

    EXPECT_FALSE(it->is_done());

    EXPECT_EQ(it->current()->evaluate(), 2);
    EXPECT_EQ(it->current()->stringify(), "2.000000");

    it->next();

    EXPECT_FALSE(it->is_done());

    EXPECT_EQ(it->current()->evaluate(), 1);
    EXPECT_EQ(it->current()->stringify(), "1.000000");

    it->next();

    EXPECT_TRUE(it->is_done());
    EXPECT_TRUE(it->current() == nullptr);
}

TEST(CreateIteratorTests, IterateLargerSub)
{
    Base* value1 = new Op(2);
    Base* value2 = new Op(1);
    Base* sub = new Sub(value1, value2);
    Base* value3 = new Op(10);
    Base* value4 = new Op(9);
    Base* sub2 = new Sub(value3, value4);
    Base* sub3 = new Sub(sub, sub2);

    EXPECT_EQ(sub3->evaluate(), 0);
    EXPECT_EQ(sub3->stringify(), "2.000000 - 1.000000 - 10.000000 - 9.000000");

    Iterator* it = sub3->create_iterator();

    EXPECT_FALSE(it->is_done());

    EXPECT_EQ(it->current()->evaluate(), 1);
    EXPECT_EQ(it->current()->stringify(), "2.000000 - 1.000000");

    it->next();

    EXPECT_FALSE(it->is_done());

    EXPECT_EQ(it->current()->evaluate(), 1);
    EXPECT_EQ(it->current()->stringify(), "10.000000 - 9.000000");

    it->next();

    EXPECT_TRUE(it->is_done());
    EXPECT_TRUE(it->current() == nullptr);
}

TEST(CreateIteratorTests, IterateDiv)
{
    Base* value1 = new Op(2);
    Base* value2 = new Op(1);
    Base* div = new Div(value1, value2);
    
    EXPECT_EQ(div->evaluate(), 2);
    EXPECT_EQ(div->stringify(), "2.000000 / 1.000000");

    Iterator* it = div->create_iterator();

    EXPECT_FALSE(it->is_done());

    EXPECT_EQ(it->current()->evaluate(), 2);
    EXPECT_EQ(it->current()->stringify(), "2.000000");

    it->next();

    EXPECT_FALSE(it->is_done());

    EXPECT_EQ(it->current()->evaluate(), 1);
    EXPECT_EQ(it->current()->stringify(), "1.000000");

    EXPECT_TRUE(it->is_done());
    EXPECT_TRUE(it->current() == nullptr);
}




#endif // ITERATOR_TESTS_HPP