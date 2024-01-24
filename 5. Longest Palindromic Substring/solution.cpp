class Solution {
public:

   int findLength(string s, int i, int j)
        {
            int ans = 0;
            if(j>=s.length())
            return 0;
            while( i>=0 && j< s.length())
            {
                if(s[i]==s[j] )
             {  
                 if(i==j)
                 ans-=1;
                  i--;
                j++;
                ans+=2;}
                else
                {
                    return ans;
                }
            }

            return ans;
        }

    string longestPalindrome(string s) {
        vector<int> dp(s.length(),1);
        int len = 1;
        int mid = 0;
        for(int i=0;i<s.length();i++)
        {
         
            int newLength = max( findLength(s,i,i) ,  findLength(s,i,i+1));
            if(newLength> len)
            {
                len = newLength;
                mid = i;
            }

            
        }
  
        int midLength = len%2==0?0:1;
        return s.substr(mid - ((len-1)/2),len);



     
    }
};