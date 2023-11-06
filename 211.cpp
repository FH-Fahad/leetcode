// https://leetcode.com/problems/design-add-and-search-words-data-structure/

class WordDictionary
{
    struct Node
    {
        char c;
        int end;
        Node *children[26];
    };

    Node *getNode(char c)
    {
        Node *current = new Node;
        current->c = c;
        current->end = 0;
        for (int i = 0; i < 26; ++i)
            current->children[i] = NULL;
        return current;
    }

    Node *root = getNode('/');

    void Trie_insert(string s)
    {
        int index;
        int i = 0;
        Node *current = root;
        while (s[i])
        {
            index = s[i] - 'a';
            if (!current->children[index])
                current->children[index] = getNode(s[i]);
            current = current->children[index];
            i++;
        }
        current->end += 1;
    }

    bool Trie_search(string s, Node *current, int pos, int n)
    {
        if (s[pos] == '.')
        {
            bool res = false;
            Node *current1 = current;
            for (int i = 0; i < 26; ++i)
            {
                if (pos == n - 1 && current->children[i])
                {
                    current1 = current->children[i];
                    res |= current1->end > 0 ? true : false;
                }
                else if (current->children[i] && Trie_search(s, current->children[i], pos + 1, n))
                    return true;
            }
            return res;
        }
        else if (current->children[s[pos] - 'a'])
        {
            if (pos == n - 1)
            {
                current = current->children[s[pos] - 'a'];
                return current->end > 0 ? true : false;
            }
            return Trie_search(s, current->children[s[pos] - 'a'], pos + 1, n);
        }
        return false;
    }

public:
    WordDictionary()
    {
    }

    void addWord(string word)
    {
        Trie_insert(word);
    }

    bool search(string word)
    {
        return Trie_search(word, root, 0, word.size());
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */