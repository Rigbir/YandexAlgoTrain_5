//
// Created by Marat on 30.09.25.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string wordInDict;
    std::getline(std::cin, wordInDict);

    std::vector<std::string> wordsInDictionary;
    {
        std::istringstream iss(wordInDict);
        std::string word;
        while (iss >> word) {
            wordsInDictionary.push_back(word);
        }
    }

    std::sort(wordsInDictionary.begin(), wordsInDictionary.end(),
            [](const std::string& s1, const std::string& s2) {
                return s1.size() < s2.size();
            });

    std::string text;
    std::getline(std::cin, text);

    std::istringstream iss(text);
    std::string word;
    bool first = true;
    while (iss >> word) {
        std::string replaced = word;
        for (const auto& pref : wordsInDictionary) {
            if (word.rfind(pref, 0) == 0) {
                replaced = pref;
                break;
            }
        }
        if (!first) std::cout << " ";
        std::cout << replaced;
        first = false;
    }
}