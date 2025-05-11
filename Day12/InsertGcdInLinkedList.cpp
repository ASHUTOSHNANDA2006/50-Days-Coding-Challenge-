#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countOdds(int low, int high) {
        int count = 0;
        for(int i = low; i<=high; i++)
        {
            if(i%2!=0)
            {
                count++;
            }
            else
            {
                continue;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    int low = 3, high = 7;
    cout << "Count of odd numbers between " << low << " and " << high << " is: " << solution.countOdds(low, high) << endl;
    return 0;
}