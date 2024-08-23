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
        if(head==NULL or head->next==NULL) return head;
        ListNode* nnext=NULL;
        ListNode* prev=NULL;
        ListNode* curr=head;
        while(curr!=NULL){
            nnext=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nnext;
        }
        return prev;
    }

    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if (head==NULL || head->next==NULL || l==r) return head;
        
        ListNode* temp=new ListNode(-1); 
        temp->next=head;
        ListNode* preLeft=temp;
        
        for(int i=1; i<l; i++){
            preLeft=preLeft->next;
        }
        ListNode* left=preLeft->next;
        ListNode* right=left;
        
        for(int i=l; i<r; i++){
            right=right->next;
        }
        ListNode* postRight=right->next;
        right->next=NULL; 
        
        preLeft->next=reverseList(left);
        left->next=postRight; 
        
        ListNode* newHead=temp->next;
        return newHead;
    }
};