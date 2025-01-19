// https://leetcode.com/problems/copy-list-with-random-pointer/

class Solution
{
    unordered_map<Node *, Node *> map;

public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;

        if (map.find(head) != map.end())
            return map[head];

        Node *newNode = new Node(head->val);
        map[head] = newNode;
        newNode->next = copyRandomList(head->next);
        newNode->random = copyRandomList(head->random);

        return newNode;
    }
};