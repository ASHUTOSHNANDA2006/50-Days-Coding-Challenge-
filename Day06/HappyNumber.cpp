#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool isHappy(int n) {
            auto getNext = [](int num) {
                int totalSum = 0;
                while (num > 0) {
                    int digit = num % 10;
                    totalSum += digit * digit;
                    num /= 10;
                }
                return totalSum;
            };
    
            int slow = n;
            int fast = getNext(n);
    
            while (fast != 1 && slow != fast) {
                slow = getNext(slow);
                fast = getNext(getNext(fast));
            }
    
            return fast == 1;
        }
};

int main() {
    Solution solution;
    int n = 19; // Example input
    if (solution.isHappy(n)) {
        cout << n << " is a happy number." << endl;
    } else {
        cout << n << " is not a happy number." << endl;
    }
    return 0;
}