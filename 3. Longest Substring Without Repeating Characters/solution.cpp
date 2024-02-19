class Solution {
public:
    bool cond(unordered_map<char, int> lastSeen , char ch, int i)
    {
        if(lastSeen.find(ch)== lastSeen.end())
        return true;
        if(lastSeen[ch] < i)
        return true;
        return false;
    }

    int lengthOfLongestSubstring(string s) {
        if(s=="")
        return 0;
        
        unordered_map<char, int> lastSeen;

        int ans  =1;
        int curr = 0;
        int i = 0, j = 0;
        while(j<s.length())
        {
            
            while(cond(lastSeen , s[j] , i) && j<s.length() )
            {
                lastSeen[s[j]] = j;
                curr++;
                j++;
            }
            ans = max(ans,curr);
            if(j>=s.length())
            break;
            i = lastSeen[s[j]]+1;
            curr = j-i;


        }
        return ans;
    }
};