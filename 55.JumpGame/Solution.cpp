#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int last = n-1;
        for (int i = n-2;i>=0;i--){
            if (i+nums[i]>=last){
                last = i;
            }
        }
        if (last == 0){
            return true;
        }
        
        return false;
       
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0;i<n;i++){
        cin >> nums[i];
    }
    Solution sol;
    cout << sol.canJump(nums) << endl;
}