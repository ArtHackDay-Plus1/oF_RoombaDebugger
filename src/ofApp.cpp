#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofToggleFullscreen();
    OSCManager::setup();
//    mRippleView.setup(RippleView::RANDOM_RIPPLE);
    mRippleView.setup(RippleView::RIPPLE);

}

//--------------------------------------------------------------
void ofApp::update(){
    OSCManager::update();
    
    // switch x,y
    mRippleView.update(ofVec3f(ofMap(Model::x,0,MacroManager::frame_height,frame_edge_x_down,frame_edge_x_up),
                               ofMap(Model::y,0,MacroManager::frame_width,frame_edge_y_down, frame_edge_y_up),
                               Model::interaction_value));

    frame_edge_x_up = ofGetWidth()/2-MacroManager::scaling_frame_height/2 - ofGetWidth()/3;
    frame_edge_x_down = frame_edge_x_up + MacroManager::scaling_frame_height;
    frame_edge_y_up = ofGetHeight()/2-MacroManager::scaling_frame_width/2;
    frame_edge_y_down = frame_edge_y_up + MacroManager::scaling_frame_width;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetWindowTitle("Model::interaction_value: "+ofToString(Model::interaction_value));
    mRippleView.draw();

    ofNoFill();
    ofDrawRectangle(0,0,MacroManager::frame_width,MacroManager::frame_height);

    ofSetColor(255,0,0,127);

    ofNoFill();
    ofDrawRectangle(frame_edge_x_up,
                    frame_edge_y_up,
                    MacroManager::scaling_frame_height,
                    MacroManager::scaling_frame_width);

    ofDrawRectangle(frame_edge_x_down + MacroManager::scaling_distance_kinect_to_frame,
                    ofGetHeight()/2-MacroManager::scaling_kinect_width/2,
                    MacroManager::scaling_kinect_height,
                    MacroManager::scaling_kinect_width
                    );

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
