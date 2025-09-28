//
// Created by Marat on 29.09.25.
//

#include <iostream>
#include <vector>
#include <climits>

int main() {
    int k;
    std::cin >> k;

    std::vector<std::pair<int, int>> v(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> v[i].first >> v[i].second;
    }

    int minX = INT_MAX;
    int maxX = INT_MIN;
    int minY = INT_MAX;
    int maxY = INT_MIN;

    for (size_t i = 0; i < v.size(); ++i) {
        if (minX > v[i].first) {
            minX = v[i].first;
        }
        if (maxX < v[i].first) {
            maxX = v[i].first;
        }

        if (minY > v[i].second) {
            minY = v[i].second;
        }
        if (maxY < v[i].second) {
            maxY = v[i].second;
        }
    }

    std::cout << minX << ' ' << minY << ' ' << maxX << ' ' << maxY;
}