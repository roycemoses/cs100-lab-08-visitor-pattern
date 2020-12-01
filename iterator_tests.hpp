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
    EXPECT_EQ(it->current()->evaluate(), 2);
    EXPECT_EQ(it->current()->stringify(), "2.000000");
    it->next();
    EXPECT_EQ(it->current()->evaluate(), 4);
    EXPECT_EQ(it->current()->stringify(), "4.000000");
}


#endif // ITERATOR_TESTS_HPP