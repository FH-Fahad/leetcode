// https://leetcode.com/problems/clone-graph/

class Solution
{
    unordered_map<Node *, Node *> map;

public:
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        if (map.find(node) == map.end())
        {
            Node *newNode = new Node(node->val);
            map[node] = newNode;
            for (Node *neighbor : node->neighbors)
            {
                newNode->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return map[node];
    }
};
