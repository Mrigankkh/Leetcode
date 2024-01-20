class Solution {
public:
    int pathSum(vector<int>& nums) {
        vector<int> trueVal(16,-1);
        unordered_map<int,int> umap;

        for(auto n : nums)
        umap[(n - n%10)/10] = n%10;
        vector<vector<int>> mat(5, vector<int>(9,0));
   for(int i=4;i>=1;i--)
   {
       for(int j = 2*i ; j>0 ; j-- )
       {


           //Currently at depth i, level j
           if(umap.find(i*10 + j)!=umap.end())
           {
               
               
               // Increment parent which is at 2* i-1 + j
              if(mat[i][j]==0)
              mat[i][j]++;
              if(i==1 && j ==1)
              break;
              mat[i-1][(j+1)/2]+=mat[i][j];
           }
       }
   }

int ans = 0;
   for(int i=4;i>=1;i--)
   {
       for(int j = 2*i ; j>0 ; j-- )
       {
           ans+= mat[i][j] * umap[i*10 + j];
       }


   }
      return ans;
    }
};

