/*
Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the later one in the level order traversal is considered. For example, in the below diagram, 7 and 34 both are the bottommost nodes at a horizontal distance of 0 from the root, here 34 will be considered.

For the above tree, the output should be 5 8 34 22 25

Examples :

Input: root[] = [1, 3, 2]

Output: [3 1 2]
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input: root[] = [10, 20, 30, 40, 60]
         
Output: [40 20 60 30]
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105

Expected Complexities
Time Complexity: O(n)
Auxiliary Space: O(n)
*/

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) 
    {
        vector<int> answer;
        if(root == NULL)
        {
            return answer;
        }
        map<int, int> mappy;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            mappy[line] = node->data;
            
            if(node->left != NULL)
            {
                q.push({node->left, line - 1});
            }
            if(node->right != NULL)
            {
                q.push({node->right, line + 1});
            }
        }
        for(auto it : mappy)
        {
            answer.push_back(it.second);
        }
        // Your Code Here
        return answer;
    }
};
//T.C. -> O(n) + O(maptime)
//S.C. -> O(n) + O(mapspace)
