#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    bool isPalyndromRecur(string s, int start, int end) {
        if(start > end) return true;
        return (s[start] == s[end]) && isPalyndrom(s, start + 1, end - 1);
    }
    bool isPalyndrom(string s, int start, int end) {
        while(start < end){
            if(s[start] != s[end]){
                return false;
            }
            start++, end--;
        }
        return true;
    } 
    
    
    void solve(vector<vector<string>>& sols, vector<string>& curr, string s, int start) {
        
        if(start >= s.size()){
            sols.push_back(*new vector<string>(curr.begin(), curr.end()));
            return;
        }
        
        
        for(int end = start; end < s.size(); end++){
            
            if(isPalyndrom(s, start, end)){
                
                curr.push_back(s.substr(start, end - start + 1));
                solve(sols, curr, s, end + 1);
                curr.pop_back();
            
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> sols = *new vector<vector<string>>();
        vector<string> curr = *new vector<string>();
        
        solve(sols, curr, s, 0);
        return sols;
    }
    
    
};


int main() {
    

    vector<vector<string>> exp = *new vector<vector<string>>();
    // exp.reserve(2);
    // exp[0] = *new vector<string>({"a","a","b"});
    // exp[1] = *new vector<string>({"aa","b"});
    exp.push_back(*new vector<string>({"a","a","b"}));
    exp.push_back(*new vector<string>({"aa","b"}));
    for(int i = 0 ; i < exp.size() ; i++){
        for (string x : exp[i]) 
            cout << x << " "; 
        cout << endl; 
    }

    vector<vector<string>> res = Solution().partition("aab");
    
    

    for(int i = 0 ; i < res.size() ; i++){
        for(int j = 0 ; j < res[i].size() ; j++){
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }


    assert(res.size() == exp.size());
    bool isCorrect;
    for(int i = 0 ; i < res.size() ; i++){
        isCorrect = false;
        assert(res[i] == exp[i]);
        isCorrect = true;
    }
    
    cout << "String was" << (isCorrect ? "" : " not ") << " correctly partitioned" << endl;

    cout << "Program is Exiting Successfully" << endl;
    return 0;
}