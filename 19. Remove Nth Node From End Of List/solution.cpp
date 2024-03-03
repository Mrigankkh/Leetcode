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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
     ListNode* penultimate = NULL;
     ListNode* curr = head;
     int currLength = 0;


     while(curr!=NULL)
     {
         if(currLength>=n)
         {
             if(penultimate==NULL)
             penultimate = head;
             else
             penultimate = penultimate->next;
         }
         curr = curr->next;
        currLength++;
     }
     if(penultimate==NULL)
     {
         if(currLength==1)
         return NULL;
         head= head->next;
     }
     else
    { 
       penultimate->next = penultimate->next->next;
    }


    return head;
    }
};