#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
    public:
        int titleToNumber(string columnTitle) {
            int result = 0;
            for (char c : columnTitle) {
                result = result * 26 + (c - 'A' + 1);
            }
            return result;
        }
};

int main() {
    Solution solution;
    string columnTitle = "ABCD"; // Example input
    int result = solution.titleToNumber(columnTitle);
    cout << "The column number for " << columnTitle << " is: " << result << endl;
    return 0;
}