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
    bool isEvenOddTree(TreeNode* root) {
        


        queue<TreeNode*> q;
        q.push(root);
        int lvl = 0;
        TreeNode* prev = NULL;
        while(!q.empty())
        {

            int sz = q.size();
            for(int i=0;i< sz;i++)
            {

                
                 auto front = q.front();
                  q.pop();

                if(lvl%2==0 )
                {
                    // Even level must have increasing odd values.
              
                    if(front->val%2==0)
                   {
                        return false;
                   }
                    if(prev!=NULL)
                    {
                        if(prev->val >= front->val )
                        {
                            return false;
                        }
                    }
                        prev = front;
                }


                else
                {
                    cout<<lvl<<endl;
                    if(front->val%2!=0)
                    return false;
                     if(prev!=NULL)
                    {

                        if(prev->val <= front->val )
                        {
                            return false;
                        }
                    }
                        prev = front;  

                }

               
                if(front->left!=NULL)
                {
                    cout<<"Pushing left element"<<endl;
                    q.push(front->left);}

                if(front->right!=NULL)
                {
                    cout<<"Pushing right element"<<endl;
                    q.push(front->right);}
            }

            prev = NULL;
            lvl+=1;
        }
        return true;

    }
};