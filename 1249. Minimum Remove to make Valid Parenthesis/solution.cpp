class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        for(int i=1;i<=s.length();i++)
        {

            if(s[i-1]== '(')
            {
               
                st.push(-i);
            }
            else if(s[i-1]== ')')
            {
                if(st.empty())
                {
                    st.push(i);
                }
                else if(st.top()< 0)
                {
                    st.pop();
                }
                else
                {
                    st.push(i);
                }
            }
        }
        while(!st.empty())
        {
            s[fabs(st.top())-1] = '#';
            st.pop();
        }
        string ans = "";
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='#')
            ans.push_back(s[i]);
        }
      // Empty the stack to avoid MLE
        return ans;
    }
};