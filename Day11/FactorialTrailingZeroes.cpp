#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            n /= 5;
            count += n;
        }
        return count;
    }
};

int main() {
    Solution solution;
    int n = 100;
    cout << "The number of trailing zeroes in " << n << "! is: " << solution.trailingZeroes(n) << endl;
    return 0;
}