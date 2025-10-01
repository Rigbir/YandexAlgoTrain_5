//
// Created by Marat on 1.10.25.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

int lBinSearch(int l, int r, int x, const std::vector<int>& v) {
    while (l < r) {
        int m = (l + r) / 2;
        if (v[m] < x) {
            l = m + 1;
        } else {
            r = m;
        }
    }

    return l;
}

int rBinSearch(int l, int r, int x, const std::vector<int>& v) {
    while (l < r) {
        int m = (l + r + 1) / 2;
        if (v[m] > x) {
            r = m - 1;
        } else {
            l = m;
        }
    }

    return l;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    std::ranges::sort(v);

    int k;
    std::cin >> k;
    std::vector<std::pair<int, int>> p(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> p[i].first >> p[i].second;
    }

    std::vector<int> result;
    for (int i = 0; i < k; ++i) {
        int right = rBinSearch(0, n - 1, p[i].second, v);
        int left = lBinSearch(0, n - 1, p[i].first, v);

        if (v[left] < p[i].first) ++left;
        if (v[right] > p[i].second) --right;

        int count = (left > right ? 0 : (right - left + 1));
        result.push_back(count);
    }

    for (auto i : result) {
        std::cout << i << ' ';
    }
}