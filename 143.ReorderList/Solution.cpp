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

    ListNode* getMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* mid = getMid(head);
        ListNode* head2 = reverse(mid->next);
        mid->next = NULL;

        ListNode* temp = head;
        while(temp!=NULL && head2!=NULL){
            ListNode* next1 = temp->next;
            ListNode* next2 = head2->next;
            temp->next = head2;
            head2->next = next1;
            head2 = next2;
            temp = next1;
        }
        return;
    }
};

int main(){
    int n;
    cin >> n;
    ListNode* head = new ListNode();
    ListNode* temp = head;
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        temp->val = x;
        if(i!=n-1){
            temp->next = new ListNode();
            temp = temp->next;
        }
    }
    Solution sol;
    sol.reorderList(head);
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
    return 0;
}