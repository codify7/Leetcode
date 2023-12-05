// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
//     private:
//     ListNode* reverse(ListNode* head) {
//         ListNode* prev = nullptr;
//         while (head != nullptr) {
//             ListNode* next = head->next;
//             head->next = prev;
//             prev = head;
//             head = next;
//         }
//         return prev;
//     }
// public:
//     bool isPalindrome(ListNode* head) {
//         if(head==NULL || head->next==NULL){
//             return true;
//         }
        
//         ListNode* slow=head;
//         ListNode* fast=head;
        
//         while(fast!=NULL && fast->next->next!=NULL){
//             slow=slow->next;
//             fast=fast->next->next;            
            
//         }
//         slow->next=reverse(slow->next);
//         slow=slow->next;
        
//         ListNode* dummy=head;
        
//         while(slow!=NULL){
//             if(dummy->val!=slow->val){
//                 return false;
//             }
//             dummy=dummy->next;
//             slow=slow->next;
            
//         }
//         return true;
        
//     }
// };

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
private:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Move to the middle of the list
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half of the list
        slow = reverse(slow);
        ListNode* check = head;

        // Compare the reversed second half with the first half
        while (slow != nullptr) {
            if (check->val != slow->val) {
                return false;
            }
            check = check->next;
            slow = slow->next;
        }

        return true;
    }
};
