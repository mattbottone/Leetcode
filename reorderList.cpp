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
    //count number of nodes
    int countNodes(ListNode* head) {
        int count = 0;

        while (head != nullptr) {
            count++;
            head = head->next;
        }

        return count;
    }

    //reverse the second half of the list (if odd, second.size() == first.size() - 1)
    ListNode* reverseHalf(ListNode* head, int count) {
        ListNode *current = nullptr, *newHead = nullptr, *last = nullptr, *next = nullptr;

        for (int i = 0; i < (count-1) / 2; i++) head = head->next;
        newHead = head; // if list is [1,2,3,4,5], head is 3
        current = head->next;

        while (current != nullptr) {
            next = current->next;
            current->next = last;
            last = current;
            current = next;
        }
        newHead->next = nullptr;

        return last;
    }

    void reorderList(ListNode* head) {
        int count = countNodes(head);
        ListNode *firstHalf = head, *next = nullptr;
        ListNode *secondHalf = reverseHalf(head, count);

        for (int i = 0; i < count / 2; i++) {
            next = firstHalf->next;
            firstHalf->next = secondHalf;
            secondHalf = secondHalf->next;
            firstHalf = firstHalf->next;
            firstHalf->next = next;
            firstHalf = firstHalf->next;
        }
    }
};
