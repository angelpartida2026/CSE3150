#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "Tokenizer.h"
#include <iostream>
#include <fstream>

TEST_CASE("Tokenizer Tests on the-verdict.txt") {
    Tokenizer tokenizer;
    tokenizer.processFile("the-verdict.txt");

    SUBCASE("These words exist") {
        CHECK(tokenizer.getToken("Jack") != -1);
        CHECK(tokenizer.getToken("Stroud") != -1);
        CHECK(tokenizer.getToken("painting") != -1);
    }

    SUBCASE("Token is consistent") {
        int token = tokenizer.getToken("Jack");
        CHECK(tokenizer.getWord(token) == "Jack");

        int token2 = tokenizer.getToken("Stroud");
        CHECK(tokenizer.getWord(token2) == "Stroud");
    }

    SUBCASE("Unknown word returns -1") {
        CHECK(tokenizer.getToken("apple") == -1);
    }

    SUBCASE("Invalid token returns empty string") {
        CHECK(tokenizer.getWord(-1) == "");
        CHECK(tokenizer.getWord(99999) == "");
    }

    SUBCASE("Duplicate word tokens are the same") {
        int t1 = tokenizer.getToken("painting");
        int t2 = tokenizer.getToken("painting");
        CHECK(t1 == t2);
    }
}


int main(int argc, char** argv) {
    doctest::Context context;
    context.applyCommandLine(argc, argv);

    int res = context.run();

    if (context.shouldExit()) {
        return res;
    }

    std::cout << "\n Tests have been completes. Press ENTER to continue the program\n";
    std::cin.get();

    Tokenizer tokenizer;
    tokenizer.processFile("the-verdict.txt");

    std::cout << "\n--- Main Program Output ---\n";
    tokenizer.printTokens();

    std::string word = "smiling";
    int token = tokenizer.getToken(word);
    std::cout << "\nToken for '" << word << "': " << token << "\n";

    int exampleToken = 23;
    std::cout << "Word for token " << exampleToken << ": " << tokenizer.getWord(exampleToken) << "\n";

    return res;
}
