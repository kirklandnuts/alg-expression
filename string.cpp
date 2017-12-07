#include "string.h"
#include <iostream>

int main() {
    string infix_str;
    Expression* my_exp = new Expression();

    cout << "Please enter full parenthesized infix expression: \n";
    // getline(cin, infix_str);
    infix_str = "( 42 + 3 ) * ( 3 - 1 )";
    my_exp->store_exp(infix_str);

    // cout << "my_exp->get_head()->get_operand1()->gen_to_string(): " << my_exp->get_head()->get_operand1()->gen_to_string() << endl;
    //     << "my_exp->get_head()->get_operand2()->gen_to_string(): " << my_exp->get_head()->get_operand2()->gen_to_string() << endl;
    // my_exp->operand1
    // cout << endl << "infix: " << my_exp->infixString() << endl
    //     << "prefix: " << my_exp->prefixString() << endl
    //     << "postfix: " << my_exp->postfixString() << endl
    //     << "evaluate: " << my_exp->evaluate() << endl;


    cout << "1. Expression Evaluation, 2. Expression Comparison" << endl;
    string decision_str;
    getline(cin, decision_str);
    int decision = stoi(decision_str);

    while (decision != 0) {
        if (decision == 1) {
            cout << "Please enter a fully parenthesized expression to be evaluated:\n";
            string exp_str;
            getline(cin, exp_str);
            Expression expression;
            expression.store_exp(exp_str);
            cout << expression.evaluate() << endl;
        } else if (decision == 2) {
            cout << "Please enter 2 comma-separated, fully parenthesized expressions to be compared:\n";
            string exp_str1, exp_str2;
            getline(cin, exp_str1, ',');
            getline(cin, exp_str2);
            Expression expression1, expression2;
            expression1.store_exp(exp_str1);
            expression2.store_exp(exp_str2);
            char comparison = expression1.compare(expression2);
            if (comparison == '=') {
                cout << expression1.infixString() << " is equal to " << expression2.infixString() << ".\n";
            } else if (comparison == '>') {
                cout << expression1.infixString() << " is greater than " << expression2.infixString() << ".\n";
            } else {
                cout << expression1.infixString() << " is less than " << expression2.infixString() << ".\n";
            }
        } else {
            cout << "Incorrect usage\n";
        }
        cout << "1. Expression Evaluation, 2. Expression Comparison, 0. Quit" << endl;
        getline(cin, decision_str);
        decision = stoi(decision_str);
    }

    return 0;
}
