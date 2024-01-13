class Solution {
public:

struct compare
 {   bool operator()(vector<int> &p , vector<int> &q){
        return p[1]<q[1];
    }};
    string reorganizeString(string s) {
        
        string ans = "";
        if(s.length()<2)
        return s;
        vector<int> freq(26,0) ;
        priority_queue<vector<int> , vector<vector<int>> , compare> pq;
        for(auto c : s)
        {
            freq[c-'a']++;
        }

        for(int i=0;i< 26;i++)
        {
            if(freq[i]!= 0)
            pq.push({i, freq[i]});
        }
        if(pq.top()[1]> ceil((double)s.length()/2))
        return "";
        else 
        {
        
            while(!pq.empty())
            {
               auto first = pq.top();
               pq.pop();
               char firstChar = char(first[0] + 'a');
               if(ans=="")
               {
                    ans+=firstChar;
                   freq[first[0]]-=1;
               }

               else if(ans.back() != firstChar)
               {
                   ans+=firstChar;
                   freq[first[0]]-=1;
                  
               }
               else
               {
                   auto second = pq.top();
                   pq.pop();
                   char secChar = char(second[0] + 'a');
                    ans+= secChar;
                    freq[second[0]]-=1;
                    if(freq[second[0]]>0)
                    {
                        pq.push({second[0], freq[second[0]]});
                    }


               }
                if(freq[first[0]]>0)
                   {
                       pq.push({first[0], freq[first[0]]});
                   }
               
            }

        }
        return ans;


    


    }
};