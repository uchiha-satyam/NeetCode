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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* lStart = head;
        ListNode* lEnd = head;
        while (lEnd->next) {
            if (n == 0) {
                lStart = lStart->next;
            }
            else {
                n--;
            }
            lEnd = lEnd->next;
        }
        if (!lStart->next) {
            return NULL;
        }
        if (n) {
            head = head->next;
            lStart->next = NULL;
            return head;
        }
        lEnd = lStart->next->next;
        lStart->next->next = NULL;
        lStart->next = lEnd;
        return head;
    }
};
