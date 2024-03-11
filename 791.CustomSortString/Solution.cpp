#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> freq;
        string ans = "";
        for (int i = 0;i<s.length();i++){
            freq[s[i]]++;
        }
        for (int i = 0;i<order.length();i++){
            if (freq.count(order[i])){
                for (int j=0;j<freq[order[i]];j++ ){
                    ans+=order[i];
                }
                freq[order[i]] = 0;
            }
        }

        for (auto it : freq){
            if (it.second!=0){
                for (int i = 0;i<it.second;i++){
                    ans+=it.first;
                }
            }
        }
        return ans;
    }
};

int main(){
    string order, s;
    cin >> order >> s;
    Solution sol;
    cout << sol.customSortString(order, s) << endl;
    return 0;
}