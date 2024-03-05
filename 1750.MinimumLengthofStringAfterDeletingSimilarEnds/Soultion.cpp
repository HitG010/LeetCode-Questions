#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            char a = s[i];
            char b = s[j];
            if (a == b){
                while (s[i] == a && i<=j){
                    i++;
                }
                while(s[j] == b && i<=j){
                    j--;
                }
            }
            else{
                break;
            }
        }
        if (j<i){
            return 0;
        }
        return j-i+1;
    }
};

int main(){
    string s;
    cin >> s;
    Solution sol;
    cout << sol.minimumLength(s) << endl;
}