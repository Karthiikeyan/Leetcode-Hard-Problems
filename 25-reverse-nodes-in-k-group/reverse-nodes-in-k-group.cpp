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
private:
    ListNode* getKthNode(ListNode* node, int k){
        ListNode* curr = node;
        while(curr && k){
            curr = curr->next;
            k--;
        }
        return curr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = new ListNode(0, head);
        ListNode* groupPrev = temp;

        while(true){
            ListNode* KthNode = getKthNode(groupPrev, k);
            if(KthNode==NULL) break;
            ListNode* groupNext = KthNode->next;

            ListNode* prev = KthNode->next;
            ListNode* curr = groupPrev->next;
            while(curr!=groupNext){
                ListNode* val = curr->next;
                curr->next = prev;
                prev = curr;
                curr = val;
            }

            ListNode* val = groupPrev->next;
            groupPrev->next = KthNode;
            groupPrev = val;
        }
        return temp->next;
    }
};