#include <iostream>

using namespace std;

class Problem7 {
public:
    int eulerFunction(int a, int b) {
        return (a - 1) * (b - 1);
    }
};

int main() {
    Problem7 problem;
    int a = 3;
    int b = 5;
    int result = problem.eulerFunction(a, b);
    cout << "Euler function of " << a << " * " << b << ": " << result << endl;

    return 0;
}
