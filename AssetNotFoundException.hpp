#ifndef ASSET_NOT_FOUND_EXCEPTION_HPP
#define ASSET_NOT_FOUND_EXCEPTION_HPP
#include <string>

class AssetNotFoundException : public std::exception{
private:
    std::string message;
public:
    AssetNotFoundException(std::string);
    std::string msg();
};

#endif