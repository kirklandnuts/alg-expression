#include "list.h"

using namespace std;

Expression::Expression(string infix_exp) {
    infix = infix_exp;
    head = build_list(infix_exp);
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
