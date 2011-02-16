#include "RGBParameterManager.h"

RGBParameterManager::RGBParameterManager(){
}

RGBParameterManager::~RGBParameterManager(){
}

RGBParameterManager::setRed(int fr, int to){
    red.fr = fr;
    red.to = to;
}

RGBParameterManager::setGreen(int fr, int to){
    green.fr = fr;
    green.to = to;
}

RGBParameterManager::setBlue(int fr, int to){
    blue.fr = fr;
    blue.to = to;
}
