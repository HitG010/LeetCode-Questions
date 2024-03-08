#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101, 0);
        int maxFreq = INT_MIN;
        for (int i = 0;i<nums.size();i++){
            freq[nums[i]]++;
            maxFreq = max(maxFreq, freq[nums[i]]);
        }
        int ans = 0;
        for (int i = 0;i<101;i++){
            if (maxFreq == freq[i]){
                ans++;
            }
        }
        return ans*maxFreq;
    }
};

int main(){
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n;i++){
        int a;
        cin >> a;
        nums.push_back(a);

    }

    Solution s;
    cout << s.maxFrequencyElements(nums) << endl;
}