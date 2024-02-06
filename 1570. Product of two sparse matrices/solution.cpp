class SparseVector {
public:

    vector<int> nums;
    SparseVector(vector<int> &nums2) {
        nums = nums2;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int ans = 0;
        for(int i=0;i<nums.size();i++)
        ans+= nums[i] * vec.nums[i];
        return ans;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);