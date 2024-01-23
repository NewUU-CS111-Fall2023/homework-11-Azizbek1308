#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Problem3 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordSet.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};

int main() {
    Problem3 problem;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool result = problem.wordBreak(s, wordDict);
    cout << "Can be segmented: " << (result ? "true" : "false") << endl;

    return 0;
}
