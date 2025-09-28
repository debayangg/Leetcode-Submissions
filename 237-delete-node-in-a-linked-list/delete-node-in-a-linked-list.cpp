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
    void deleteNode(ListNode* node) {
        ListNode* tmp = node->next;
        ListNode* prev = node;
        node->val=node->next->val;
        while(tmp->next!=nullptr)
        {
            tmp->val = tmp->next->val;
            prev=prev->next;
            tmp = tmp->next;
        }
        delete tmp;
        prev->next=nullptr;
    }
};