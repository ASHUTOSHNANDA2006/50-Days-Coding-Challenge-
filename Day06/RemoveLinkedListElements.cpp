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
        ListNode* removeElements(ListNode* head, int val) {
            // Create a dummy node before the head to handle edge cases easily
            ListNode* dummy = new ListNode(0);
            dummy->next = head;
    
            ListNode* current = dummy;
            while (current->next != nullptr) {
                if (current->next->val == val) {
                    // Skip the node with the target value
                    ListNode* temp = current->next;
                    current->next = current->next->next;
                    delete temp; // optional: free memory
                } else {
                    current = current->next;
                }
            }
    
            ListNode* newHead = dummy->next;
            delete dummy; // clean up dummy node
            return newHead;
        }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(6, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6)))))));
    int val = 6;
    
    Solution solution;
    ListNode* modifiedHead = solution.removeElements(head, val);
    
    // Print the modified list
    ListNode* current = modifiedHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    
    // Clean up memory (not shown here for brevity)
    
    return 0;
}