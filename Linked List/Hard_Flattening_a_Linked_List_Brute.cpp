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

Expected Complexities
Time Complexity: O(n * n * m)
Auxiliary Space: O(n)
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
  
    Node* convertToLinkedList(vector<int> arr)
    {
        if(arr.size() == 0)
        {
            return NULL;
        }
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i = 1; i<arr.size(); i++)
        {
            Node* newNode = new Node(arr[i]);
            temp->bottom = newNode;
            temp = temp->bottom;
        }
        return head;
    }
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) 
    {
        vector<int> arr;
        Node* temp = root;
        while(temp != NULL)
        {
            Node* t2 = temp;
            while(t2 != NULL)
            {
                arr.push_back(t2->data);
                t2 = t2->bottom;
            }
            temp = temp->next;
        }
        sort(arr.begin(), arr.end());
        Node* head = convertToLinkedList(arr);
        return head;
        // Your code here
        
    }
};

//T.C. -> O(n*m) + 2*O(nmlog(nm) where n is the row length and m is column length
//S.C. -> O(n*m*2)
