//
// Created by Marat on 1.10.25.
//

#include <iostream>
#include <vector>

int binSearch(int l, int r, int x, long long s, const std::vector<long long>& pref) {
    while (l <= r) {
        int m = (l + r) / 2;
        long long sum = pref[m + x] - pref[m];
        if (sum == s) {
            return m + 1;
        }
        if (sum < s) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return -1;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }

    std::vector<long long> pref(v.size() + 1);
    pref[0] = 0;
    for (size_t i = 1; i < pref.size(); ++i) {
        pref[i] = pref[i - 1] + v[i - 1];
    }

    std::vector<std::pair<int, long long>> p(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> p[i].first >> p[i].second;
    }

    for (int i = 0; i < m; ++i) {
        int res = binSearch(0, n - p[i].first, p[i].first, p[i].second, pref);
        std::cout << res << '\n';
    }
}