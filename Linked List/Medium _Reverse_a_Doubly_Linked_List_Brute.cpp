/*
Given a doubly linked list. Your task is to reverse the doubly linked list and return its head.

Examples:

Input: LinkedList: 3 <-> 4 <-> 5
Output: 5 <-> 4 <-> 3

Input: LinkedList: 75 <-> 122 <-> 59 <-> 196
Output: 196 <-> 59 <-> 122 <-> 75

Expected Time Complexity: O(n).
Expected Auxiliary Space: O(1).

Constraints:
1 <= number of nodes <= 106
0 <= node->data <= 104
*/


/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) 
    {
        stack<int> st;
        DLLNode* temp = head;
        while(temp != NULL)
        {
            st.push(temp->data);
            temp = temp->next;
            
        }
        temp = head;
        while(temp != NULL)
        {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }
        return head;
        // Your code here
        
    }
};

//T.C. -> O(2N)
//S.C. -> O(N)
