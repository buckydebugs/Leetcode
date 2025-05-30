/*
You are given the head_ref of a doubly Linked List and a Key. Your task is to delete all occurrences of the given key if it is present and return the new DLL.

Example1:

Input: 
2<->2<->10<->8<->4<->2<->5<->2
2
Output: 
10<->8<->4<->5
Explanation: 
All Occurences of 2 have been deleted.

Example2:

Input: 
9<->1<->3<->4<->5<->1<->8<->4
9
Output: 
1<->3<->4<->5<->1<->8<->4
Explanation: 
All Occurences of 9 have been deleted.
Your Task:

Complete the function void deleteAllOccurOfX(struct Node** head_ref, int key), which takes the reference of the head pointer and an integer value key. Delete all occurrences of the key from the given DLL.

Expected Time Complexity: O(N).

Expected Auxiliary Space: O(1).

Constraints:

1<=Number of Nodes<=105

0<=Node Value <=109


*/
// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
    void deleteAllOccurOfX(struct Node** head_ref, int x) 
    {
        Node* temp = *head_ref;
        while(temp != NULL)
        {
            if(temp->data == x)
            {
                if(temp == *head_ref)
                {
                    *head_ref = temp->next;
                }
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;
                if(nextNode !=NULL)
                {
                    nextNode->prev = prevNode;
                }
                if(prevNode!= NULL)
                {
                    prevNode->next = nextNode;
                }
                delete temp;
                temp = nextNode;
            }
            else
            {
                temp = temp->next;
            }
        }
        
        // Write your code here
        
    }
};
//T.C. -> O(n)
//S.C> -> O(1)
// IMP: ** means pointer to pointer so we used *head_ref instead of head 
