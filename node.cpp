#include <iostream>
#include <string>
#include <cstddef>
#include "node.h"

using namespace std;

// Node::Node(char var, Node* parent) {
//     data.var = var;
//     node_t = VARIABLE;
//     this->parent = parent;
//     this->operand1 = NULL;
//     this->operand2 = NULL;
// }

Node::Node(operator_type op, Node* operand1, Node* operand2, Node* parent) {
    data.op = op;
    node_t = EXPRESSION;
    this->parent = parent;
    this->operand1 = operand1;
    this->operand2 = operand2;
}

// Node::Node(int val, Node* parent) {
//     data.val = val;
//     node_t = INTEGER;
//     this->parent = NULL;
//     this->operand1 = NULL;
//     this->operand2 = NULL;
// }

// Destructor
Node::~Node() {
    delete parent;
    delete operand1;
    delete operand2;
}

void Node::set_operand1(Node* new_operand1) {
    this->operand1 = new_operand1;
}

void Node::set_operand2(Node* new_operand2) {
    this->operand2 = new_operand2;
}

void Node::set_parent(Node* new_parent) {
    this->parent = new_parent;
}

void Node::set_operator(char op) {
    if (op == '+') {
        data.op = PLUS;
    } else if (op == '-') {
        data.op = MINUS;
    } else if (op == '*') {
        data.op = MULT;
    } else {
        data.op = DIVIDE;
    }
    node_t = EXPRESSION;
}

void Node::set_variable(char var) {
    data.var = var;
    node_t = VARIABLE;
}

void Node::set_value(string val) {
    this->data.val = atoi(val.c_str());;
    node_t = INTEGER;
}

string Node::print_infix() const {
    string s = "(";
    if (operand1->node_t == VARIABLE) {
        s += operand1->data.var;
        s += print_operator();
        s += operand2->int_to_string();
    }
    else {
        s += operand1->print_infix();
        s += print_operator();
        s += operand2->print_infix();
    }
    s += ")";
    return s;
}

string Node::print_prefix() const {
    string s = "";
    if (operand1->node_t == VARIABLE) {
        s += print_operator();
        s += operand1->data.var;
        s += operand2->int_to_string();
    } else {
        s += print_operator();
        s += operand1->print_prefix();
        s += operand2->print_prefix();
    }
    return s;
}

string Node::print_postfix() const {
    string s = "";
    if (operand1->node_t == VARIABLE) {
        s += operand1->data.var;
        s += operand2->int_to_string();
        s += print_operator();
    } else {
        s += operand1->print_postfix();
        s += operand2->print_postfix();
        s += print_operator();
    }
    return s;
}

string Node::int_to_string() const {
    return to_string(data.val);
    // return "fuck";
}

string Node::print_operator() const {
    if (data.op == PLUS) {
        return "+";
    } else if (data.op == MINUS) {
        return "-";
    } else if (data.op == MULT) {
        return "*";
    } else {
        return "/";
    }
}

string Node::gen_to_string() const {
    if (node_t == EXPRESSION) {
        return this->print_operator();
    } else if (node_t == VARIABLE) {
        string s;
        s.push_back(data.var);
        return s;
    } else {
        return this->int_to_string();
        // return "VALUE";
    }
}
