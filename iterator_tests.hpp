#ifndef ITERATOR_TESTS_HPP
#define ITERATOR_TESTS_HPP

#include "gtest/gtest.h"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "pow.hpp"
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

TEST(CreateIteratorTests, IterateAddTree)
{
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* four = new Op(4);
    Base* add1 = new Add(one, four);
    Base* add2 = new Add(two, three);
    Base* add3 = new Add(add1, add2);
    

    EXPECT_EQ(add3->evaluate(), 10);
    EXPECT_EQ(add3->stringify(), "1.000000 + 4.000000 + 2.000000 + 3.000000");
    Iterator* it = add3->create_iterator();
    EXPECT_FALSE(it->is_done());
    EXPECT_EQ(it->current()->evaluate(), 5);
    EXPECT_EQ(it->current()->stringify(), "1.000000 + 4.000000");
    it->next();
    EXPECT_FALSE(it->is_done());    
    EXPECT_EQ(it->current()->evaluate(), 5);
    EXPECT_EQ(it->current()->stringify(), "2.000000 + 3.000000");
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

    it->next();
    EXPECT_TRUE(it->is_done());
    EXPECT_TRUE(it->current() == nullptr);
}
TEST(CreateIteratorTests, IterateMultTree)
{
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* four = new Op(4);
    Base* mult1 = new Mult(one, four);
    Base* mult2 = new Mult(two, three);
    Base* mult3 = new Mult(mult1, mult2);
    

    EXPECT_EQ(mult3->evaluate(), 24);
    EXPECT_EQ(mult3->stringify(), "1.000000 * 4.000000 * 2.000000 * 3.000000");
    Iterator* it = mult3->create_iterator();
    EXPECT_FALSE(it->is_done());
    EXPECT_EQ(it->current()->evaluate(), 4);
    EXPECT_EQ(it->current()->stringify(), "1.000000 * 4.000000");
    it->next();
    EXPECT_FALSE(it->is_done());    
    EXPECT_EQ(it->current()->evaluate(), 6);
    EXPECT_EQ(it->current()->stringify(), "2.000000 * 3.000000");
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

TEST(CreateIteratorTests, IterateLargerDiv)
{
    Base* value1 = new Op(2);
    Base* value2 = new Op(1);
    Base* div = new Div(value1, value2);
    Base* value3 = new Op(4);
    Base* value4 = new Op(1);
    Base* div2 = new Div(value3, value4);
    Base* div3 = new Div(div, div2);
    
    EXPECT_EQ(div3->evaluate(), 0.5);
    EXPECT_EQ(div3->stringify(), "2.000000 / 1.000000 / 4.000000 / 1.000000");

    Iterator* it = div3->create_iterator();

    EXPECT_FALSE(it->is_done());

    EXPECT_EQ(it->current()->evaluate(), 2);
    EXPECT_EQ(it->current()->stringify(), "2.000000 / 1.000000");

    it->next();

    EXPECT_FALSE(it->is_done());

    EXPECT_EQ(it->current()->evaluate(), 4);
    EXPECT_EQ(it->current()->stringify(), "4.000000 / 1.000000");

    it->next();

    EXPECT_TRUE(it->is_done());
    EXPECT_TRUE(it->current() == nullptr);
}

TEST(CreateIteratorTests, IterateRand)
{
    Base* value1 = new Rand();

    Iterator* it = value1->create_iterator();
    EXPECT_TRUE(it->is_done());
    EXPECT_TRUE(it->current() == nullptr);
}    
TEST(CreateIteratorTests, IteratePowTree)
{
    Base* one = new Op(1);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Base* four = new Op(4);
    Base* pow1 = new Pow(two, one);
    Base* pow2 = new Pow(two, three);
    Base* pow3 = new Pow(pow1, pow2);
    

    EXPECT_EQ(pow3->evaluate(), 256);
    EXPECT_EQ(pow3->stringify(), "2.000000 ** 1.000000 ** 2.000000 ** 3.000000");
    Iterator* it = pow3->create_iterator();
    EXPECT_FALSE(it->is_done());
    EXPECT_EQ(it->current()->evaluate(), 2);
    EXPECT_EQ(it->current()->stringify(), "2.000000 ** 1.000000");
    it->next();
    EXPECT_FALSE(it->is_done());    
    EXPECT_EQ(it->current()->evaluate(), 8);
    EXPECT_EQ(it->current()->stringify(), "2.000000 ** 3.000000");
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
    EXPECT_TRUE(it->is_done());
    EXPECT_TRUE(it->current() == nullptr);
}

#endif // ITERATOR_TESTS_HPP