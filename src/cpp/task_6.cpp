#include <iostream>
#include <vector>

using namespace std;

class Problem6 {
public:
    bool isPrime(int num) {
        if (num <= 1) {
            return false;
        }

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }

        return true;
    }

    vector<int> generatePrimesGreaterThanN(int n) {
        vector<int> primes;

        int num = n + 1;
        while (primes.size() < 2) {
            if (isPrime(num)) {
                primes.push_back(num);
            }
            num++;
        }

        return primes;
    }
};

int main() {
    Problem6 problem;
    int n = 10;
    vector<int> result = problem.generatePrimesGreaterThanN(n);
    cout << "Two prime numbers greater than " << n << ": " << result[0] << " and " << result[1] << endl;

    return 0;
}
