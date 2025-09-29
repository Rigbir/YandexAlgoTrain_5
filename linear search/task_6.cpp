//
// Created by Marat on 29.09.25.
//

#include <iostream>
#include <vector>

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int sectors, minSpeed, maxSpeed, stopSpeed;
    std::cin >> sectors;

    std::vector<int> scores(sectors);
    for (int i = 0; i < sectors; ++i) {
        std::cin >> scores[i];
    }

    std::cin >> minSpeed >> maxSpeed >> stopSpeed;

    int maxScoreInWheel = 0;
    for (auto x : scores) {
        maxScoreInWheel = std::max(x, maxScoreInWheel);
    }

    int maxScore = 0;
    for (int speed = minSpeed; speed <= stopSpeed + 1 && speed <= maxSpeed; ++speed) {
        if (speed <= stopSpeed) {
            maxScore = std::max(maxScore, scores[0]);
            continue;
        }
        int currentSector = ((speed - 1) / stopSpeed) % sectors;
        maxScore = std::max(maxScore, scores[currentSector]);
        if (currentSector != 0) {
            maxScore = std::max(maxScore, scores[sectors - currentSector]);
        }

        if (maxScore == maxScoreInWheel) break;
    }

    int initialSpeed = stopSpeed + 1;
    if (initialSpeed < minSpeed || initialSpeed > maxSpeed) {
        initialSpeed = minSpeed;
    }

    for (int speed = initialSpeed; speed <= maxSpeed; speed += stopSpeed) {
        if (speed <= stopSpeed) {
            maxScore = std::max(maxScore, scores[0]);
            continue;
        }
        int currentSector = ((speed - 1) / stopSpeed) % sectors;
        maxScore = std::max(maxScore, scores[currentSector]);
        if (currentSector != 0) {
            maxScore = std::max(maxScore, scores[sectors - currentSector]);
        }

        if (maxScore == maxScoreInWheel) break;
    }

    std::cout << maxScore;
}