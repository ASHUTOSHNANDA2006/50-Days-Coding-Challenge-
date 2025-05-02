#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        bool checkPerfectNumber(int num) {
            int sum = 0;
            for(int i=1; i<=num; i++)
            {
                if(num%i==0)
                {
                    sum += i;
                }
            }
            sum = sum - num;
            if(sum==num)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    };

int main() {
    Solution s;
    int num = 28;
    if (s.checkPerfectNumber(num)) {
        cout << num << " is a perfect number." << endl;
    } else {
        cout << num << " is not a perfect number." << endl;
    }
    return 0;
}