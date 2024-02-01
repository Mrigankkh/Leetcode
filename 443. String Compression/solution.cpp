class Solution {
public:

    vector<char> getStream(int a)
    {
        string s = to_string(a);

        vector<char> ans;
        for(auto c : s)
             ans.push_back(char(c));
        return ans;
    
    }

    int compress(vector<char>& chars) {
        
        char curr = chars[0];
        int currLength = 1;
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i] !=curr )
            {
                if(currLength>1)
                {
                    vector<char> soc = getStream(currLength);
                    for(auto c : soc)
                    {    
                         chars.insert(chars.begin() + i++ , c);
                    }
                }

                currLength = 1;
                curr = chars[i];
                continue;
            }

            else
            {
                currLength++;
                chars.erase(chars.begin() + i);
                i--;

            }
        
        }
           
        if(currLength>1)
        {
            vector<char> soc = getStream(currLength);
            for(auto c : soc)
            {     
                chars.push_back(c);}
            }
            
        return chars.size();
    }
};