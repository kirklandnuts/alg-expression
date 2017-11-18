#ifndef NODE_H
#define NODE_H
#include <string>
#include <cstring>

using namespace std;

enum node_type{EXPRESSION, VARIABLE, INTEGER};
enum operator_type{PLUS, MINUS, MULT, DIVIDE};

union data_type {
    operator_type op;
    char var;
    int val;
};

class Node {
	public:
		// Constructor
        // Node(char var = 'x', Node* parent = NULL);
        Node(operator_type op = PLUS, Node* operand1 = NULL, Node* operand2 = NULL, Node* parent = NULL);
        // Node(int val = 0, Node* parent = NULL);
        // Destructor
        ~Node();

        // Mutators
        void set_operand1(Node* new_operand1);
        void set_operand2(Node* new_operand2);
        void set_parent(Node* new_parent);
        void set_operator(char op);
        void set_variable(char var);
        void set_value(string val);

        // Observers
        string print_infix() const;
        string print_prefix() const;
        string print_postfix() const;
        string int_to_string() const;
        string gen_to_string() const;
        string print_operator() const;
        node_type get_type() const {return node_t;}
        Node* get_operand1() const {return operand1;}
        Node* get_operand2() const {return operand2;}
        Node* get_parent() const {return parent;}



    private:
        node_type node_t;
        data_type data;
        Node* operand1;
        Node* operand2;
        Node* parent;
};

#endif
