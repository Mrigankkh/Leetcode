struct compare{

    bool operator()(pair<int,char> &p,pair<int,char> &q)
    {
        return p.first<q.first;
    }
};
class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int> umap;
        for(auto c:s)
        {
            if(umap.find(c)==umap.end())
            umap[c] = 1;
            else
            umap[c]++;
        }      

        priority_queue<pair<int,char> , vector<pair<int,char>> , compare> pq;

        for(auto elem : umap)
        {
            pq.push({elem.second, elem.first});
        }

        while(!pq.empty())
        {
            auto ch = pq.top().second;
            auto freq = pq.top().first;

            pq.pop();

            for(int i=0;i<freq;i++)
            {
                ans+=ch;
            }


        }

        return ans;
    }
};