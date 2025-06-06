/*
You are given a linked list where each element in the list is a node and have an integer data. You need to add 1 to the number formed by concatinating all the list node numbers together and return the head of the modified linked list. 

Note: The head represents the first element of the given array.

Examples :

Input: LinkedList: 4->5->6
Output: 457

Explanation: 4->5->6 represents 456 and when 1 is added it becomes 457. 
Input: LinkedList: 1->2->3
Output: 124
 
Explanation:  1->2->3 represents 123 and when 1 is added it becomes 124. 
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1 <= len(list) <= 105
0 <= list[i] <= 9
*/


/*

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
    Node* reverseList(Node* head)
    {
        Node* prev = NULL;
        Node* temp = head;
        while(temp != NULL)
        {
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    Node* addOne(Node* head) 
    {
        int carry = 1;
        head = reverseList(head);
        Node* temp = head;
        while(temp != NULL)
        {
            temp->data = temp->data + carry;
            if(temp->data < 10)
            {
                carry = 0;
                break;
            }
            else
            {
                temp->data = 0;
                carry = 1;
            }
            temp = temp->next;
        }
        if(carry == 1)
        {
            Node* newNode = new Node(carry);
            head = reverseList(head);
            newNode->next = head;
            return newNode;
        }
        head = reverseList(head);
        return head;
        // Your Code here
        // return head of list after adding one
    }
};

//T.C. -> O(3N)
//S.C. ->O(1)
