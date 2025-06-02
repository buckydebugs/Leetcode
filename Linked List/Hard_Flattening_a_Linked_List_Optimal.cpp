/*
Given a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom pointer to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data.
Your task is to flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

Note:
1. ↓ represents the bottom pointer and -> represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.

Examples:

Input:

Output: 5-> 7-> 8-> 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
Explanation: 
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 10 and so on.
Input:
 
Output: 5-> 7-> 8-> 10-> 19-> 22-> 28-> 30-> 50
Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 10 and so on.
Constraints:
0 <= n <= 100
1 <= number of nodes in sub-linked list(mi) <= 50
1 <= node->data <= 104
*/
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
  
    Node* mergeTwoLists(Node* list1, Node* list2)
    {
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        
        while(list1 != NULL && list2 != NULL)
        {
            if(list1->data < list2->data)
            {
                temp->bottom = list1;
                temp = list1;
                list1 = list1->bottom;
            }
            else
            {
                temp->bottom = list2;
                temp = list2;
                list2 = list2->bottom;
            }
            temp->next = NULL;
        }
        if(list1)
        {
            temp->bottom = list1;
        }
        else if (list2) 
        {
            temp->bottom = list2;
        }
        return dummyNode->bottom;
    }
    
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) 
    {
        if(root == NULL || root->next == NULL)
        {
            return root;
        }
        Node* mergedHead = flatten(root->next);
        return mergeTwoLists(root, mergedHead);
        // Your code here
        
    }
};
//T.C. -> O(n*O(2(n1+n2))) ~ O(2mn)
//         row  merge of two lists of length n1 and n2 as 2m
//S.C. -> O(n) stack space
