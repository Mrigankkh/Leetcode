struct Node{
    bool flag = false;
    Node* links[26];
    bool hasKey(char key)
    {
        return links[tolower(key)- 'a']!=NULL;
    }
};

class Trie{

    private: Node* root;
    public:
    Trie()
    {
        root = new Node();
    }

    bool allTrue(string word)
    {
        Node* temp = root;
        for(auto key : word)
        {
            if(temp->hasKey(key))
            {
                temp = temp->links[tolower(key)- 'a' ];
                if(temp->flag== false)
                return false;
            }
   
        }
       return true;
    }
    void insert(string word)
    {
        Node* temp = root;
        for(auto key : word)
        {
            if(temp->hasKey(key))
            {
                temp = temp->links[tolower(key)- 'a' ];
            }
            else
            {
                temp->links[tolower(key)- 'a' ] = new Node();
                temp = temp->links[tolower(key)- 'a' ];

            }
        }
        temp->flag = true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        string ans = "";
        // First we insert all the words in a trie.
        Trie trie ;
        for(auto word: words)
        {
            trie.insert(word);
        }

        for(auto word:words)
        {
            if(trie.allTrue(word))
            {
              ans =  ans.length()>word.length()? ans: (ans.length()==word.length()? (ans<word?ans: word) : word);
            }
        }

        return ans;
    }
};