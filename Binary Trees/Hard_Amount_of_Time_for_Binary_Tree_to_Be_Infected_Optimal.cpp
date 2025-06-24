/*
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

 

Example 1:


Input: root = [1,5,3,null,4,10,6,9,2], start = 3
Output: 4
Explanation: The following nodes are infected during:
- Minute 0: Node 3
- Minute 1: Nodes 1, 10 and 6
- Minute 2: Node 5
- Minute 3: Node 4
- Minute 4: Nodes 9 and 2
It takes 4 minutes for the whole tree to be infected so we return 4.
Example 2:


Input: root = [1], start = 1
Output: 0
Explanation: At minute 0, the only node in the tree is infected so we return 0.
 

Constraints:

The number of nodes in the tree is in the range [1, 105].
1 <= Node.val <= 105
Each node has a unique value.
A node with a value of start exists in the tree.
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
    int findMaxDistance(map<TreeNode*, TreeNode*> &mappy, TreeNode* target)
    {
        queue<TreeNode*> q;
        q.push(target);
        map<TreeNode*, int> visited;
        visited[target] = 1;
        int maxi = 0;
        while(!q.empty())
        {
            int size = q.size();
            int flag = 0;
            for(int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    flag = 1;
                    visited[node->left] = 1;
                    q.push(node->left);
                }
                if(node->right && !visited[node->right])
                {
                    flag = 1;
                    visited[node->right] = 1;
                    q.push(node->right);
                }
                if(mappy[node] && !visited[mappy[node]])
                {
                    flag = 1;
                    visited[mappy[node]] = 1;
                    q.push(mappy[node]);
                }
            }
            if(flag)
            {
                maxi++;
            }
        }
        return maxi;
    }
    TreeNode* bfsToMapParents(TreeNode* root, map<TreeNode*, TreeNode*> & mappy, int start)
    {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* result;
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node->val == start)
            {
                result = node;
            }
            if(node->left)
            {
                mappy[node->left] = node;
                q.push(node->left);
            }
            if(node->right)
            {
                mappy[node->right] = node;
                q.push(node->right);
            }
        }
        return result;
    }
    int amountOfTime(TreeNode* root, int start) 
    {
        map<TreeNode*, TreeNode*> mappy;
        TreeNode* target = bfsToMapParents(root, mappy, start);
        int maxi = findMaxDistance(mappy, target);
        return maxi;
    }
};
//T.C. -> O(n) + O(n) + O(maptime) ~ O(n)
//S.C. -> O(n) + O(n) ~ O(n)
