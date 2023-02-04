#include <iostream>
#include <stack>

using namespace std;

bool isRedundant(string msg) {
    stack<char> s;

    for (char c: msg) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) return true;
            if (c == ')' && s.top() != '(') return true;
            if (c == ']' && s.top() != '[') return true;
            if (c == '}' && s.top() != '{') return true;

            s.pop();
        }
    }

    return false;
}

int main(void) {
    string msg = "((a+b)([)) + c)";

    if (isRedundant(msg)) {
        cout << "Has redundant brackets" << endl;
    }
    else {
        cout << "No redundant brackets" << endl;
    }

    return 0;
}