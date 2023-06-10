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
    int pairSum(ListNode* head) {
        ListNode* start = head;
        ListNode* prev = head;
        vector<int> list_val;
        int count = 0;
        while(prev) {
            list_val.push_back(prev->val);
            prev = prev->next;
            count += 1;
        }
        reverse(list_val.begin(), list_val.end() );
        int max_sum = -1, sum = 0;
        for(int i = 0; i < count / 2; i++) {
            sum = list_val[i] + start->val;
            if(sum > max_sum)
                max_sum = sum;
            start = start->next;
        }
        return max_sum;
    }
};