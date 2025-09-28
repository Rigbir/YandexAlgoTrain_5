//
// Created by Marat on 25.09.25.
//

#include <iostream>

int f(int i, int units, int barhp, int p) {
    int enemy = 0;
    int rounds = 0;

    while (barhp >= i) {
        if (enemy >= units) {
            return 1e9;
        }
        barhp -= units - enemy;
        enemy = 0;
        if (barhp >= 0) {
            enemy += p;
        }
        ++rounds;
    }

    while (barhp > 0) {
        if (units <= 0) {
            return 1e9;
        }
        if (barhp >= units) {
            barhp -= units;
        } else {
            enemy -= units - barhp;
            barhp = 0;
        }
        units -= enemy;
        if (barhp > 0) {
            enemy += p;
        }
        ++rounds;
    }

    while (enemy > 0) {
        if (units <= 0) {
            return 1e9;
        }
        enemy -= units;
        if (enemy > 0) {
            units -= enemy;
        }
        ++rounds;
    }

    return rounds;
}

int main() {
    int x, y, p;
    std::cin >> x >> y >> p;

    int ans = 1e9;
    for (int i = 0; i < y + 2; ++i) {
        ans = std::min(ans, f(i, x, y, p));
    }

    if (ans != 1e9) {
        std::cout << ans;
    } else {
        std::cout << -1;
    }
}