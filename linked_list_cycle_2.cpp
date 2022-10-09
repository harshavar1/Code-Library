/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <stdint.h>
class Solution {
public:
    
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)
        {
            return NULL;
        }
        ListNode *fast = head->next->next, *slow = head->next;
        while(fast != slow and fast and fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        // std::cout << "loop found";
        
        if(fast != slow)
        {
            return NULL;
        }
        else
        {
            fast = head;
            while(fast != slow)
            {
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    
    
