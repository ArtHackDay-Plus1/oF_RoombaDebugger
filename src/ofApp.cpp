#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    OSCManager::setup();
    mRippleView.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    OSCManager::update();
//    mRippleView.update(ofVec3f(mouseX,mouseY,0));
    
    // switch x,y
    mRippleView.update(ofVec3f(ofMap(Model::y,0,MacroManager::roomba_frame_max_height,0,ofGetWidth()),
                               ofMap(Model::x,0,MacroManager::roomba_frame_max_width,0,ofGetHeight()),
                               Model::z));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetWindowTitle("Model::interaction_value: "+ofToString(Model::interaction_value));
    mRippleView.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
