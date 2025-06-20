/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,2,3]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [1,2,4,5,6,7,3,8,9]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
 

Follow up: Recursive solution is trivial, could you do it iteratively?
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
    void preorderHelper(TreeNode* root, vector<int> &result)
    {
        TreeNode* temp = root;
        if(temp == nullptr)
        {
            return;
        }
        result.push_back(temp->val);
        preorderHelper(temp->left, result);
        preorderHelper(temp->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) 
    {
       vector<int> result;
       preorderHelper(root, result);
       return result;
    }
};
//T.C. -> o(n)
//S.C> -> O(n) Recursive  stack space
