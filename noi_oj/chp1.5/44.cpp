#include <iostream>

using namespace std;

bool isPrime(unsigned long n) {
    if (n <= 3) {
        return n > 1;
    } 
    else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    else {
        for (long long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}


int main(int argc, char const *argv[])
{
    long n;
    cin >> n;
    int cnt = 0;
    for (long i = 2; i <= 10000000; i++) {
        if (isPrime(i)) {
            cnt++;
        }
        if (cnt == n) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}