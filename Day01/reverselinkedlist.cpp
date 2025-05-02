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
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while (curr) {
                ListNode* nextTemp = curr->next;
                curr->next = prev; 
                prev = curr;
                curr = nextTemp; 
            }
            return prev;
        }
    };

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    ListNode* current = reversedHead;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}