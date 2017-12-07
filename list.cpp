#include "list.h"

using namespace std;

Node* build_list(string infix_string) {
    Node* current = new Node();
    Node* head = current;
    int index = 0;
    while (index < infix_string.length() - 1) {
        char cursor = infix_string[index];
        cout << "processing char: " << cursor << endl;
        if (cursor == '(') {
            Node* n = new Node();
            n->set_parent(current);
            if (current->get_operand1() == NULL) {
                current->set_operand1(n);
            } else {
                current->set_operand2(n);
            }
            current = n;
        } else if (cursor == '+' or cursor == '-' or cursor == '*' or cursor == '/') {
            current->set_operator(cursor);
        } else if (cursor == 'x') {
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
            Node* n = new Node();
            n->set_value(num);
            n->set_parent(current);
            if (current->get_operand1() == NULL) {
                current->set_operand1(n);
            } else {
                current->set_operand2(n);
            }
        } else if (cursor == ')') {
            current = current->get_parent();
        }
        index += 1;
    }
    if (head->get_operand2() == NULL) {
        head = head->get_operand1();
    }
    return head;
}
