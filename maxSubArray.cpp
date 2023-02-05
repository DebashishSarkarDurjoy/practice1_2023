#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> maxSubArray(vector<int> &numbers, int k) {
    deque<int> Q(k);
    vector<int> result;
    
    int i = 0;
    for (; i < k; i++) {
        while (!Q.empty() && numbers[i] > numbers[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }

    for (; i < numbers.size(); i++) {
        result.push_back(numbers[Q.front()]);
        while (!Q.empty() && Q.front() <= i-k) {
            Q.pop_front();
        }
        while (!Q.empty() && numbers[i] > numbers[Q.back()]) {
            Q.pop_back();
        }
        Q.push_back(i);
    }
    return result;
}

int main(void) {
    vector<int> numbers = {1,2,3,1,4,5,2,3,5};
    vector<int> num;
    num = maxSubArray(numbers, 3);
    
    for (int n: num) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}