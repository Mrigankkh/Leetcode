class Solution {
public:
    int reverse(int x) {
        int minus = 1;
        if(x<0)
        {
            minus = -1;
        }
        string s = to_string(x);
        int ans ;
        std::reverse(s.begin(),s.end());
        try{
            ans = stoi(s);
            return minus*stoi(s);
        }
        catch(std:: out_of_range)
        {
            return 0;
        }
  
        return 0;
    }
};