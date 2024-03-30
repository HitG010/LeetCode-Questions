#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int start = 0;
        unordered_map<int, int> mp;
        int ans = 0;
        int count = 0;
        int temp = -1;
        for (int end = 0;end<nums.size();end++){
            if (mp[nums[end]] == 0){
                count++;
                if (count>k){
                    temp = start;
                }
            }
            mp[nums[end]]++;
            while(count>=k){
               if (mp[nums[start]] == 1 && count == k){
                break;
               }
               mp[nums[start]]--;
               if (mp[nums[start]] == 0){
                count--;
               }
               start++; 
            }
            if (count == k){
                ans += (start - temp);
            }
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
    cout << obj.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}