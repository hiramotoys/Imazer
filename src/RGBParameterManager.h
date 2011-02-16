#ifndef RGBParameterManager_H
#define RGBParameterManager_H

#inluce "Threshold.h"

class RGBParameterManager{
 public:
    Threshold red;
    Threshold green;
    Threshold blue;
    RGBParameterManager();
    ~RGBParameterManager();
    void setRed(int fr, int to);
    void setGreen(int fr, int to);
    void setBlue(int fr, int to);
};

#endif // RGBParameterManager
