class Solution {
public:
 
    string reverseWords(string s) {
       stack<string> st;
       string curr = "";
       for(int i=0;i<s.length();i++)
       {
           if(s[i]!=' ')
           {
               curr +=s[i];
           }
           else
           {
              while(s[i]==' ')
              {
                  ++i;
                  
              }
              
              if(curr!="")
                { 
                    st.push(curr);
                    if(i== s.length())
                    {
                        curr = "";
                        break;
                    }
                
                }
              curr = "";
              curr += s[i];
           }
       } 
       if(curr!="")
      {
           st.push(curr);
            cout<<"Pushed"<< curr<<endl;

           
    }


       s = "";
       while(!st.empty())
       {
           s+=st.top();
           s+=' ';
           st.pop();
       }
       return s.substr(0, s.length()-1);
    }
};