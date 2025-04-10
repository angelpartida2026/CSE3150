#include "Tokenizer.h"
#include <fstream>
#include <iostream>
#include <regex>

void Tokenizer::processFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::regex word_regex(R"(\b\w+\b)");

    while (getline(file, line)) {
        auto words_begin = std::sregex_iterator(line.begin(), line.end(), word_regex);
        auto words_end = std::sregex_iterator();

        for (std::sregex_iterator it = words_begin; it != words_end; ++it) {
            std::string word = it->str();
            if (wordToToken.find(word) == wordToToken.end()) {
                int token = tokenToWord.size();
                wordToToken[word] = token;
                tokenToWord.push_back(word);
            }
        }
    }
}

int Tokenizer::getToken(const std::string& word) const {
    auto it = wordToToken.find(word);
    if (it != wordToToken.end()) {
        return it->second;
    }
    return -1;
}

std::string Tokenizer::getWord(int token) const {
    if (token >= 0 && token < (int)tokenToWord.size()) {
        return tokenToWord[token];
    }
    return "";
}

void Tokenizer::printTokens() const {
    for (const auto& pair : wordToToken) {
        std::cout << pair.first << " => " << pair.second << "\n";
    }
}
