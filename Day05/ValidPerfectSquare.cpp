#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool isPerfectSquare(int num) {
            if (num < 1) return false;
    
            long long left = 1, right = num;
            while (left <= right) {
                long long mid = left + (right - left) / 2;
                long long square = mid * mid;
    
                if (square == num) return true;
                else if (square < num) left = mid + 1;
                else right = mid - 1;
            }
            return false;
        }
};

int main() {
    Solution solution;
    int num = 16; // Example input
    if (solution.isPerfectSquare(num)) {
        cout << num << " is a perfect square." << endl;
    } else {
        cout << num << " is not a perfect square." << endl;
    }
    return 0;
}

