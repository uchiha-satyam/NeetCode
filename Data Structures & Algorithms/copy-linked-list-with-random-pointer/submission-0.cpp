/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* lNewHead = NULL;
        Node* lCurr = head;
        Node* lNewCurr = lNewHead;
        unordered_map<Node*, Node*> lMap;
        while (lCurr) {
            lNewCurr = new Node(lCurr->val);
            lMap[lCurr] = lNewCurr;
            lCurr = lCurr->next;
        }
        lCurr = head;
        lNewHead = lMap[head];
        while (lCurr) {
            if (lCurr->next) {
                lMap[lCurr]->next = lMap[lCurr->next];
            }
            if (lCurr->random) {
                lMap[lCurr]->random = lMap[lCurr->random];
            }
            lCurr = lCurr->next;
        }
        return lNewHead;
    }
};
