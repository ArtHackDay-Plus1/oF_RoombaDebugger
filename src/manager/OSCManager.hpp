//
//  OSCManager.hpp
//  oF_OSC_ReceiverSample
//
//  Created by HirokiNaganuma on 2018/03/10.
//

#ifndef OSCManager_hpp
#define OSCManager_hpp


#include "ofMain.h"
#include "ofxOsc.h"
#include "MacroManager.hpp"
#include "Model.hpp"

class OSCManager{
public:
    static string latest_updated_time;

    static ofxOscReceiver receiver;
    static ofxOscMessage message;
    
    static void setup();
    static void update();
    static void draw();
};


#endif /* OSCManager_hpp */
