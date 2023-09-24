// https://leetcode.com/problems/odd-even-linked-list/

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *oddhead = NULL, *evenhead = NULL, *oddtail = NULL, *eventail = NULL;
        int x = 1;

        while (head != NULL)
        {
            if (x % 2 == 0)
            {
                if (evenhead == NULL)
                {
                    evenhead = eventail = head;
                    head = head->next;
                }
                else
                {
                    eventail->next = head;
                    eventail = eventail->next;
                    head = head->next;
                }
            }
            else
            {
                if (oddhead == NULL)
                {
                    oddhead = oddtail = head;
                    head = head->next;
                }
                else
                {
                    oddtail->next = head;
                    oddtail = oddtail->next;
                    head = head->next;
                }
            }
            x++;
        }
        if (oddhead == NULL)
            return evenhead;

        if (evenhead == NULL)
            return oddhead;

        eventail->next = NULL;
        oddtail->next = evenhead;

        return oddhead;
    }
};