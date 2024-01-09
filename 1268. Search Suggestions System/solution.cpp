class Trie{
struct Node{
bool flag = false;
vector<Node *> links{vector<Node *>(26, NULL)};
bool hasKey(char key)
{
    return links[key - 'a'] !=NULL;
}
};
    private:
    Node* root;

    public:


    Trie()
    {
        root = new Node();
    }
vector<string> getWordsWithPrefix(string & prefix)
    {
        vector<string> ans;
        Node *temp = root;
        int currentIndex = 0;
        while(temp->hasKey(prefix[currentIndex])&& currentIndex < prefix.length())
        {
       
            temp = temp->links[prefix[currentIndex] - 'a'];
            currentIndex++;
            if(currentIndex== prefix.length())
            {
                break;
            }
        }
        if(prefix.length()!=currentIndex)
        {
            return {};
        }
        vector<string> result;
         dfs(temp, prefix, result);
         return result;


        // temp is at the end of matched prefix 
        
    }

    void dfs(Node* temp , string  prefix, vector<string>& result)
    {
       
        if(result.size()>=3)
        return ;

        if(temp->flag == true)
        {
            result.push_back(prefix);
        }


        for(int i = 0;i <26;i++)
        {
            if(temp->links[i]!=NULL)
           { 
               dfs(temp->links[i] , prefix + char('a'+ i), result);
     
           }
        }
        return ;
    }

    void insert(string & s)
    {
        Node *temp = root;
        for(auto &ch: s)
        {
            if(temp->hasKey(ch))
            {
                temp = temp->links[ch - 'a'];
            }
            else
            {
                temp->links[ch - 'a'] = new Node();
                temp = temp->links[ch - 'a'];
            }
        }
        temp->flag = true;
    }
};


class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie = Trie();
        for(auto &product : products)
        {
            trie.insert(product);
        }

        vector<vector<string>> ans;
        string prefix = "";
        for(auto &key : searchWord)
        {
            prefix = prefix + key;
      ans.push_back(trie.getWordsWithPrefix(prefix));
        }

        return ans;
    }
};