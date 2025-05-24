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
    Node* segregate(Node* head) 
    {
        int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        Node* temp = head;
        while(temp != NULL)
        {
            if(temp->data == 0)
            {
                count0++;
            }
            else if(temp->data == 1)
            {
                count1++;
            }
            else
            {
                count2++;
            }
            temp = temp->next;
        }
        temp = head;
        
        while(temp != NULL)
        {
            if(count0)
            {
                temp->data = 0;
                count0--;
            }
            else if(count1)
            {
                temp->data = 1;
                count1--;
            }
            else 
            {
                temp->data = 2;
                count2--;
            }
            temp = temp->next;
        }
        return head;
    
        
        // code here
        
    }
};

//.T.C. -> O(2N)
//.S.C. -> O(1)
