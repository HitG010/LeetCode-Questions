#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones = 0;
        int zeros = 0;
        for (int i = 0;i<s.length();i++){
            if (s[i] == '1'){
                ones++;
            }
            else{
                zeros++;
            }
        }
        cout<<ones<<" "<<zeros<<endl;

        string ans = "";
        for (int i = 1;i<ones;i++){
            ans+='1';
        }
        for (int i = 0;i<zeros;i++){
            ans+='0';
        }
        ans+='1';
        return ans;
    }
};