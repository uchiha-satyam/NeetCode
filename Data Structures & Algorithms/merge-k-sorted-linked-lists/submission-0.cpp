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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        set<pair<int, ListNode*>> lRecord;
        ListNode* lHead = nullptr;
        ListNode* lCurr = nullptr;
        for (auto& lNode : lists) {
            if (lNode) {
                lRecord.insert({lNode->val, lNode});
                lNode = lNode->next;
            }
        }
        while (!lRecord.empty()) {
            auto lIt = lRecord.begin();
            if (lHead) {
                lCurr->next = lIt->second;
                lCurr = lCurr->next;
            }
            else {
                lHead = lCurr = lIt->second;
            }
            ListNode* lTemp = lCurr->next;
            lCurr->next = NULL;
            lRecord.erase(lIt);
            if (lTemp) {
                lRecord.insert({lTemp->val, lTemp});
            }
        }
        return lHead;
    }
};
