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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        
        while (head != nullptr) {
            if (head->next != nullptr && head->val == head->next->val) {
                // Move head until the end of the duplicate sublist
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // This needs to be inside the 'if' block right after the inner while loop finishes
                prev->next = head->next; 
            } else {
                // Only move prev forward if NO duplicates were found
                prev = prev->next;
            }
            // Move head forward for the next iteration
            head = head->next;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; 
        return newHead;
    }
};