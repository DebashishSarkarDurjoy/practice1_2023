#include <iostream>
#include <queue>
using namespace std;

int main(void) {
    queue<char> q;
    int freq[27] = {0};

    char ch = ' ';
    do {
        cin >> ch;
        q.push(ch);
        int idx = ch - 'a';

        freq[idx]++;

        while ( !q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (!q.empty()) cout << "--> " << q.front() << endl;
        else cout << "-1" << endl;
    } while (ch != '.');

    return 0;
}