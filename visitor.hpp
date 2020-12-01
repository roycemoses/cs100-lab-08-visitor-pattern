#ifndef __COUNT_VISITOR_HPP__
#define __COUNT_VISITOR_HPP__

class CountVisitor{
    private:
        int ops;
        int rands;
        int mults;
        int divs;
        int add;
        int sub;
        int pow;

    public:
        CountVisitor() {};

        void visit_op() { ++ops; }
        int op_count() { return ops; }
        void visit_rand() { ++rands; };
        int rand_count() { return rands; };
        void visit_mult() { ++mults; }
        int mult_count() { return mults; }
        void visit_div() { ++divs; };
        int div_count() { return divs; };
        void visit_add() { ++add; }
        int add_count() { return add; }
        void visit_sub() { ++sub; };
        int sub_count() { return sub; };
        void visit_pow() { ++pow; }
        int pow_count() { return pow; }
};

#endif //__COUNT_VISITOR_HPP__
