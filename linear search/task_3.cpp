//
// Created by Marat on 29.09.25.
//

#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    int sum = 0;
    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
        sum += v[i];
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        count = std::max(count, 2 * v[i] - sum);
        if (count < 0) count = 0;
    }

    if (count <= 0) {
        count = sum;
    }

    std::cout << count;
}