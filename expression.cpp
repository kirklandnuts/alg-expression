#include "list.h"
#include "expression.h"
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
