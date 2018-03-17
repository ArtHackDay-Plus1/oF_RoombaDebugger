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

    static void setup();
    static void update();

    //========[RECEIVER]========
    static ofxOscReceiver receiver;
    static ofxOscMessage message;

    static void setup_receiver();
    static void update_receiver();
    //========[RECEIVER]========

    //========[SENDER]========
    static ofxOscSender sender;

    static void setup_sender();
    static void update_sender();
    //========[SENDER]========
};


#endif /* OSCManager_hpp */
