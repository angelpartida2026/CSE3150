#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <unordered_map>
#include <vector>

class Tokenizer {
public:
    void processFile(const std::string& filename);
    int getToken(const std::string& word) const;
    std::string getWord(int token) const;
    void printTokens() const;

private:
    std::unordered_map<std::string, int> wordToToken;
    std::vector<std::string> tokenToWord;
};

#endif
