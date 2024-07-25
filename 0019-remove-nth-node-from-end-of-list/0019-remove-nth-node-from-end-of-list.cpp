/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head; // Initialize slow pointer at the head of the list
        ListNode* fast = head; // Initialize fast pointer at the head of the list

        // Move the fast pointer n steps ahead
        while (n--) {
            fast = fast->next;
        }

        // Check if fast pointer reached the end after n steps
        if (fast == nullptr) {
            return head->next; // If yes, we need to remove the head, so return head->next
        }

        // Move both pointers until fast reaches the end of the list
        while (fast->next) {
            slow = slow->next; // Move slow pointer one step
            fast = fast->next; // Move fast pointer one step
        }

        // At this point, slow pointer is at the node just before the node to be deleted
        slow->next = slow->next->next; // Adjust the next pointer to skip the node to be deleted

        return head; // Return the head of the modified list
    }
};
