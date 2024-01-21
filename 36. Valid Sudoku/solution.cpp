class Solution {
public:

    bool condition3(vector<vector<char>>& board)
    {
        bool ans  = true;
        vector<vector<int>> startPoints = {{0,0}, {0,3}, {0,6},{3,0}, {3,3}, {3,6}, {6,0}, {6,3}, {6,6}};
        for(auto point : startPoints)
        {
            ans = ans && bfs(board, point[0], point[1]);
            if(ans==false)
            return ans;
        }
        return ans;

    }
    bool valid(int sx, int sy,int x , int y )
    {
        return x < sx+3 && y < sy +3;
    }


    bool bfs(vector<vector<char>>& board , int sx, int sy)
    {
        unordered_map<char, bool> found;
        queue<string> q;
        vector<vector<int>> visited(9, vector<int>(9,0));

        visited[sx][sy] = true;
        if(board[sx][sy]!= '.')
        {
            found[board[sx][sy]] = true;
        }

        q.push(to_string( sx+1) + to_string(sy+1));
        while(!q.empty())
        {
                string front = q.front();
                q.pop();
                int xy = stoi(front);
                int x = (xy - xy%10)/10 -1;
                int y =  xy%10 -1;
                vector<int> dx = {0,1,1};
                vector<int> dy = {1,0,1};
                for(int d=0;d<3;d++)
                {

                 if(valid(sx,sy, x+dx[d], y+dy[d]) && !visited[x+dx[d]][y+dy[d]])
                 {
                    visited[x+dx[d]][y+dy[d]] = true;
                    if(board[x+dx[d]][y+dy[d]]!= '.')
                    {
                        if(found.find(board[x+dx[d]][y+dy[d]]) == found.end())              
                            found[board[x+dx[d]][y+dy[d]]] = true;
                        else
                            return false;
                    }
                    q.push(to_string(dx[d]+x +1) + to_string(1+ y+dy[d]));
                 }
            }
        }
        return true;
    }

 
   bool condition1(vector<vector<char>>& board)
    {
        vector<vector<bool>> existR(9,vector<bool>(9,false));
        vector<vector<bool>> existC(9,vector<bool>(9,false));
       for(int i=0;i<9;i++)
       {
           for(int j=0;j<9;j++)
           {
               if(board[i][j]!='.')
                { 
                    if(existR[j][board[i][j]- '1']== false)
                    {
                        existR[j][board[i][j]- '1'] = true;
                    }
                    else
                    {
                        return false;
                    }
                    if(existC[i][board[i][j] - '1']== false)
                    {
                        existC[i][board[i][j]- '1'] = true;
                    }
                    else
                    {
                        return false;
                    }
               
                 }
           }
       }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return condition1(board) && condition3(board);
    }
};