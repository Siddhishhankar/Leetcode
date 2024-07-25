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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Create a dummy node to serve as the starting point of the merged list
        ListNode dummy(0);
        ListNode* current = &dummy;

        // Traverse both lists until we reach the end of one of them
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                // If list1's value is smaller or equal, append it to the result list
                current->next = list1;
                // Move list1 to the next node
                list1 = list1->next;
            } else {
                // If list2's value is smaller, append it to the result list
                current->next = list2;
                // Move list2 to the next node
                list2 = list2->next;
            }
            // Move current to the next node in the result list
            current = current->next;
        }

        // At this point, one of the lists is fully traversed.
        // Append the remaining nodes of the other list to the result list.
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        // The merged list starts from the next node of the dummy node
        return dummy.next;
    }
};
