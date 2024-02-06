class Solution {
public:
int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int hScore = 0;
        int len = citations.size();
        for(int i=0;i<len;i++)
        {
            if(citations[i]==0)
            continue;

            if((len - i) >= citations[i])
            {
                hScore  = citations[i];
            }
            else
            {
                hScore = max(hScore , min(len - i , citations[i]) );
            }
        }
        return hScore;
    }
};