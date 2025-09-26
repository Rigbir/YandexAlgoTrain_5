//
// Created by Marat on 25.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    long long count = 0;
    for (size_t i = 0; i < v.size(); ++i) {
        long long tabs = v[i] / 4;
        long long rem = v[i] % 4;
        count += tabs + std::min(rem, 5 - rem);
    }

    std::cout << count;
}