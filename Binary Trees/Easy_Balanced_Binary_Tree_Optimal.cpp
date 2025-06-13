/*
Given a binary tree, determine if it is height-balanced.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/
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
    int findHeight(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        return 1 + max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) 
    {
        if(root == NULL)
        {
            return true;
        }
        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);
        if(abs(leftHeight-rightHeight) > 1)
        {
            return false;
        }
        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);
        if(!left || !right)
        {
            return false;
        }
        return true;
    }
};
//T.C. -> O(n^2)
//S.C. -> O(n)
