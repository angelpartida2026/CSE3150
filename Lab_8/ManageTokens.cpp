#include "ManageTokens.h"
#include <openssl/sha.h>
#include <sstream>
#include <iomanip>

std::string generateHash(const std::string& input) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(reinterpret_cast<const unsigned char*>(input.c_str()), input.size(), hash);

    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    return ss.str();
}

std::unique_ptr<nftoken> ManageTokens::mint(const std::string& name) {
    return std::make_unique<nftoken>(name, generateHash(name));
}

void ManageTokens::transfer(std::vector<std::unique_ptr<nftoken>>& toWallet, std::vector<std::unique_ptr<nftoken>>& fromWallet, std::vector<std::unique_ptr<nftoken>>::iterator pos) {
    toWallet.push_back(std::move(*pos));
    fromWallet.erase(pos);
}
