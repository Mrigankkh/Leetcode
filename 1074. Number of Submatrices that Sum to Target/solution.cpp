class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        //Find prefix sum for each row

        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int row = 0; row<rows;row++)
        {
            for(int col = 1 ; col< cols;col++)
            {
                matrix[row][col]+= matrix[row][col-1];
            }
        }

        // We have prefix sum for each row.
        int count = 0;
        for(int col1 = 0 ; col1<cols;col1++)
        {
            for(int col2 = col1;col2<cols;col2++)
            {

                unordered_map<int,int> umap;
                umap[0] = 1;
                int currSum = 0;

                for(int row = 0;row< rows; row++)
                {

                    if(col1>0)
                        currSum+= matrix[row][col2] - matrix[row][col1-1];
                    else 
                        currSum+= matrix[row][col2];

                    if(umap.find(currSum - target)!=umap.end())
                    {
                        count+= umap[currSum -  target];
                    }

                    if(umap.find(currSum)!=umap.end())
                    {
                        umap[currSum]++;
                    }
                    else
                    umap[currSum] = 1;
                }

            }
        }

        return count;
    }
};