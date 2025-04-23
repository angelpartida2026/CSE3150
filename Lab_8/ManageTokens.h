#ifndef MANAGETOKENS_H
#define MANAGETOKENS_H
#include "nftoken.h"
#include <vector>
#include <memory>
#include <string>

class ManageTokens {
public:
    std::unique_ptr<nftoken> mint(const std::string& name);
    void transfer(std::vector<std::unique_ptr<nftoken>>& toWallet, std::vector<std::unique_ptr<nftoken>>& fromWallet, std::vector<std::unique_ptr<nftoken>>::iterator pos);
};

#endif
