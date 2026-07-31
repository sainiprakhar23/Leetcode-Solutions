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
        ListNode* currNode = head;
        while(currNode != NULL &&currNode->next != NULL){
            if(currNode->val == currNode->next->val){
                ListNode* temp = currNode->next;
                currNode->next = temp->next;
                delete temp;
            }
            else{
                // in else becz after deleting dulpicate we should on the same node ,
                // as another dupicate may be there, we will move the curr->next has diff value
             currNode = currNode->next;      
            }
            
        }
        return head;
    }
};