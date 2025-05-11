#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* current = head;
        
        while (current != nullptr && current->next != nullptr) {
            int gcdVal = std::gcd(current->val, current->next->val);
            ListNode* newNode = new ListNode(gcdVal);

            newNode->next = current->next;
            current->next = newNode;

            current = newNode->next;
        }        
        return head;
    }
};

int main() {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(6);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    
    Solution solution;
    ListNode* modifiedHead = solution.insertGreatestCommonDivisors(head);

    ListNode* current = modifiedHead;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    
    return 0;
}