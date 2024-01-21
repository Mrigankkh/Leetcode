class Solution {
public:
    bool valid(vector<vector<int>>& matrix , int x, int y)
    {
        if( x< matrix.size() && x>=0 && y<matrix[0].size() && y>=0)
        {
            if(matrix[x][y]!= -101)
            return true;
        }
        return false;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int sz = matrix.size() * matrix[0].size()-1;
        vector<int> dx = {0,-1,0,1};
        vector<int> dy = {1,0,-1,0};
        ans.push_back(matrix[0][0]);
           matrix[0][0] = -101;
        int cx = 0;
        int cy = 1;
        int sx = 0, sy = 0;
        while(sz>0)
        {
            cout<<"Checking "<<sx+cx<<" "<<sy+cy<<endl;
            if(valid(matrix, sx + cx, sy+ cy))
            {

                sx+=cx;
                sy+=cy;
                ans.push_back(matrix[sx][sy]);
                matrix[sx][sy] = -101;
                --sz;
            cout<<"Valid curent direction"<<sx<<sy<<endl;
            }
            else
            {
                cout<<"Changing direction"<<endl;
                // need to test other directions
                for(int d=0;d<4;d++)
                {
                    if(valid(matrix, sx + dx[d], sy+ dy[d]))
                    {
                        sx = sx + dx[d];
                        sy = sy + dy[d];
                        ans.push_back(matrix[sx][sy]);
                        matrix[sx][sy] = -101;
                        --sz;
                        cx = dx[d];
                        cy = dy[d];
                        break;
                    }

                }
            }
        }
        return ans;
    }
};