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
    ListNode* reverse(ListNode* head){
        ListNode* temp1 = NULL;
        ListNode* temp2 = head;
        while(temp2!=NULL){
            ListNode* next = temp2->next;
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = next;
        }
        return temp1;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast=fast->next->next;
        }
        ListNode* head2 = reverse(slow->next);
        slow->next = NULL;
        while (head!=NULL && head2!=NULL){
            if (head->val != head2->val){
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};

int main(){
    int n;
    cin >> n;
    ListNode* head = new ListNode();
    ListNode* temp = head;
    for (int i = 0;i<n;i++){
        int x;
        cin >> x;
        temp->val = x;
        if (i != n-1){
            temp->next = new ListNode();
            temp = temp->next;
        }
    }
    Solution sol;
    cout << sol.isPalindrome(head);
    return 0;
}