/*
Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order: 

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary. 

Examples:

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:
 
Input: root[] = [1, 2, N, 4, 9, 6, 5, N, 3, N, N, N, N 7, 8]
Output: [1, 2, 4, 6, 5, 7, 8]
Explanation:
            
As the root doesn't have a right subtree, the right boundary is not included in the traversal.
Input: root[] = [1, N, 2, N, 3, N, 4, N, N] 
Output: [1, 4, 3, 2]
Explanation:

Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
*/


/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    bool isLeaf(Node* root)
    {
        return !root->left && !root->right;
    }
    void addLeftBoundary(Node* root, vector<int> &result)
    {
        Node* current = root->left;
        while(current)
        {
            if(!isLeaf(current))
            {
                result.push_back(current->data);
            }
            if(current->left)
            {
                current = current->left;
            }
            else
            {
                current = current->right;
            }
        }
    }
    void addLeaves(Node* root, vector<int> &result)
    {
        if(isLeaf(root))
        {
            result.push_back(root->data);
            return;
        }
        if(root->left)
        {
            addLeaves(root->left, result);
        }
        if(root->right)
        {
            addLeaves(root->right, result);
        }
    }
    void addRightBoundary(Node* root, vector<int> &result)
    {
        Node* current = root->right;
        vector<int> temp;
        while(current)
        {
            if(!isLeaf(current))
            {
                temp.push_back(current->data);
            }
            if(current->right)
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }
        }
        for(int i = temp.size()-1; i >= 0; i--)
            {
                result.push_back(temp[i]);
            }
    }
    vector<int> boundaryTraversal(Node *root) 
    {
        vector<int> result;
        if(!root)
        {
            return result;
        }
        if(!isLeaf(root))
        {
            result.push_back(root->data);
        }
        addLeftBoundary(root, result);
        addLeaves(root, result);
        addRightBoundary(root, result);
        // code here
        return result;
    }
};
//T.C. -> O(LeftHeightTree) + O(NumberOfNodes) + O(RightHeightTree) ~ O(N)
//S.C. -> O(N)
