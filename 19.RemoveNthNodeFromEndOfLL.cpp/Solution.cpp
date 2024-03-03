#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        int i = 0;
        while(i<n){
            fast = fast ->next;
            i++;
        }

        if (fast == NULL){
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        while(fast->next != NULL){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return head;
    }

};