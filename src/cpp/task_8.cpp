#include <iostream>

using namespace std;

class Problem8 {
public:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }

    int modInverse(int a, int m) {
        int m0 = m;
        int y = 0, x = 1;

        if (m == 1) {
            return 0;
        }

        while (a > 1) {
            int q = a / m;
            int t = m;

            m = a % m;
            a = t;
            t = y;

            y = x - q * y;
            x = t;
        }

        if (x < 0) {
            x += m0;
        }

        return x;
    }

    void generateKeys(int p, int q, int& e, int& d) {
        int n = p * q;
        int phi = (p - 1) * (q - 1);

        // Find e such that 1 < e < phi and gcd(e, phi) = 1
        for (e = 2; e < phi; e++) {
            if (gcd(e, phi) == 1) {
                break;
            }
        }

        // Find d such that d * e = 1 (mod phi)
        d = modInverse(e, phi);
    }
};

int main() {
    Problem8 problem;
    int p = 17;
    int q = 11;
    int e, d;
    problem.generateKeys(p, q, e, d);
    cout << "Generated e: " << e << endl;
    cout << "Generated d: " << d << endl;

    return 0;
}
