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
    void print(ListNode* l) {
        ListNode* temp = l;
        while (temp) {
            cout << temp->val << ", ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverseList(ListNode*& aInHead) {
        ListNode* lPrev = NULL;
        ListNode* lNext = NULL;
        while (aInHead) {
            lNext = aInHead->next;
            aInHead->next = lPrev;
            lPrev = aInHead;
            aInHead = lNext;
        }
        aInHead = lPrev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* lPos1 = head;
        ListNode* lPos2 = head;
        while (lPos2->next && lPos2->next->next) {
            lPos1 = lPos1->next;
            lPos2 = lPos2->next->next;
        }
        lPos2 = lPos1->next;
        lPos1->next = NULL;
        lPos1 = head;
        print(lPos2);
        reverseList(lPos2);
        print(lPos2);
        ListNode* lNext1 = NULL;
        ListNode* lNext2 = NULL;
        while (lPos2) {
            lNext1 = lPos1->next;
            lNext2 = lPos2->next;
            lPos1->next = lPos2;
            lPos2->next = lNext1;
            lPos1 = lNext1;
            lPos2 = lNext2;
        }
    }
};
