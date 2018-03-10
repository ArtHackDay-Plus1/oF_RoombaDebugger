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

    ofSetColor(ofNoise( ofGetFrameNum() ) * 255 * 5, 255);
    ofDrawEllipse(position.x, position.y, 5,5);
    rip.end();
    rip.update();
}

void RippleView::draw(){
    ofBackground(0);
    ofSetColor(255,255);

    rip.draw(0,0);
    ofDrawBitmapString("ofxRipples ( damping = " + ofToString(rip.damping) + " )", 15,15);
}
