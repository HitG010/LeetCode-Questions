#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Iterative solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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
};

// Recursive solution
class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            if (head == NULL || head->next == NULL){
                return head;
            }
            ListNode* newHead = reverseList(head->next);
            head->next->next = head;
            head->next = NULL;
            return newHead;
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
    ListNode* newHead = sol.reverseList(head);
    while(newHead!=NULL){
        cout << newHead->val << " ";
        newHead = newHead->next;
    }
    cout << endl;
    return 0;
}