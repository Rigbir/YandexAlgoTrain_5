//
// Created by Marat on 29.09.25.
//

#include <iostream>
#include <string>

void f(int n) {
    int count = 0;
    std::string result = "";

    int num;
    std::cin >> num;
    int currentMin = num;
    int currentLength = 1;

    for (int i = 1; i < n; ++i) {
        std::cin >> num;

        if (currentMin == currentLength || num < currentLength + 1) {
            ++count;
            result += std::to_string(currentLength) + " ";
            currentLength = 1;
            currentMin = num;
        } else {
            currentLength += 1;
            currentMin = std::min(num, currentMin);
        }
    }

    ++count;
    std::cout << count << '\n';

    result += std::to_string(currentLength) + "\n";
    std::cout << result;
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;
        f(n);
    }
}