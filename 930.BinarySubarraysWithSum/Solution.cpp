#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // Prefix Sum
        int ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        mp[nums[0]]++;
        if (nums[0] == goal){
            ans++;
        }
        for (int i = 1;i<nums.size();i++){
            nums[i] += nums[i-1];
            int a = nums[i] - goal;
            if (mp.count(a)){
                ans+=mp[a];
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,0,1,0,1};
    int goal = 2;
    cout << sol.numSubarraysWithSum(nums, goal) << endl;
    return 0;
}