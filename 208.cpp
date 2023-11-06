// https://leetcode.com/problems/implement-trie-prefix-tree/

class Trie
{
public:
    struct Node
    {
        char c;
        bool isWord;
        Node *children[26];

        Node(char c) : c(c), isWord(false)
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
        }
    };

    Node *root;

    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *current = root;
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            if (current->children[c - 'a'] == nullptr)
                current->children[c - 'a'] = new Node(c);

            current = current->children[c - 'a'];
        }
        current->isWord = true;
    }

    bool search(string word)
    {
        Node *node = getNode(word);
        return node != nullptr && node->isWord;
    }

    bool startsWith(string prefix)
    {
        return getNode(prefix) != nullptr;
    }

    Node *getNode(string word)
    {
        Node *current = root;
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            if (current->children[c - 'a'] == nullptr)
                return nullptr;

            current = current->children[c - 'a'];
        }
        return current;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */