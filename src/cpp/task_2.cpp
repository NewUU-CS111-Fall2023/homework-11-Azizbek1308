/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Problem2 {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        if (totalSum % 2 != 0) {
            return false;
        }

        int targetSum = totalSum / 2;
        int n = nums.size();
        vector<bool> dp(targetSum + 1, false);
        dp[0] = true;

        for (int num : nums) {
            for (int j = targetSum; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[targetSum];
    }
};

int main() {
    Problem2 problem;
    vector<int> nums = {1, 5, 11, 5};
    bool result = problem.canPartition(nums);
    cout << "Can partition the array: " << (result ? "true" : "false") << endl;

    return 0;
}
