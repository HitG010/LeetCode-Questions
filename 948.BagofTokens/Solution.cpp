#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int ans = 0;
        int score = 0;
        sort(tokens.begin(), tokens.end());
        int i = 0;
        int j = tokens.size()-1;

        while(i<=j){
            if (power>=tokens[i]){
                score++;
                power-=tokens[i];
                i++;
            }
            else if (score>0){
                score--;
                power+=tokens[j];
                j--;
            }
            else{
                break;
            }
            ans = max(ans,score);
        }
        return ans;
    }
};


int main(){
    int n;
    cin >> n;
    vector<int> tokens;
    for (int i = 0; i < n;i++){
        int a;
        cin >> a;
        tokens.push_back(a);
    }
    int power;
    cin >> power;
    Solution s;
    cout<<s.bagOfTokensScore(tokens, power)<<endl;
}