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
    mRippleView.update(ofVec3f(Model::x,
                               Model::y,
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
