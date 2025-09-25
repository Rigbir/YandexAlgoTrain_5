//
// Created by Marat on 25.09.25.
//

#include <iostream>

int main() {
    int p, v, q, m;
    std::cin >> p >> v >> q >> m;

    int l1 = p - v, r1 = p + v;
    int l2 = q - m, r2 = q + m;

    int first = r1 - l1 + 1;
    int second = r2 - l2 + 1;

    int interLeft = std::max(l1, l2);
    int interRight = std::min(r1, r2);
    int inter = 0;
    if (interLeft <= interRight) {
        inter = interRight - interLeft + 1;
    }

    std::cout << (first + second - inter);
}