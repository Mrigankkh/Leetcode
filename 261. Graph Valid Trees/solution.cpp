class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    bool validTree(int n, vector<vector<int>>& edges) {
        

        // Build an adjacency list.

        for(int i=0;i<n;i++)
        adjList[i] = {};
        for(auto edge : edges)
        {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }
        vector<bool> visited(n, false);


      // Write a simple DFS. If it is a graph, each node will be visited.

                vector<bool> pathVisited(visited.size(), false);
                 visited[0] = true;
                 pathVisited[0] = true;
                 int count = 0;
                 dfs(count,0,visited, pathVisited, 0);
              
        return count == n-1;
       
        // return false;

    }


   void dfs(int &count,int parent,vector<bool>& visited,vector<bool>& pathVisited, int curr)
    {
        
        for(auto child : adjList[curr])
        {

             if(child==parent)
             continue;  

            if(pathVisited[child])
            {
                count = -1;
                return;    
            }

            if(!visited[child])
            {
               

                pathVisited[child] = true;
                ++count;
                visited[child] = true;
                dfs(count,curr , visited,pathVisited, child);
                if(count==-1)
                return;
            }
            pathVisited[child] = false;
        }


    }
};