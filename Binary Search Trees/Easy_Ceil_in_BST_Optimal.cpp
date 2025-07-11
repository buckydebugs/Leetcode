/*
Given a BST and a number X, find Ceil of X.
Note: Ceil(X) is a number that is either equal to X or is immediately greater than X.

If Ceil could not be found, return -1.

Examples:

Input: root = [5, 1, 7, N, 2, N, N, N, 3], X = 3

Output: 3
Explanation: We find 3 in BST, so ceil of 3 is 3.
Input: root = [10, 5, 11, 4, 7, N, N, N, N, N, 8], X = 6

Output: 7
Explanation: We find 7 in BST, so ceil of 6 is 7.
Your task:
You don't need to read input or print anything. Just complete the function findCeil() to implement ceil in BST which returns the ceil of X in the given BST.

Constraints:
1 <= Number of nodes <= 105
1 <= Value of nodes<= 105

Expected Complexities
Time Complexity: O(log n)
Auxiliary Space: O(1)
*/

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) 
{
    int ceily = -1;
    while(root)
    {
        if(root->data == input)
        {
            ceily = root->data;
            return ceily;
        }
        if(input > root->data)
        {
            root = root->right;    
        }
        else
        {
            ceily = root->data;
            root = root->left;
        }
    }
    // Your code here
    return ceily;
}
//T.C. -> O(log2 n)
//S.C. -> O(1)
