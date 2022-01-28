//https://leetcode.com/problems/palindrome-linked-list/

/*
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
*/

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
    bool isPalindrome(ListNode* head) {
        if(head==NULL) return true;
        ListNode *fast=head,*slow=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        stack <int>st;
        while(slow!=NULL){
            st.push(slow->val);
            slow=slow->next;
        }
        ListNode* temp=head;
        while(!st.empty()){
            if(st.top()==temp->val){
                st.pop();
                temp=temp->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
