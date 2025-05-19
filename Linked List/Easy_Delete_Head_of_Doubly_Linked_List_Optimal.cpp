/*
Given a doubly linked list of size n, you have to delete the head of the linked list and return the new head.
Note: Please set the previous of new head to null, and set the next of old head to null, and then delete the old head.

Example 1:

Input:
LinkedList: 1<-->2
Output:
2
2
Example 2:

Input:
LinkedList: 2<-->5<-->7<-->8<-->99<-->100
Output:
5 7 8 99 100
100 99 8 7 5
Your Task:
The task is to complete the function deleteHead() which takes head reference and returns reference to the new head node, which is then used to display the list. (The driver's code print the modified list twice, once forward and once backward)

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
2 <= number of nodes <= 103
*/


// User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/
Node *deleteHead(Node *head) 
{
     Node* oldHead = head;
      head = head->next;
      head->prev = NULL;
      oldHead->next = NULL;
      delete oldHead;
      return head;
    // Your code here
    
}

//T.C. -> O(1)
//S.C. -> O(1)
