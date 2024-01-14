class Solution {
public:
    int partitionString(string s) {
        
        int curr = 0;
        int part = 1;
        int ans = 1;
        unordered_map<char,int> umap;
      while(curr <s.length())
      {
          char ch = s[curr];
          if(umap.find(ch)!=umap.end())
          {
              if(umap[ch]== part)
              {
                  ans ++;
                  part++;
                  umap[ch]++;
              }
              else
              {
                   umap[ch] = part;
              }
          }
          else
          {
              umap[ch] = part;
          }

        curr++;
      }
      return ans;
    }
};