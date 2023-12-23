class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> umap;
        for(auto word : strs)
        {
            string original = word;
            sort(word.begin(),word.end());
            umap[word].push_back(original);
        }
        vector<vector<string>> ans;
        for(auto x :umap)
        {
            ans.push_back(x.second);
        }
        return ans;


    }
};              