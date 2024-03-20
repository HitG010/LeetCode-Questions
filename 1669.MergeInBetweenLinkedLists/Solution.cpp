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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        int i = 0;
        ListNode* head = list1;
        ListNode* first = NULL;
        ListNode* sec = NULL;
        while(list1!=NULL){
            if (i == a-1){
                first = list1;
            }
            if (i == b+1){
                sec = list1;
                break;
            }
            i++;
            list1 = list1->next;
        }
        if (first == NULL){
            head = list2;
        }
        else{
            first->next = list2;
        }
        while (list2->next!=NULL){
            list2 = list2->next;
        }
        if (sec != NULL){
            list2->next = sec;
        }
        return head;
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
    int a, b;
    cin >> a >> b;
    int m;
    cin >> m;
    ListNode* head2 = new ListNode();
    ListNode* temp2 = head2;
    for (int i = 0;i<m;i++){
        int x;
        cin >> x;
        temp2->val = x;
        if (i != m-1){
            temp2->next = new ListNode();
            temp2 = temp2->next;
        }
    }
    Solution sol;
    ListNode* res = sol.mergeInBetween(head, a, b, head2);
    while (res!=NULL){
        cout << res->val << " ";
        res = res->next;
    }
}