#ifndef RESOURCE_HPP
#define RESOURCE_HPP
#include <string>

class AssetManager;

template<typename T>
class Resource{
    friend AssetManager;
private:
    unsigned int amountReferences;
protected:
    std::string path;
    T resourceData;
    int uniqueNumber;
public:
    Resource(std::string path,int uniqueNumber) : path(path), uniqueNumber(uniqueNumber){}
    std::string getPath() const{
        return this->path;
    }
    int getUniqueNumber() const{
        return this->uniqueNumber;
    }
    virtual void destroy() = 0;
};



#endif