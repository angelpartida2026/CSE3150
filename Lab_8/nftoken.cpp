#include "nftoken.h"

nftoken::nftoken(const std::string& name, const std::string& hash)
    : name(name), hash(hash) {}

std::string nftoken::getName() const {
    return name;
}

std::string nftoken::getHash() const {
    return hash;
}
