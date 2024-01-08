struct Node {

    bool flag = false;
    Node* links[26];

    bool hasKey(char key)
    {
        return links[key - 'a']!= NULL;
    }

};
class Trie {

private:
Node* root;
    
public:

    Trie() {
      root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(auto key : word)
        {
     
            if(temp->hasKey(tolower(key)))
            {
                temp = temp->links[tolower(key) - 'a'];
            }
            else
            {
                temp->links[tolower(key) - 'a'] = new Node();
                temp = temp->links[tolower(key) - 'a'];
                temp->flag = false;
            }
        }
        temp->flag = true;


    }
    
    bool search(string word) {
        int currentIndex = 0;
        Node* temp = root;
        while(temp->hasKey(tolower(word[currentIndex])) && currentIndex< word.length())
        {
            temp = temp->links[tolower(word[currentIndex])-'a'];
            currentIndex++;
            if(currentIndex>= word.length())
                break;
        }
            cout<<word[currentIndex]<<endl;
        return temp->flag== true && currentIndex==word.length();


    }
    
    bool startsWith(string prefix) {
    int currentIndex = 0;
        Node* temp = root;
        while(temp->hasKey(tolower(prefix[currentIndex]) ) && currentIndex< prefix.length())
        {
            temp = temp->links[tolower(prefix[currentIndex])-'a'];
            currentIndex++;
                     if(currentIndex>= prefix.length())
                break;
        }

        return prefix.length() == currentIndex;
return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */