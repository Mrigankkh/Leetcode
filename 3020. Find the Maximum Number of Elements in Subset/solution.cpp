class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<float,int> umap;
        for(auto num : nums)
        {
            if(umap.find(num)!=umap.end())
                umap[num]++;
            else
                umap[num] = 1;
        }
    int ans = 1;
        
        
        if(umap.find(1)!=umap.end())
        {
            if(umap[1]%2==0)
            ans = umap[1]-1;
            else
            ans = umap[1];
        }
        for(auto num2: nums)
        {
            if(num2==1)
            continue;
            int num = num2;
           
            int tempAns = 1;
            while(tempAns<nums.size() && umap.find(pow(num,0.5))!=umap.end())
            {               
                    if(umap[pow(num,0.5)]>=2)
                    {
                        
                        tempAns+=2;
                        num = pow(num,0.5);
                        continue;
                    }
                
                break;
                
                
            }
            
            ans = max(ans, tempAns);
               
        }
        return ans;
    }
};