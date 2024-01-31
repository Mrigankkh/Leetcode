class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans (temperatures.size(),0);

        stack<pair<int,int>> st;
        for(int i=0;i<temperatures.size();i++)
        {

            if(st.empty())
            {
                st.push({i, temperatures[i]});
                continue;
            }
            auto top = st.top();
            while(temperatures[i]> top.second && !st.empty())
            {
                st.pop();
                ans[top.first] = i - top.first; 
                if(!st.empty())
                top = st.top();

                
            }
           
              st.push({i, temperatures[i]});
            
        }
        return ans;
    }
};