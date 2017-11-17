#include "node.h"
#include <iostream>
#include <cctype>

using namespace std;

Node* build_list(string infix_string) {
    Node* current;
    Node* head = current;
    int index = 1;
    while (index < infix_string.length()) {
        char cursor = infix_string[index];
        if (cursor == '(') {
            Node* n;
            if (current->get_operand1() == NULL) {
                current->set_operand1(n);
            } else {
                current->set_operand2(n);
            }
            current = n;
        } else if (cursor == '+' or cursor == '-' or cursor == '*' or cursor == '/') {
            current->set_operator(cursor);
        } else if (cursor == 'x') {
            current->set_variable(cursor);
        } else if (isdigit(cursor)) {
            current->set_value((int)cursor);
        } else if (cursor == ')') {
            current = current->get_parent();
        }
        index += 1;
    }
    return head;
}

int main() {
    // Node* var = new Node('x');
    // Node* val = new Node(1);
    // Node* op = new Node(MINUS, var, val);
    //
    // Node* var2 = new Node('x');
    // Node* val2 = new Node(23);
    // Node* op2 = new Node(DIVIDE, var2, val2);
    //
    // Node* op3 = new Node(MULT, op, op2);
    //
    // op2->set_parent(op3);
    string infix_str = "((x+3)*(x-5))-(x/2)";
    Node* list = build_list(infix_str);

    cout << "infix: " << list->print_infix() << endl
        << "prefix: " << list->print_prefix() << endl
        << "postfix: " << list->print_postfix() << endl;

    return 0;
}
