#ifndef EXPRESSION_H
#define EXPRESSION_H

using namespace std;

class Expression {
    public:
        Expression(string infix);
        string infixString() const;
        string prefixString() const;
        string postfixString() const;
    private:
        string infix;
};
