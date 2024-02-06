class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<string,char> umap;
        unordered_map<char,bool> seen;
        vector<string> words;
        string word = "";
        for(auto c: s)
        {
            if(c==' ')
            {
                cout<<word<<endl;
                words.push_back(word);
                word = "";
            }
            else
            {
                word+=c;
            }
        }
          cout<<word<<endl;
         words.push_back(word);
        if(words.size()!=pattern.length())
        return false;
       for(int i=0;i< pattern.length();i++)
       {
           if(umap.find(words[i])== umap.end())
           {
               if(seen.find(pattern[i])!=seen.end())
               return false;
               seen[pattern[i]] = true;
               umap[words[i]] = pattern[i];
           }
           else
           {
               if(umap[words[i]] != pattern[i])
               return false;
           }
       }

       return true;
    }
};