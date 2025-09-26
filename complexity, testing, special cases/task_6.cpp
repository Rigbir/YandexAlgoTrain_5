//
// Created by Marat on 25.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    std::vector<char> signs;
    int prev = std::abs(v[0]) % 2;
    for (int i = 1; i < n; ++i) {
        int curr = std::abs(v[i]) % 2;
        if (curr == 1) {
            if (prev == 1) {
                signs.push_back('x');
                prev = 1;
            } else {
                signs.push_back('+');
                prev = 1;
            }
        } else {
            signs.push_back('+');
        }
    }

    for (auto c : signs) {
        std::cout << c;
    }
}