/*
Given the head of a Singly Linked List and a value x, insert that value x at the beginning of the LinkedList and return the modified Linked List.

Examples :

Input: LinkedList: 1->2->3->4->5 , x = 6
Output: 6->1->2->3->4->5
Explanation: 

We can see that 6 is inserted at the beginning of the linkedlist.
Input: LinkedList: 5->4 , x = 1
Output: 1->5->4
Explanation: 

We can see that 1 is inserted at the beginning of the linkedlist.
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)

Constraints:
1 <= number of nodes <= 105
1 <= node->data , x <= 103
*/


class Solution {
public:
    // Function to insert a node at the beginning of the linked list
    Node* insertAtBegining(Node* head, int x) {
        Node* temp = new Node(x);
        temp->next = head;
        // Correctly initializes a new node
        return temp;
    }
};

//T.C. -> O(1)
//S.C. -> O(1)
