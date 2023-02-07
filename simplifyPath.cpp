#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string simplify(string path) {
    istringstream iss(path);

    string token;
    vector<string> stack;
    while (getline(iss, token, '/')) {
        if ( (token == ".") || (token == "") ) {
            continue;
        }

        if (token == "..") {
            if (stack.size() != 0) {
                stack.pop_back();
            }
            continue;
        }
        stack.push_back(token);
    }

    for (string s: stack) cout << "/" << s;
    cout << endl;

    return " ";
}

int main(void) {
    string path = "/../x/y/../z/././w/a///../c/./";
    //   x/z/w/c

    simplify(path);

    return 0;
}