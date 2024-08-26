class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        for(char ch : num){
            while(k > 0 && !ans.empty() && ans.back() > ch){
                ans.pop_back();
                k--;
            }
            ans.push_back(ch);
        }

        while(k > 0 && !ans.empty()){
            ans.pop_back();
            k--;
        }

        while(!ans.empty() && ans[0] == '0'){
            ans.erase(ans.begin());
        }
        return ans.empty() ? "0" : ans;
    }
};
