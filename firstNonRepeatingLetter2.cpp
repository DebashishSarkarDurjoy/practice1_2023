#include<bits/stdc++.h>
using namespace std;


vector<char> FindFirstNonRepeatingCharacter(string S){
    queue<char> q;
    int freq[27] = {0};
    vector<char> v;

    for (char ch: S) {
        int idx = ch - 'a';
        freq[idx]++;
        q.push(ch);
    
        while ( !q.empty() && freq[q.front() - 'a'] > 1 ) {
            q.pop();
        }
        
        if (!q.empty()) {
            v.push_back( q.front() );
        }
        else v.push_back( '0' );
    
      
    }
    return v;
}