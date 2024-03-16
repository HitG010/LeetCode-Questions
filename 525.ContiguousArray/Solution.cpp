#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sum = 0;
        int ans = 0;
        for (int i = 0;i<nums.size();i++){
            if (nums[i] == 0){
                sum--;
            }
            else{
                sum++;
            }
            if (mp.count(sum)){
                ans = max(ans,i-mp[sum]);
            }
            else{
                mp[sum] = i;
            }
        }
        return ans;
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
    cout << sol.findMaxLength(nums) << endl;
}