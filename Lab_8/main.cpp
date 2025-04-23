#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "nftoken.h"
#include "ManageTokens.h"
#include <iostream>
#include <memory>
#include <vector>
using namespace std;

void printWallet(const vector<unique_ptr<nftoken>>& wallet, const string& name) {
    cout << name << ":\n";
    for (const auto& token : wallet) {
        cout << "  Name: " << token->getName() << "\n";
        cout << "  Hash: " << token->getHash() << "\n";
    }
    cout << endl;
}

TEST_CASE("Minting and Transferring NFTs") {
    ManageTokens manager;
    vector<unique_ptr<nftoken>> walletA;
    vector<unique_ptr<nftoken>> walletB;

    auto nft1 = manager.mint("JonathanHusky");
    auto nft2 = manager.mint("C++ Essentials");
    walletA.push_back(move(nft1));
    walletA.push_back(move(nft2));
    CHECK(walletA.size() == 2);
    CHECK(walletB.empty());

    manager.transfer(walletB, walletA, walletA.begin() + 1);

    CHECK(walletA.size() == 1);
    CHECK(walletB.size() == 1);
    CHECK(walletA.size() != 2);
    CHECK(walletB.size() != 0);
    CHECK(walletA[0]->getName() == "JonathanHusky");
    CHECK(walletB[0]->getName() == "C++ Essentials");
}

TEST_CASE("Multiple Transfers and Hash Uniqueness") {
    ManageTokens manager;

    auto token1 = manager.mint("NFT 1");
    auto token2 = manager.mint("NFT 2");
    CHECK(token1->getHash() != token2->getHash());

    vector<unique_ptr<nftoken>> walletA;
    vector<unique_ptr<nftoken>> walletB;

    walletA.push_back(move(token1));
    walletA.push_back(move(token2));

    manager.transfer(walletB, walletA, walletA.begin());

    CHECK(walletA.size() == 1);
    CHECK(walletB.size() == 1);
    CHECK(walletA.size() != 2);
    CHECK(walletB.size() != 0);
    CHECK(walletB[0]->getName() == "NFT 1");
    CHECK(walletA[0]->getName() == "NFT 2");
}

int main(int argc, char** argv) {
    cout << "Before Transfer:\n";
    ManageTokens manager;
    vector<unique_ptr<nftoken>> walletA;
    vector<unique_ptr<nftoken>> walletB;

    auto nft1 = manager.mint("JonathanHusky");
    auto nft2 = manager.mint("C++ Essentials");
    walletA.push_back(move(nft1));
    walletA.push_back(move(nft2));
    printWallet(walletA, "Wallet A");
    printWallet(walletB, "Wallet B");

    manager.transfer(walletB, walletA, walletA.begin() + 1);

    cout << "\nAfter Transfer:\n";
    printWallet(walletA, "Wallet A");
    printWallet(walletB, "Wallet B");
    cout << "\n--- Unit Testing ---\n";
    return doctest::Context(argc, argv).run();
}
