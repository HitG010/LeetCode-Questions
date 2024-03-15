#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prod = 1;
        int count = 0;
        for (int i = 0;i<nums.size();i++){
            if (nums[i] == 0){
                count++;
                continue;
            }
            prod*= nums[i];
        }
        for (int i = 0;i<nums.size();i++){
            if (nums[i] == 0 && count == 1){
                nums[i] = prod;
            }
            else if (count>0){
                nums[i] = 0;
            }
            else{
                nums[i] = prod/nums[i];
            }
            
        }
        return nums;
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
    vector<int> ans = sol.productExceptSelf(nums);
    for (int i = 0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}