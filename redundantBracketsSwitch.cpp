#include <iostream>
#include <stack>
using namespace std;


bool isRedundant(string msg) {
    stack<char> s;

    for (char c: msg) {
        switch(c) {
            case '(':
            case '{':
            case '[':
                     s.push(c);
                     break;
            
            case ')': if (!s.empty() && s.top() == '(') {
                        s.pop();
                    } else return true; 
                    break;
            case '}': if (!s.empty() && s.top() == '{') {
                        s.pop();
                    } else return true; 
                    break;
            case ']': if (!s.empty() && s.top() == '[') {
                        s.pop();
                    } else return true; 
                    break;

            default: continue;
        }
    }
    return false;
}


int main(void) {
    string msg = "((a+b) + c)";

    if (isRedundant(msg)) {
        cout << "Has redundant brackets" << endl;
    }
    else {
        cout << "No redundant brackets" << endl;
    }

    return 0;
}