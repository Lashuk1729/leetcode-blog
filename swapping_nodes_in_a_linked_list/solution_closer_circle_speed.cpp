/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* node = head;
        ListNode* second = head;
        int count = 1, temp;

        while(count < k) {
            count += 1;
            first = first->next;
            node = node->next;
        }

        while(node->next) {
            node = node->next;
            second = second->next;
        }

        temp = first->val;
        first->val = second->val;
        second->val = temp;
        return head;
    }
};