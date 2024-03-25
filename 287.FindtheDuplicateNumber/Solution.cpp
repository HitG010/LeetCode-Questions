#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(fast!=slow){
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int temp = 0;
        while(temp!=slow){
            temp = nums[temp];
            slow = nums[slow];
        }
        return slow;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    Solution obj;
    cout << obj.findDuplicate(nums) << endl;
    return 0;
}