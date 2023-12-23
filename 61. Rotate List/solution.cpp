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


    ListNode* rotateRight(ListNode* head, int k) {
      
       int len = 0;
  
        ListNode* tempL= head;
        while(tempL)
        {
            len++;
            tempL = tempL->next;
        }
        if(len<2)
        return head;
        k = k%len;
        if(k==0)return head;
        int breakPoint = len - k ;
        ListNode* breakNode =  head;
        if(breakPoint<=0)
        return head;
        while(breakPoint!=1)
        {
            breakPoint--;
            breakNode = breakNode->next;
        }
        ListNode* newFirstNode  = breakNode->next;
        breakNode->next = NULL;   
        ListNode* temp = newFirstNode;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
    return newFirstNode;
    }
};