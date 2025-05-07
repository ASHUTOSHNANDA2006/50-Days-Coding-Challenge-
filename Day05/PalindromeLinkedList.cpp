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
        bool isPalindrome(ListNode* head) {
            if (!head || !head->next) return true;
    
            // Step 1: Find the middle (slow will point to middle)
            ListNode* slow = head;
            ListNode* fast = head;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
    
            // Step 2: Reverse the second half
            ListNode* prev = nullptr;
            while (slow) {
                ListNode* nextNode = slow->next;
                slow->next = prev;
                prev = slow;
                slow = nextNode;
            }
    
            // Step 3: Compare both halves
            ListNode* firstHalf = head;
            ListNode* secondHalf = prev;
            while (secondHalf) {
                if (firstHalf->val != secondHalf->val) return false;
                firstHalf = firstHalf->next;
                secondHalf = secondHalf->next;
            }
    
            return true;
        }
};

int main() {
    // Example usage:
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(2, new ListNode(1))));
    Solution solution;
    cout << (solution.isPalindrome(head) ? "true" : "false") << endl; // Output: true

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}