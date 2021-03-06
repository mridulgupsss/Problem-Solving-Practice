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
    public :
    int camera=0;
    int helper(TreeNode* root)
    {
        if(root==NULL) return 1;
        int l=helper(root->left);
        int r=helper(root->right);
        if(l==-1 || r==-1)
        {
            camera++;
            return 0;
            
        }
        if(l==0 || r==0) return 1;
        else // if (l==1 && r==1)
        {
            return -1;
        }
        
        
    }
    int minCameraCover(TreeNode* root) {
        if(helper(root)==-1) camera++;
        return camera;
    }
};