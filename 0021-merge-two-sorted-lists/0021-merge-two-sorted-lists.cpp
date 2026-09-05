class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* prev = &dummy;

        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }

            prev = prev->next;
        }

        if (list1)
            prev->next = list1;
        else
            prev->next = list2;

        return dummy.next;
    }
};