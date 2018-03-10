//
//  Model.hpp
//  oF_OSC_ReceiverSample
//
//  Created by HirokiNaganuma on 2018/03/10.
//

#ifndef Model_hpp
#define Model_hpp

#include "ofMain.h"

class Model{
public:
    static int x;
    static int y;
    static int z;
    static int interaction_value;

    static void setup();
    static void update();
    static void draw();

    static void update_values(int x, int y, int z, int interaction_value);
};

#endif /* Model_hpp */
