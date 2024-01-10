class Solution {
public:
string s1,s2;
bool lex(char a, char b)
{
    return a==b|| (a=='z' && b=='a') || b-a ==1;
    
}
    bool helper(int i, int j)
    {
       
        if(j==s2.length())
        {
            return true;
        }
        if(i == s1.length())
        {
            return false;
        }
 while(i<s1.length() && j<s2.length())
        {
            if(lex(s1[i], s2[j]))
            {
                
                return helper(++i, ++j);
            }
            else
            {
                i++;
            }
        }
                       return false;


    }
    bool canMakeSubsequence(string str1, string str2) {
        s1 = str1;
        s2 = str2;
        return helper(0,0);
       
       

    }
};