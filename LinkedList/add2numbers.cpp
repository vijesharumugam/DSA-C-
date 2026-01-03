//  2. Add Two Numbers (Leetcode)


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head){
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr != nullptr){
            ListNode* next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        
        ListNode* ans = new ListNode(-1);
        ListNode* temp = ans;
        int c = 0;
        while( h1 != nullptr || h2 != nullptr || c){
            int su = 0;
            if(h1 != nullptr){
                su += h1 -> val;
                h1 = h1 -> next;
            }
            if(h2 != nullptr){
                su += h2 -> val;
                h2 = h2 -> next;
            }
            su += c;
            c = su / 10;
            ListNode* node = new ListNode(su % 10);
            temp -> next = node;
            temp = temp -> next;
        }
        return ans->next;
    }
};