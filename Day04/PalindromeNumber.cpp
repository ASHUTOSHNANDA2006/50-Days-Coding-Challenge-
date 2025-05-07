#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false;
    
            int rev = 0;
            int temp = x;
            while (temp != 0) {
                int ld = temp % 10;
    
                if (rev > (INT_MAX - ld) / 10) {
                    return false;
                }
    
                rev = rev * 10 + ld;
                temp = temp / 10;
            }
            return (rev == x);
        }
};

int main() {
    Solution solution;
    int x = 121;
    if (solution.isPalindrome(x)) {
        cout << x << " is a palindrome." << endl;
    } else {
        cout << x << " is not a palindrome." << endl;
    }
    return 0;
}