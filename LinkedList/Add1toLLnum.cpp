// Add 1 to a Linked List Number
// https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1


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
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        while(curr != NULL){
            Node* nextNode = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        
        // return head of list after adding one
        Node* h = reverse(head);
        int c = 1;
        Node* curr = h;
        while(curr != NULL && c){
            int su = curr -> data + c;
            curr -> data = su % 10;
            c = su / 10;
            if(curr -> next == NULL && c)
            {
                curr -> next = new Node(c);
                c = 0;
            }
            curr = curr -> next;
        }
        return reverse(h);
    }
};