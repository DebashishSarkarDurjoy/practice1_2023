#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string simplify(string path) {
    istringstream iss(path);

    // filtering
    vector<string> tokens;
    string token;
    while (getline(iss, token, '/')) {
        if (token == "." || token == "") {
            continue;
        }
        tokens.push_back(token);
    }

    vector<string> stack;
    if (path[0] == '/') {
        stack.push_back("");
    }

    for (auto token: tokens) {
        if (token == "..") {
            if ( (stack.size() == 0) || (stack[stack.size()-1] == "..") ) {
                stack.push_back("..");
            }
            else if (stack[stack.size()-1] != "") {
                stack.pop_back();
            }
        }
        else stack.push_back(token);
    }

    if (stack.size() == 1 || stack.size() == 0) return "/";

    int i = 0;
    ostringstream oss;
    for (auto token: stack) {
        if (i != 0) {
            oss << "/";
        }
        i++;
        oss << token;
    }

    return oss.str();
}

int main(void) {
    string path = "/../x/y/../z/././w/a///../c/./";
    //   x/z/w/c

    cout << simplify(path) << endl;

    return 0;
}