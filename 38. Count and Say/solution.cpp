class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
        {
            return "1";
        }
        return helper(countAndSay(n-1));
    }

    string helper(string said)
    {
        if(said=="")
        return "";

        char curr = said[0];
        int count  = 1;
        string ans = "";
        for(int i =1;i<said.length();i++)
        {
            if(said[i]!=curr)
            {
                ans+= to_string(count) + curr;
                count = 1;
                curr = said[i];
            }
            else
            {
                count++;
            }
        }

        ans+= to_string(count) + curr;
        return ans;




    }
};