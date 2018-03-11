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
    
    const int roomba_frame_max_width = 1200;
    const int roomba_frame_max_height = 2700;
    
    const int roomba_frame_margin = 300;

};

#endif /* MacroManager_hpp */
