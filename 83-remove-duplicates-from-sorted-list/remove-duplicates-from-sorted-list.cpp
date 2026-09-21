class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* currentNode = head;
        while(currentNode != NULL && currentNode->next!=NULL){
            if(currentNode->val == currentNode->next->val){
                ListNode* temp = currentNode->next;
                currentNode->next = temp->next;
                delete temp;
            }
            else{
                currentNode = currentNode->next;
            }
        }
        return head;
    }
};