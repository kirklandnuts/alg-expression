#include "node.h"
#include <iostream>
#include <cctype>

using namespace std;

Node* build_list(string infix_string) {
    Node* current = new Node();
    Node* head = current;
    int index = 1;
    while (index < infix_string.length() - 1) {
        cout << "i: " << to_string(index) << endl;
        char cursor = infix_string[index];
        if (cursor == '(') {
            cout << "creating new op node [" << cursor << "]\n";
            Node* n = new Node();
            n->set_parent(current);
            if (current->get_operand1() == NULL) {
                current->set_operand1(n);
            } else {
                current->set_operand2(n);
            }
            current = n;
        } else if (cursor == '+' or cursor == '-' or cursor == '*' or cursor == '/') {
            cout << "setting operator [" << cursor << "]\n";
            current->set_operator(cursor);
        } else if (cursor == 'x') {
            cout << "creating new var node [" << cursor << "]\n";
            Node* n = new Node();
            n->set_variable(cursor);
            n->set_parent(current);
            current->set_operand1(n);
        } else if (isdigit(cursor)) {
            string num;
            while (isdigit(cursor)) {
                num.push_back(cursor);
                index += 1;
                cursor = infix_string[index];
            }
            num.push_back(cursor);
            cout << "creating new int node [" << num << "]\n";
            Node* n = new Node();
            n->set_value(num);
            n->set_parent(current);
            current->set_operand2(n);
        } else if (cursor == ')') {
            cout << "traversing to parent node [" << cursor << "]\n";
            current = current->get_parent();
            cout << "traversed to parent node [" << cursor << "]\n";
        }
        cout << "current: " << current->gen_to_string() << endl;
        if (current->get_operand1() != NULL) {
            cout << "op1: " << current->get_operand1()->gen_to_string() << endl;
        }
        if (current->get_operand2() != NULL) {
            cout << "op2: " << current->get_operand2()->gen_to_string() << endl;
        }
        if (current->get_parent() != NULL) {
            cout << "op2: " << current->get_parent()->gen_to_string() << endl;
        }
        cout << endl;
        //     << "op1: " << current->get_operand1()->gen_to_string() << endl
        //     << "op2: " << current->get_operand2()->gen_to_string() << endl;
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
    // string infix_str = "(((x+3)*(x-5))-(x/2))";
    // string infix_str = "(x+3)";
    string infix_str = "( ( x + 32 ) * ( x + 2 ) )";
    Node* list = build_list(infix_str);

    cout << "infix: " << list->print_infix() << endl
        << "prefix: " << list->print_prefix() << endl
        << "postfix: " << list->print_postfix() << endl;

    return 0;
}
