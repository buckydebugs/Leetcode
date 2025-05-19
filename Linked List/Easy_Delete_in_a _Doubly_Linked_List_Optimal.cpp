/*
Given a Doubly Linked list and a position. The task is to delete a node from a given position (position starts from 1) in a doubly linked list and return the head of the doubly Linked list.

Examples:

Input: LinkedList = 1 <--> 3 <--> 4, x = 3
Output: 1 <--> 3
Explanation: After deleting the node at position 3 (position starts from 1),the linked list will be now as 1 <--> 3.
 
Input: LinkedList = 1 <--> 5 <--> 2 <--> 9, x = 1
Output: 5 <--> 2 <--> 9
Explanation:

Constraints:
2 <= size of the linked list <= 106
1 <= x <= size of the linked list 
1 <= node->data <= 104
*/

/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
  Node* deleteHead(Node* head)
  {
      Node* oldHead = head;
      head = head->next;
      head->prev = NULL;
      oldHead->next = NULL;
      delete oldHead;
      return head;
      
  }
  Node* deleteTail(Node* head)
  {
      Node* tail = head;
      while(tail->next != NULL)
      {
          tail = tail->next;
      }
      Node* newTail = tail->prev;
      newTail->next = NULL;
      tail->prev = NULL;
      delete tail;
  return head;
  }
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) 
    {
        if(head == NULL)
        {
            return head;
        }
        int count = 0;
        Node* kNode = head;
        while(kNode != NULL)
        {
            count++;
            if(count == x)
            {
                break;
            }
            kNode = kNode->next;
        }
        Node* back = kNode->prev;
        Node* front = kNode->next;
        
        if(back == NULL && front == NULL)
        {
            delete(kNode);
            return NULL;
        }
        else if(back == NULL)
        {
            return deleteHead(head);
        }
        else if(front == NULL)
        {
            return deleteTail(head);
        }
        back->next = front;
        front->prev = back;
        
        kNode->next = NULL;
        kNode->prev = NULL;
        delete kNode;
        return head;
        // Your code here
        
    }
};
//T.C. -> O(2N) + O(N) + O(N)
//S.C. -> O(1)
