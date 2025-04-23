#ifndef NFTOKEN_H
#define NFTOKEN_H
#include <string>

class nftoken {
private:
    std::string name;
    std::string hash;

public:
    nftoken(const std::string& name, const std::string& hash);
    std::string getName() const;
    std::string getHash() const;
};

#endif

