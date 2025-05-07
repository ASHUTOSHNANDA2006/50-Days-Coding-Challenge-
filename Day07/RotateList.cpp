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
        ListNode* rotateRight(ListNode* head, int k) {
            if (!head || !head->next || k == 0) return head;
    
            // Step 1: Compute the length of the list and get the tail node
            int length = 1;
            ListNode* tail = head;
            while (tail->next) {
                tail = tail->next;
                length++;
            }
    
            // Step 2: Normalize k (as rotating by length results in the same list)
            k = k % length;
            if (k == 0) return head;
    
            // Step 3: Connect tail to head to make it a circular list
            tail->next = head;
    
            // Step 4: Find new tail: (length - k - 1)th node
            ListNode* newTail = head;
            for (int i = 0; i < length - k - 1; i++) {
                newTail = newTail->next;
            }
    
            // Step 5: Set new head and break the circle
            ListNode* newHead = newTail->next;
            newTail->next = nullptr;
    
            return newHead;
        }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int k = 2;
    
    Solution solution;
    ListNode* rotatedHead = solution.rotateRight(head, k);
    
    // Print the rotated list
    ListNode* current = rotatedHead;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    
    return 0;
}