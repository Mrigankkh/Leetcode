/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    unordered_map<int, vector<int>> umap;
    int mn = INT_MAX;
    int mx = INT_MIN;
    void bfs(TreeNode* root)
    {
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root,0));
        int curr = 0;
        while(!q.empty())
        {
            auto front = q.front();
            mx = max(mx, front.second);
            mn = min(mn,front.second);
            if(umap.find(front.second)!=umap.end())
            {
                
                umap[front.second].push_back(front.first->val);
            }
            else
            {
            umap[front.second] = {front.first->val};
            }
         
            q.pop();

            if(front.first->left)
          { 
               q.push({front.first->left , front.second-1});
          
          }
            if(front.first->right)
     {       q.push({front.first->right , front.second+1});}

        }

    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
     
        vector<vector<int>> ans;
           if(!root)
           return ans;
                bfs(root);
        for(int i=mn; i<= mx; i++)
        {
            if(umap.find(i)!=umap.end())
            ans.push_back(umap[i]);
        }
        return ans;
        
    }
};