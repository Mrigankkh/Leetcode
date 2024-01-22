class Solution {
public:
    bool valid(int x ,int y, int layerStart, int layerEnd)
    {
        return x>=layerStart && y>=layerStart && x<= layerEnd && y<= layerEnd ;
    }

    void advanceOne(vector<vector<int>>& matrix, int layerStart, int layerEnd)
    {
        int x = layerStart;
        int y = x;
        int temp = matrix[x][y];
        
        vector<int> dx = {0,1,0,-1};
        vector<int> dy = {1,0,-1,0};

        for(int d=0;d<4;d++)
        {
            while(valid(x+dx[d], y+dy[d], layerStart, layerEnd))
            {
                int temp2 =  matrix[x+dx[d]][y+dy[d]];
                matrix[x+dx[d]][y+dy[d]] = temp;
                temp = temp2;
                x += dx[d];
                y += dy[d];
            }
        }

    }
    void rotate(vector<vector<int>>& matrix) {
        int layerWidth = matrix.size();
        int temp = INT_MIN;
        int n = matrix.size();
        for(int i = 0; i< (n+1)/2; i++)
        {
            int start = i;
            int end = i+ layerWidth-1;
            int advance = layerWidth - 1;
              
            for(int j=0;j<advance;j++)
            {
                advanceOne(matrix , start,end);
            }
            layerWidth-=2;
        }
    }
};