struct compare{

    bool operator()(int &p, int &q)
    {
        return p<q;
    }
};
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> , compare> pq;

        for(auto num : nums)
        pq.push(num);
        int curr = INT_MIN;

        while(k>0)
        {
            k--;

            curr = pq.top();
            pq.pop();
            cout<<curr<<endl;
        }
        return curr;


    }
};

// Count sort can also be used.