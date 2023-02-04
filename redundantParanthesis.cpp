#include <iostream>
#include <stack>
using namespace std;

bool isRedundant(string msg) {
    stack<char> s;
    
    for (char c: msg) {
        if (c == ')') {
            bool operator_found = false;
            char temp = s.top();
            s.pop();
            while (temp != '(' && !s.empty()) {
                if (temp == '+' || temp == '-' || temp == '/' || temp == '*') {
                    operator_found = true;
                    
                }
                temp = s.top();
                s.pop();
            }
            if (operator_found == false) return true;
        }
        s.push(c);
    }

    return false;
}

int main(void) {
    string msg = "((a+b)) + c)";

    if (isRedundant(msg)) {
        cout << "Yes redundancy" << endl;
    }
    else cout << "No redundancy" << endl;

    return 0;
}