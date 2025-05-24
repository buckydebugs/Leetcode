/*
Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

Examples:

Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2

Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2

Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
Input: head = 2 → 2 → 0 → 1

Output: 0 → 1 → 2 → 2

Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be 0 → 1 → 2 → 2.
Constraints:
1 ≤ no. of nodes ≤ 106
0 ≤ node->data ≤ 2
*/

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
public:
    Node* segregate(Node* head) {
        if (!head) return nullptr;

        Node* dummyZero = new Node(-1);
        Node* zero = dummyZero;
        Node* dummyOne = new Node(-1);
        Node* one = dummyOne;
        Node* dummyTwo = new Node(-1);
        Node* two = dummyTwo;

        Node* temp = head;

        // Segregating into separate lists
        while (temp) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = temp;
            } else if (temp->data == 1) {
                one->next = temp;
                one = temp;
            } else {
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }

        // Correct linking to maintain all elements
        zero->next = dummyOne->next ? dummyOne->next : dummyTwo->next;
        one->next = dummyTwo->next;
        two->next = nullptr;  // Prevent cycle
        
        delete(dummyZero);
        delete(dummyOne);
        delete(dummyTwo);
        

        return dummyZero->next;
    }
};

// T.C. -> O(N)
// S.C. -> O(1)
