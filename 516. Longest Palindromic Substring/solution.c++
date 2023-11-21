class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()<1)
        return "";
        int end = 0;
        int start = 0;
for(int i=0;i< s.length();i++)
{
    int l1 = solve(s,i,i);
    int l2 = solve(s,i,i+1);
    int l = max(l1,l2);
    if(l> end-start )
    {
     start = i - ((l-1)/2);
     end = i+ ((l)/2);
    }
}
    return s.substr(start , end- start+1 );

    }

    int solve(string s, int i , int j)
    {
        while(i>=0 && j < s.length() && s[i]==s[j])
        {

            i--;
            j++;
        }
        return j-i - 1;
    }
};