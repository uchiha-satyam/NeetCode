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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int lRem = 0;
        ListNode* lPos1 = l1;
        ListNode* lPos2 = l2;
        ListNode* lHead = NULL;
        ListNode* lCurr = NULL;
        ListNode* lPrev = NULL;
        while (l1 || l2 || lRem) {
            if (l1) {
                lRem += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                lRem += l2->val;
                l2 = l2->next;
            }
            lCurr = new ListNode(lRem%10);
            if (!lHead) {
                lHead = lCurr;
            }
            if (lPrev) {
                lPrev->next = lCurr;
            }
            lPrev = lCurr;
            lRem /= 10;
        }
        return lHead;
    }
};
