#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 1;
        int start = 0;
        mp[nums[0]]++;
        for (int end = 1;end<nums.size();end++){
            mp[nums[end]]++;
            int a = mp[nums[end]];
            while(a>k && start<end){
                mp[nums[start]]--;
                a = mp[nums[end]];
                start++;
            }
            ans = max(ans, end-start+1);
        }
        return ans;
    }
};

int main(){
    string s;
    getline(cin, s);
    vector<int> nums;
    for (int i = 0;i<s.size();i++){
        if (s[i]>='0' && s[i]<='9'){
            int temp = 0;
            while(i<s.size() && s[i]>='0' && s[i]<='9'){
                temp = temp*10 + (s[i]-'0');
                i++;
            }
            nums.push_back(temp);
        }
    }
    int k;
    cin >> k;
    Solution obj;
    cout << obj.maxSubarrayLength(nums, k) << endl;
    return 0;
}