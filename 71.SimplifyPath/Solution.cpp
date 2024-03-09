#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

class Solution {
    string ans = "";

    void solve(stack<string>& files){
        if (files.empty()){
            return;
        }
        string file = files.top();
        files.pop();
        solve(files);
        ans+='/';
        ans+=file;
    }
public:
    string simplifyPath(string path) {
        stack<string> files;
        int i = 0;
        while (i<path.length()){
            string file = "";
           while(path[i]!='/' && i<path.length()){
               file+=path[i];
               i++;
           }
           if (file == ".."){
               if (files.size()>0)
                    files.pop();
           }
           else if (file == "." || file == ""){
               i++;
               continue;
           }
           else{
               files.push(file);
           }
           i++;
        }

        solve(files);
        return ans == "" ? "/" : ans;
    }
};


int main(){
    string input;
    cin >> input;
    Solution s;
    cout << s.simplifyPath(input);
}