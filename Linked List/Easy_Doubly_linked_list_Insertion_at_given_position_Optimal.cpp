/*
Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list and return the head of the updated list.

Examples:

Input: LinkedList: 2<->4<->5, p = 2, x = 6 
Output: 2<->4<->5<->6
Explanation: p = 2, and x = 6. So, 6 is inserted after p, i.e, at position 2 (0-based indexing).
Input: LinkedList: 1<->2<->3<->4, p = 0, x = 44
Output: 1<->44<->2<->3<->4
Explanation: p = 0, and x = 44 . So, 44 is inserted after p, i.e, at position 0 (0-based indexing).
Constraints:
0 <= p < size of doubly linked list <= 106
1 <= x <= 106
*/


/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        if (head == NULL) {
            return new Node(data);
        }

        int count = 0;  // **Fix: Use 0-based indexing for correct positioning**
        Node* temp = head;
        Node* newNode = new Node(data);

        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            // **Fix: Prevent out-of-bounds insertion**
            return head;
        }

        // Correct insertion logic
        Node* front = temp->next;
        temp->next = newNode;
        newNode->prev = temp;

        if (front) {
            front->prev = newNode;
            newNode->next = front;
        }

        return head;
    }
};

//T.C. -> O(N)
//S.C. -> O(1)
