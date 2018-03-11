//
//  RippleView.hpp
//  oF_RippleVisualizer
//
//  Created by HirokiNaganuma on 2018/03/10.
//

#ifndef RippleView_hpp
#define RippleView_hpp

#include "ofxRipples.h"
#include "MacroManager.hpp"

class RippleView{
public:
    ofxRipples  rip;
    enum mode {
        RIPPLE,
        RANDOM_RIPPLE
    };
    mode effect_mode;

    ofVec2f position;
    float damping;

    RippleView(){};

    void setup(mode arg_mode);
    void update(ofVec3f position);
    void draw();
};

#endif /* RippleView_hpp */
