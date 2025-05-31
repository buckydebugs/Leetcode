/*
Given a doubly linked list of n nodes sorted by values, the task is to remove duplicate nodes present in the linked list.

Example 1:

Input:
n = 6
1<->1<->1<->2<->3<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of node with value 1 is 
retained, rest nodes with value = 1 are deleted.
Example 2:

Input:
n = 7
1<->2<->2<->3<->3<->4<->4
Output:
1<->2<->3<->4
Explanation:
Only the first occurance of nodes with values 2,3 and 4 are 
retained, rest repeating nodes are deleted.
Your Task:
You have to complete the method removeDuplicates() which takes 1 argument: the head of the linked list.  Your function should return a pointer to a linked list with no duplicate element.

Constraint:
1 <= n <= 105
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)
*/
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

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) 
    {
        if(head == NULL)
        {
            return NULL;
        }
        Node* temp = head;
        while(temp != NULL && temp->next != NULL)
        {
            Node* nextNode = temp->next;
            while(nextNode != NULL && nextNode->data == temp->data)
            {
                Node* duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate;
            }
            temp->next = nextNode;
            if(nextNode != NULL)
            {
                nextNode->prev = temp;
            }
            temp = temp->next;
        }
        return head;
        // Your code here
        
    }
};
//T.C. -> O(n) and Not O(N^2) because the temp goes through unique elements and nextNode goes through duplicates so O(n)
//S.C. -> O(1)
