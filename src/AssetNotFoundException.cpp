#include "AssetNotFoundException.hpp"

AssetNotFoundException::AssetNotFoundException(std::string msg){
    this->message = msg;
}

std::string AssetNotFoundException::msg(){
    return this->message;
}
