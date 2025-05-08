#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
    public:
        ListNode* swapNodes(ListNode* head, int k) {
            ListNode* first = head;
            
            for (int i = 1; i < k; i++) {
                first = first->next;
            }
            
            ListNode* kthFromStart = first;
    
            ListNode* second = head;
            while (first->next != nullptr) {
                first = first->next;
                second = second->next;
            }
            
            ListNode* kthFromEnd = second;
    
            swap(kthFromStart->val, kthFromEnd->val);
            
            return head;
        }
};

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 2;
    
    Solution solution;
    ListNode* result = solution.swapNodes(head, k);

    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    
    return 0;
}