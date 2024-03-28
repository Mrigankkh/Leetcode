class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        return  slidingWindowSolution(nums,  k);
    }


    int slidingWindowSolution(vector<int>& nums, int k)
    {
        int currLength = 0;
        int start = 0;
        int end = 0;
        int maxLength = 0;
        unordered_map<int,int> freq;

        for(int i=0;i< nums.size();i++)
        {
            if(freq.find(nums[i])!=freq.end())
            {
                // Found
                if(freq[nums[i]]< k)
                {
                    // No violation of good subarray rule
                    end++;
                    freq[nums[i]]+=1;
                    currLength++;
                    continue;
                }
                else
                {
                        maxLength = max(maxLength, currLength);
                        //Subarray rule violated.
                        while( nums[start]!=nums[i])
                        {
                            freq[nums[start]]--;
                            start++;
                            currLength--;
                        }
                        start++;
                        end++;
                        // currLength--;

                        
                }

            }
            else
            {
                 currLength++;
                 freq[nums[i]] = 1;

            }

            cout<<"Cuurr Length is: "<<currLength<<endl;
        }
                    return max(maxLength, currLength);

    }
};