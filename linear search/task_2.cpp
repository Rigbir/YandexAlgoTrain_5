//
// Created by Marat on 29.09.25.
//

#include <iostream>
#include <vector>
#include <climits>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    int cost = 0;
    for (int day = 0; day < n; ++day) {
        for (int sell = day + 1; sell <= std::min(n - 1, day + k); ++sell) {
            cost = std::max(cost, v[sell] - v[day]);
        }
    }

    std::cout << cost;
}