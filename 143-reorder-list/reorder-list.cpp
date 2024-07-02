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
        if(head == NULL) return NULL;

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* left = head;
        ListNode* fast = head, *slow = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* right = reverseList(slow);
        
        while(left || right){
            if(left){
                ListNode* leftNxt = left->next;
                left->next = right;
                left = leftNxt;
            }
            if(right){
                ListNode* rightNxt = right->next;
                right->next = left;
                right = rightNxt;
            }
        }
    }
};