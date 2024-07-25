/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            // If the list is empty or has only one node, there can't be a cycle
            return nullptr;
        }

        ListNode* slow = head;  // Slow pointer moves one step at a time
        ListNode* fast = head;  // Fast pointer moves two steps at a time

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // Move slow pointer one step
            fast = fast->next->next;    // Move fast pointer two steps

            if (slow == fast) {         // If slow and fast meet, there is a cycle
                ListNode* start = head; // To find the start of the cycle, initialize another pointer at head
                while (start != slow) { // Move both pointers one step at a time
                    start = start->next;
                    slow = slow->next;
                }
                return start;           // Both pointers meet at the start of the cycle
            }
        }

        return nullptr;  // If no cycle is detected, return nullptr
    }
};
