// https://leetcode.com/problems/merge-two-sorted-lists/

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *list3 = new ListNode(0);
        ListNode *head = list3;
        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                list3->next = new ListNode(list2->val);
                list2 = list2->next;
            }
            else
            {
                list3->next = new ListNode(list1->val);
                list1 = list1->next;
            }
            list3 = list3->next;
        }
        while (list1)
        {
            list3->next = new ListNode(list1->val);
            list3 = list3->next;
            list1 = list1->next;
        }
        while (list2)
        {
            list3->next = new ListNode(list2->val);
            list3 = list3->next;
            list2 = list2->next;
        }
        return head->next;
    }
};