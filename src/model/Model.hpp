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

    static int nearest_y;
    static int nearest_depth;
    static int num_of_people;

    static void update_values(int nearest_y, int nearest_depth, int num_of_people);
    static void update_values(int nearest_y, int nearest_depth);
};

#endif /* Model_hpp */
