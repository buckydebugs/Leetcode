/*
Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

 

Example 1:


Input: root = [3,1,4,null,2], k = 1
Output: 1
Example 2:


Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3
 

Constraints:

The number of nodes in the tree is n.
1 <= k <= n <= 104
0 <= Node.val <= 104
 

Follow up: If the BST is modified often (i.e., we can do insert and delete operations) and you need to find the kth smallest frequently, how would you optimize?
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
    void inorderHelper(TreeNode* root, int& count, int& val, int k) {
        if (!root) return;

        inorderHelper(root->left, count, val, k);

        count++;
        if (count == k) {
            val = root->val;
            return; // Early return to avoid unnecessary traversal
        }

        inorderHelper(root->right, count, val, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        int val = -1; // Default value
        inorderHelper(root, count, val, k);
        return val;
    }
};

//T.C. -> O(n)
//S.C. -> O(1)
