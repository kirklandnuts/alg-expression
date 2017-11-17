#include "string.h"
#include <iostream>

int main() {
    string infix_str;
    Expression* my_exp = new Expression();

    cout << "Please enter full parenthesized infix expression: \n";
    getline(cin, infix_str);
    my_exp->store_exp(infix_str);

    cout << endl << "infix: " << my_exp->infixString() << endl
        << "prefix: " << my_exp->prefixString() << endl
        << "postfix: " << my_exp->postfixString() << endl;

    return 0;
}
