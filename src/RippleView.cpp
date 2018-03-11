//
//  RippleView.cpp
//  oF_RippleVisualizer
//
//  Created by HirokiNaganuma on 2018/03/10.
//

#include "RippleView.hpp"

void RippleView::setup(){
    rip.allocate(ofGetWidth(),ofGetHeight());
    rip.damping = MacroManager::default_damping;
}

void RippleView::update(ofVec3f position){
    rip.begin();
    ofFill();

    ofSetColor(ofNoise( ofGetFrameNum() ) * 127 * 5, 100);
//    ofSetColor(ofNoise( ofGetFrameNum() ) * 255 * 5, 255);
    
//    ofDrawEllipse(position.x, position.y, 5,5);
    
    int num_of_ripple = position.z;
    if(num_of_ripple<1)num_of_ripple =  1;
    if(ofGetElapsedTimeMillis()%1000 < 50){
        for(int i = 0; i < num_of_ripple; i++){
            ofDrawEllipse(ofRandom(MacroManager::roomba_frame_margin,MacroManager::roomba_frame_max_height-2*MacroManager::roomba_frame_margin),
                          ofRandom(MacroManager::roomba_frame_margin,MacroManager::roomba_frame_max_width -2*MacroManager::roomba_frame_margin),
                          5,5);
        }
    }
    
    
    rip.end();
    rip.update();
}

void RippleView::draw(){
    ofBackground(0);
    ofSetColor(255,255);

    rip.draw(0,0);
//    ofDrawBitmapString("ofxRipples ( damping = " + ofToString(rip.damping) + " )", 15,15);
}
