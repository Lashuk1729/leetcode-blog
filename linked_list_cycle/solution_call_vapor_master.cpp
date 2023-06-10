/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        // ListNode *slow = head, *fast = head;
        // while(slow != 0 && fast != 0 && fast->next != 0)
        // {
        //     slow = slow->next;
        //     fast = fast->next->next;
        //     if(slow == fast)
        //         return true;
        // }
        // return false;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
};