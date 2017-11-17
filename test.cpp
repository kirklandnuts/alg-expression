#include <cstring>
#include <string>
#include <iostream>

using namespace std;

enum operator_type{PLUS, MINUS, MULT, DIVIDE};

union data_type {
    operator_type op;
    char var;
    int val;
};

int main() {
    string out_str;
    string infix_string = "henlo 123 uwu";
    int index = 0;
    while (index < infix_string.length() - 1) {
        char cursor = infix_string[index];
        if (isdigit(cursor)) {
            while (isdigit(cursor)) {
                out_str.push_back(cursor);
                index += 1;
                cursor = infix_string[index];
            }
        }
        index += 1;
    }
    cout << out_str << endl;
}
