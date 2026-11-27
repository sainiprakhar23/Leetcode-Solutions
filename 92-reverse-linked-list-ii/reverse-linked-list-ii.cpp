class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (head == NULL || left == right) return head;

        ListNode* beforeSublist = NULL;
        ListNode* current = head;

        int position = 1;

        // Reach the node at position left
        while (position < left) {
            beforeSublist = current;
            current = current->next;
            position++;
        }

        // Reverse the required sublist
        ListNode* reverseCurrent = current;
        ListNode* previous = NULL;

        int nodesToReverse = right - left + 1;

        while (nodesToReverse--) {
            ListNode* nextNode = reverseCurrent->next;

            reverseCurrent->next = previous;
            previous = reverseCurrent;
            reverseCurrent = nextNode;
        }

        // Connect the reversed sublist
        current->next = reverseCurrent;

        if (beforeSublist != NULL) {
            beforeSublist->next = previous;
            return head;
        }

        return previous;
    }
};