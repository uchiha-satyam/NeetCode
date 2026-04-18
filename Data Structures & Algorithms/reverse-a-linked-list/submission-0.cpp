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
    ListNode* reverseList(ListNode* head) {
        ListNode* lPrev = NULL;
        ListNode* lCurr = head;
        while (lCurr) {
            head = head->next;
            lCurr->next = lPrev;
            lPrev = lCurr;
            lCurr = head;
        }
        return lPrev;
    }
};
