#include "list.h"
#include "expression.h"
#include <stack>
#include <string>

using namespace std;

Expression::Expression() {
    this->head = NULL;
}

void Expression::store_exp(string infix_str) {
    this->head = build_list(infix_str);
}

string Expression::infixString() const {
    return head->print_infix();
}

string Expression::prefixString() const {
    return head->print_prefix();
}

string Expression::postfixString() const {
    return head->print_postfix();
}

int operate(int num1, int num2, char op) {
    int rnum;
    if (op == '+') {
        rnum = num1 + num2;
    } else if (op == '-') {
        rnum = num1 - num2;
    } else if (op == '*') {
        rnum = num1 * num2;
    } else if (op == '/') {
        rnum = num1 / num2;
    }
    return rnum;
}

int Expression::evaluate() const {
    string postfix = this->postfixString();
    stack<int> mystack;
    int num1, num2;
    int index = 0;
    while(index < postfix.length()) {
        char c = postfix[index];
        if (c == ' ') {
            index += 1;
        } else if (c == '+' or c == '-' or c == '*' or c == '/') {
            num2 = mystack.top();
            mystack.pop();
            num1 = mystack.top();
            mystack.pop();
            cout << "performing " << num1 << " " << c << " " << num2 << endl;
            mystack.push(operate(num1, num2, c));
            index += 1;
        } else {
            string num;
            while (isdigit(c)) {
                num.push_back(c);
                index += 1;
                c = postfix[index];
            }
            num.push_back(c);
            mystack.push(atoi(num.c_str()));
            index += 1;
        }
    }
    return mystack.top();
}


char Expression::compare(Expression compare_exp) const {
    int original = this->evaluate();
    int compare = compare_exp.evaluate();
    if (original == compare)
        return '=';
    else if (original > compare)
        return '>';
    else
        return '<';
}
