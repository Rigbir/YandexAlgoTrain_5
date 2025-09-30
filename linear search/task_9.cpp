//
// Created by Marat on 29.09.25.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i].first >> v[i].second;
    }

    std::sort(v.begin(), v.end(), [](auto &a, auto &b){ return a.first < b.first; });

    int ans = 1e9;
    for (int col = 1; col < n + 1; ++col) {
        int now = 0;
        for (int i = 0; i < n; ++i) {
            now += std::abs(v[i].first - (i + 1)) + std::abs(v[i].second - col);
        }
        ans = std::min(ans, now);
    }

    std::cout << ans;
}