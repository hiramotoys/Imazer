#include "RGBParameterManager.h"

RGBParameterManager::RGBParameterManager(){
}

RGBParameterManager::~RGBParameterManager(){
}

void RGBParameterManager::setRed(int fr, int to){
    red.fr = fr;
    red.to = to;
}

void RGBParameterManager::setGreen(int fr, int to){
    green.fr = fr;
    green.to = to;
}

void RGBParameterManager::setBlue(int fr, int to){
    blue.fr = fr;
    blue.to = to;
}
