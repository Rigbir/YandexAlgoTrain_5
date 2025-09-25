//
// Created by Marat on 25.09.25.
//

#include <iostream>
#include <string>

int main() {
    int g1_left, g1_right;
    char sep;
    std::cin >> g1_left >> sep >> g1_right;

    int g2_left, g2_right;
    std::cin >> g2_left >> sep >> g2_right;

    int place;
    std::cin >> place;

    int sum1 = g1_left + g2_left;
    int sum2 = g1_right + g2_right;

    int count = 0;
    if (sum1 > sum2) {
        std::cout << 0;
    } else if (sum1 < sum2) {
        count = sum2 - sum1;
        if (place == 1) {
            if (count + g2_left <= g1_right) {
                count += 1;
            }
        } else if (place == 2) {
            if (g1_left <= g2_right) {
                count += 1;
            }
        }
    } else {
        if (place == 1) {
            if (g2_left <= g1_right) {
                count = 1;
            }
        } else if (place == 2) {
            if (g1_left <= g2_right) {
                count = 1;
            }
        }
    }

    std::cout << count;
}

