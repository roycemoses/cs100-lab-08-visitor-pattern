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
        CountVisitor();

        void visit_op() { ++ops; }
        int op_count() { return ops; }
        void visit_rand();
        int rand_count();
        void visit_mult() { ++mults; }
        int mult_count() { return mults; }
        void visit_div();
        int div_count();
        void visit_add() { ++add; }
        int add_count() { return add; }
        void visit_sub();
        int sub_count();
        void visit_pow();
        int pow_count();

};

#endif //__COUNT_VISITOR_HPP__
