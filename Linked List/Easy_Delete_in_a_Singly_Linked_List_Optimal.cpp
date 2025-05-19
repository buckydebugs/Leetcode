/*
Given a singly linked list and an integer, x. Delete the xth node (1-based indexing) from the singly linked list.

Examples:

Input: Linked list: 1 -> 3 -> 4, x = 3
Output: 1 -> 3

Explanation: After deleting the node at the 3rd position (1-base indexing), the linked list is as 1 -> 3. 
Input: Linked list: 1 -> 5 -> 2 -> 9, x = 2 
Output: 1 -> 2 -> 9
Explanation: After deleting the node at 2nd position (1-based indexing), the linked list is as 1 -> 2 -> 9.
Constraints:
2 <= size of linked list <= 106
1 <= x <= size of linked list
*/


/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* removeHead(Node* head)
    {
        Node* temp = head;
        head = temp->next;
        delete(temp);
        return head;
    }
    Node* deleteNode(Node* head, int x) 
    {
        if(head == NULL)
        {
            return head;
        }
        if(x == 1)
        {
            return removeHead(head);
        }
        int count = 0;
        Node* temp = head;
        Node* prev = NULL;
        while(temp != NULL)
        {
            count++;
            if(count == x)
            {
                prev->next = prev->next->next;
                delete(temp);
                break;
            }
            
            prev = temp;
            temp = temp->next;
        }
        return head;
        // code here
        
    }
};
//T.C. -> O(1) + O(N)
//S.C. -> O(1)
