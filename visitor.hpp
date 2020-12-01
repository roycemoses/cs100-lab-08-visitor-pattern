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

        void visit_op();
        int op_count();
        void visit_rand() { ++rands; };
        int rand_count();
        void visit_mult();
        int mult_count();
        void visit_div();
        int div_count();
        void visit_add();
        int add_count();
        void visit_sub();
        int sub_count();
        void visit_pow();
        int pow_count();

};

#endif //__COUNT_VISITOR_HPP__
