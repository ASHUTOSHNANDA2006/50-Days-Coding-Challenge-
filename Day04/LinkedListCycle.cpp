#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (head == NULL || head->next == NULL)
                return false;
    
            ListNode *slow = head;
            ListNode *fast = head->next;
    
            while (fast != NULL && fast->next != NULL) {
                if (slow == fast)
                    return true;
    
                slow = slow->next;
                fast = fast->next->next;
            }
    
            return false;
        }
};

int main() {
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head; // Create a cycle

    if (solution.hasCycle(head)) {
        cout << "The linked list has a cycle." << endl;
    } else {
        cout << "The linked list does not have a cycle." << endl;
    }

    return 0;
}