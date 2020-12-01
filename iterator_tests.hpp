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

    EXPECT_EQ(it->current()->evaluate(), 2);
    EXPECT_EQ(it->current()->stringify(), "2.000000");

    it->next();

    EXPECT_EQ(it->current()->evaluate(), 1);
    EXPECT_EQ(it->current()->stringify(), "1.000000");
}




#endif // ITERATOR_TESTS_HPP