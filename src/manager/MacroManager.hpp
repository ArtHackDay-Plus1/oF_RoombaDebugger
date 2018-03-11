//
//  MacroManager.hpp
//  oF_OSC_ReceiverSample
//
//  Created by HirokiNaganuma on 2018/03/10.
//

#ifndef MacroManager_hpp
#define MacroManager_hpp

#include <stdio.h>
#include <string>

namespace MacroManager {
    //    const int projectorWidth = 1920;
    //    const int projectorHeight = 1080;
    const int osc_port_num = 8017;
    
    const int interactive_value_min = 0;
    const int interactive_value_max = 100;
    
    const float default_damping = 0.99;

    // ------

    const float scaling_factor = 5;

    const float frame_width = 2700;
    const float frame_height = 1200;

    const int frame_margin = 300;

    const float kinect_width = 200;
    const float kinect_height = 50;

    const float distance_kinect_to_frame = 4700;

    const float scaling_frame_width = 540;
    const float scaling_frame_height = 240;

    const float scaling_kinect_width = 40;
    const float scaling_kinect_height = 10;

    const float scaling_distance_kinect_to_frame = 700;

};

#endif /* MacroManager_hpp */
