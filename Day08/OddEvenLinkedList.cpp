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
        ListNode* oddEvenList(ListNode* head) {
            if (!head || !head->next) return head;
    
            ListNode* odd = head;
            ListNode* even = head->next;
            ListNode* evenHead = even;
    
            while (even && even->next) {
                odd->next = even->next;
                odd = odd->next;
    
                even->next = odd->next;
                even = even->next;
            }
    
            odd->next = evenHead;
            return head;
        }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution solution;
    ListNode* result = solution.oddEvenList(head);
    
    // Print the result
    while (result) {
        cout << result->val << " ";
        result = result->next;
    }
    
    return 0;
}