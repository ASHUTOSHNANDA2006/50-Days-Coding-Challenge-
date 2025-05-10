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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
  
        ListNode* nodeToDelete = slow->next;
        slow->next = nodeToDelete->next;
        delete nodeToDelete;
        
        return dummy.next;
    }
};

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    int n = 2;

    Solution solution;
    ListNode* modifiedHead = solution.removeNthFromEnd(head, n);

    ListNode* current = modifiedHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    current = modifiedHead;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}