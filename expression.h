#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>
#include "node.h"


using namespace std;

class Expression {
    public:
        Expression();

        void store_exp(string infix_str);

        string infixString() const;
        string prefixString() const;
        string postfixString() const;
        int evaluate() const;
        char compare(Expression compare_exp) const;
    private:
        Node* head;
};

#endif
