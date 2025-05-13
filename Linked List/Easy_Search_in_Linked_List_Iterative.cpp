/*
Given a linked list of n nodes and a key, the task is to check if the key is present in the linked list or not.

Example:

Input: n = 4, key = 3
1->2->3->4
Output: true
Explanation: 3 is present in Linked List, so the function returns true.
Constraint:
1 <= n <= 105
1 <= key <= 105
*/


/* Link list node */
/*
struct Node
{
    int data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
}; */

class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) 
    {
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
        // Code here
        
    }
};
//T.C. -> Best case: O(1) head is the key. Worst Case: O(n). Averagae Case: O(n/2)
//S.C. -> O(1)
