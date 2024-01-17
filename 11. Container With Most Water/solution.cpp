class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0, i = 0, j = height.size()-1;
        while(i<j)
        {
            ans = max(ans , (int)(min(height[j] ,height[i])*( j-i)));
            height[i]> height[j]? j-- : i++;
           
        }
        return ans;
    }
};