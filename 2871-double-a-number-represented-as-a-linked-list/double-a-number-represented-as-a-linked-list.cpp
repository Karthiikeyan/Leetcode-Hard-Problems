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
    ListNode* doubleIt(ListNode* head) {
        vector<int> v;
        ListNode* temp = head;
        while(head!=NULL){
            v.push_back(head->val);
            head = head->next;
        }
        int n = v.size();
        long long carry = 0;
        long long val, sum;

        temp = NULL;
        for(int i=n-1;i>=0;i--){
            sum = 2*v[i] + carry;
            val = sum%10;
            ListNode* prev = new ListNode(val);
            prev->next = temp;
            temp = prev;
            carry = sum/10;
        }
        while(carry){
            val = carry%10;
            carry/=10;
            ListNode* prev = new ListNode(val);
            prev->next = temp;
            temp = prev;
        }
        return temp;
    }
};