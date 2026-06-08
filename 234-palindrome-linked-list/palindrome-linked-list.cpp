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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next) return true;
        //finding an middle element
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while(curr){
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        //compare first and second half
        ListNode* first = head;
        ListNode* second = prev; // prev is head of second half  linked list
        bool isPalin = true;
        while(second){
            if(first->val !=second->val){
                isPalin = false;
                break;
            }
            first = first->next;
            second = second->next;
        }
        //restore the linked list
        curr = prev;
        prev = nullptr;
        while(curr){
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return isPalin;

    }
};