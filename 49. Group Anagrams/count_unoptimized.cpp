class Solution {
public:

    // vector<int> getPattern(string s)
    // {
    //     vector<int> pattern(26,0);
    //     for(auto c : s)
    //     {
    //         pattern[c-97]++;
    //     }
       
    //     cout<<endl;
    //     return pattern;
    // }

   unordered_map<char,int> getPattern(string s)
    {
       unordered_map<char,int> pattern;
        for(auto c : s)
        {
            if(!pattern[c])
            pattern[c] = 1;
            else
            pattern[c]++;
        }
    
        return pattern;
    }
    // bool patternMatch(vector<int> patternA, vector<int> patternB)
    // {
    //     if(patternA.size()!= patternB.size())
    //     return false;
    //     for(int i=0;i<patternA.size();i++)
    //     {
    //         if(patternA[i]!=patternB[i])
    //         return false;
    //     }
    //     return true;
    // }

        bool patternMatch(unordered_map<char,int> patternA, unordered_map<char,int> patternB)
    {
        if(patternA.size()!= patternB.size())
        return false;
        for(auto elem : patternA)
        {
             if(patternB[elem.first]!=patternA[elem.first])
            return false;
        }
        return true;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         vector<vector<string>> ans;
         vector<unordered_map<char,int>> patterns;

        for(int i=0;i<strs.size();i++)
        {  
        bool matched = false;
        unordered_map<char,int> pattern = getPattern(strs[i]);

        
            for( int p=0;p<patterns.size();p++)
            {
                if(patternMatch(pattern,patterns[p]))
                {

                   ans[p].push_back(strs[i]);
                   matched = true;
                   break;
                }
            }
            if(!matched)
            {
                patterns.push_back(pattern);
                ans.push_back({strs[i]});
            }


        }
        return ans;


    }
};