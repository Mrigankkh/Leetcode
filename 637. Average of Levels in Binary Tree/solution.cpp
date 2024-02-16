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
    vector<double> averageOfLevels(TreeNode* root) {
        //BFS
        vector<double> ans;
        if(!root)
        {
            return ans;
        }

        queue<TreeNode* > q;
        q.push(root);
        int lvl = 0;
        while(!q.empty())
        {
            int sz = q.size();
            double sum = 0;
            int count = 0;
            for(int i=0;i<sz; i++)
            {
                auto front = q.front();
                q.pop();
                 sum+= front->val;
                 ++count;
                if(front->right!=NULL)
                {
                   
                    q.push(front->right);
                }
                if(front-> left!=NULL)
                {
                    q.push(front->left);
                }
            }
            if(count==0)
            ans.push_back(0);
            else
             ans.push_back(sum/count);
        }
        return ans;
    }
};