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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* dummy =new ListNode(0);
        dummy->next=head;
        unordered_map<int,ListNode*> mp;
        mp[0]=dummy;
        int sum=0;
        
        while(head!=NULL){
            sum+=head->val;
            
            if(mp.count(sum)){
                ListNode* prev= mp[sum];
                ListNode* start= prev;
                
                //delete bad references
                int aux = sum;
                while(prev!=head){
                    prev=prev->next;
                    aux+=prev->val;
                    if(prev!=head)mp.erase(aux);
                }
                
                start->next = head->next;
            }else{
                mp[sum]= head;
            }
            
            head=head->next;
        }
        
        return dummy->next;
    }
};