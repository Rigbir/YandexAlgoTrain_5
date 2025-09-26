//
// Created by Marat on 25.09.25.
//

#include <iostream>
#include <string>

int main() {
    long long n, k, d;
    std::cin >> n >> k >> d;

    std::string output = std::to_string(n);
    long long mod = n % k;

    for (int i = 0; i < d; ++i) {
        bool found = false;
        for (int j = 0; j <= 9; ++j) {
            if ((mod * 10 + j) % k == 0) {
                output.push_back('0' + j);
                mod = 0;
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << -1;
            return 0;
        }
    }

    std::cout << output;
}