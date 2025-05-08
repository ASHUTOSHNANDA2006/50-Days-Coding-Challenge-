#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
    public:
        int findNthDigit(int n) {
            int length = 1;     
            long count = 9;    
            int start = 1;       
    
          
            while (n > length * count) {
                n -= length * count;  
                length++;
                count *= 10;
                start *= 10;
            }
    
            start += (n - 1) / length;
    
            string s = to_string(start);
            return s[(n - 1) % length] - '0'; 
        }
};

int main() {
    Solution solution;
    int n = 11;
    int result = solution.findNthDigit(n);
    cout << "The " << n << "th digit is: " << result << endl;
    return 0;
}