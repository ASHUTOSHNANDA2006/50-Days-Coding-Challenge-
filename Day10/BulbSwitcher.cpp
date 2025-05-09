#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
    public:
        int bulbSwitch(int n) {
            return sqrt(n);
        }
};

int main() {
    Solution solution;
    int n = 10; // Example input
    int result = solution.bulbSwitch(n);
    cout << "Number of bulbs that are on after " << n << " rounds: " << result << endl;
    return 0;
}