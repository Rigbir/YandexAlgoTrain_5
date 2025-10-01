//
// Created by Marat on 1.10.25.
//

#include <iostream>

using int64 = long long;
using i128 = __int128_t;

bool can(int64 n, int64 k) {
    i128 L = static_cast<i128>(k) * (k + 1) * (k + 5) / 6 - 1;
    return n >= L;
}

int64 binSearch(int64 n) {
    int64 l = 0, r = 1;

    while (can(n, r)) {
        r *= 2;
        if (r > static_cast<int64>(2e6)) {
            r = 2e6;
            break;
        }
    }

    while (l < r) {
        int64 m = (l + r + 1) / 2;
        if (can(n, m)) {
            l = m;
        } else {
            r = m - 1;
        }
    }

    return l;
}

int main() {
    int64 n;
    std::cin >> n;
    std::cout << binSearch(n);
}