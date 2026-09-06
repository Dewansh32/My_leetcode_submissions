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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int x=0;
        int y=0;

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int size1=0;
        int size2=0;

        while(temp1!=NULL)
        {
            size1++;
            temp1 = temp1->next;
        }

        while(temp2!=NULL)
        {
            size2++;
            temp2 = temp2->next;
        }


        int carry = 0;
        ListNode dummy(0);
        ListNode* head = &dummy;

        while(l1!=NULL || l2!=NULL)
        {
            int val1 = (l1 != NULL) ? l1->val : 0;
            int val2 = (l2 != NULL) ? l2->val : 0;

            int sum = carry + val1 + val2;

            head->next = new ListNode(sum%10);
            carry = sum/10;
            head = head->next;

            if(l1!=NULL)
            {
                l1 = l1->next;
            }
            if(l2!=NULL)
            {
                l2 = l2->next;
            }
        }

        if(carry!=0)
        {
            head->next = new ListNode(carry);
        }
        
        
        return dummy.next;
        
    }
};