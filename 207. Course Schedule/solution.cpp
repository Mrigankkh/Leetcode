class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {

        // First we need to store the indegrees of each vertex.
        vector<int> inDegree(numCourses,0);
         //We also need to create an adjacency list.

         unordered_map<int, vector<int>> umap;
         for(auto p : pre)
         {
             inDegree[p[1]]++;
             int out = p[0];
             if(umap.find(out)== umap.end())
             {
                 umap[out] = {p[1]};
             }
             else
             {
                 umap[out].push_back(p[1]);
             }
         }

         //Now remove each node successively. Start with nodes that have indegree 0.

         queue<int> q;
         for(auto i =0;i< numCourses;i++)
         {
             if(inDegree[i]==0)
             {
                 q.push(i);
             }
         }

        vector<int> popped;
         // BFS: Remove child nodes
         while(!q.empty())
         {
             int sz = q.size();
             for(int i=0;i<sz;i++)
             {
                 int front = q.front();
                 q.pop();
                 popped.push_back(front);
                 for(auto outs : umap[front])
                 {
                     --inDegree[outs];
                     if(inDegree[outs]==0)
                     {
                         q.push(outs);
                     }
                 }
             }
         }
return numCourses==popped.size();


        
    }
};