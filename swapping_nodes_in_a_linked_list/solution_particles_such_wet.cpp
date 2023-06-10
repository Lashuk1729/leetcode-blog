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
    ListNode* kNodeStart(ListNode* head, int k) {
        int count = 0;
        ListNode* current = head;
        while (count < k-1) {
            count++;
            current = current->next;
        }
        return current;
    }

    ListNode* kNodeEnd(ListNode* head, int k) {
        int count = 0;
        ListNode* current = head;
        
        while (current != NULL) {
            count++;
            current = current->next;
        }

        count = count - k + 1;

        free(current);
        current = head;
        while (count-1) {
            count--;
            current = current->next;
        }
        return current;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* kthStart = kNodeStart(head, k);
        ListNode* kthEnd = kNodeEnd(head, k);

        int temp;
        temp = kthStart->val;
        kthStart->val = kthEnd->val;
        kthEnd->val = temp;
        return head;
    }
};