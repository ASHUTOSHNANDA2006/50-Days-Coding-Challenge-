#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        int addDigits(int num) {
            if (num < 10) {
                return num;
            }
            else {
                int sum = 0;
                while (num > 0) {
                    sum += num % 10;
                    num /= 10;
                }
                return addDigits(sum);
            }
        }
};

int main() {
    Solution solution;
    int num = 38;
    int result = solution.addDigits(num);
    cout << "The result is: " << result << endl;
    return 0;
}