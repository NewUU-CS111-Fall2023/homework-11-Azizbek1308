/*
 * Author:
 * Date:
 * Name:
 */

#include <iostream>
#include <vector>

using namespace std;

class Problem1 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        if (sum < target || (sum + target) % 2 != 0) {
            return 0;
        }

        int subsetSum = (sum + target) / 2;
        int n = nums.size();
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = subsetSum; j >= nums[i]; j--) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[subsetSum];
    }
};

int main() {
    Problem1 problem;
    vector<int> nums = {2, 1};
    int target = 1;
    int result = problem.findTargetSumWays(nums, target);
    cout << "Number of different expressions: " << result << endl;

    return 0;
}
