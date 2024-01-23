#include <iostream>
#include <vector>

using namespace std;

class Problem4 {
public:
    int superPow(int a, vector<int>& b) {
        int result = 1;
        for (int digit : b) {
            result = (powMod(result, 10) * powMod(a, digit)) % 1337;
        }
        return result;
    }

private:
    int powMod(int x, int n) {
        if (n == 0) {
            return 1;
        }
        x %= 1337;
        int result = 1;
        for (int i = 0; i < n; i++) {
            result = (result * x) % 1337;
        }
        return result;
    }
};

int main() {
    Problem4 problem;
    int a = 2;
    vector<int> b = {1, 0};
    int result = problem.superPow(a, b);
    cout << "Result: " << result << endl;

    return 0;
}
