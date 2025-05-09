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
        ListNode* deleteMiddle(ListNode* head) {
            if (!head || !head->next) return nullptr;
    
            ListNode* slow = head;
            ListNode* fast = head;
            ListNode* prev = nullptr;
    
            while (fast && fast->next) {
                prev = slow;
                slow = slow->next;
                fast = fast->next->next;
            }
    
            prev->next = slow->next;
            delete slow;
    
            return head;
        }
};

int main() {    
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution solution;
    ListNode* modifiedHead = solution.deleteMiddle(head);

    ListNode* current = modifiedHead;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }    
    return 0;
}