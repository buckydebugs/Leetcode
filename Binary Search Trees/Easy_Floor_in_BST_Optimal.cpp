/*
You are given a BST(Binary Search Tree) with n number of nodes and value x. your task is to find the greatest value node of the BST which is smaller than or equal to x.
Note: when x is smaller than the smallest node of BST then returns -1.

Examples:

Input:
n = 7               2
                     \
                      81
                    /     \
                 42       87
                   \       \
                    66      90
                   /
                 45
x = 87
Output: 87
Explanation: 87 is present in tree so floor will be 87.
Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 11
Output: 9
Input:
n = 4                     6
                           \
                            8
                          /   \
                        7       9
x = 5
Output: -1
Constraint:
1 <= Noda data <= 109
1 <= n <= 105

Expected Complexities
Time Complexity: O(height of tree)
Auxiliary Space: O(height of tree)
*/

// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) 
    {
        int floory = -1;
        while(root)
        {
            if(root->data == x)
            {
                floory = root->data;
                return floory;
            }
            if(x > root->data)
            {
                floory = root->data;
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        // Code here
        return floory;
    }
};
//T.C. -> O(log2 n)
//S.C> -> O(1)
