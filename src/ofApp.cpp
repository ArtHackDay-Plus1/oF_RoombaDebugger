#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    ofToggleFullscreen();
    OSCManager::setup();
    ofBackground(0);
    ofSetCircleResolution(64);
    ofHideCursor();
}

//--------------------------------------------------------------
void ofApp::update(){
    OSCManager::update();

    frame_edge_x_up = ofGetWidth()/2-MacroManager::scaling_frame_height/2 - ofGetWidth()/3;
    frame_edge_x_down = frame_edge_x_up + MacroManager::scaling_frame_height;
    frame_edge_y_up = ofGetHeight()/2-MacroManager::scaling_frame_width/2;
    frame_edge_y_down = frame_edge_y_up + MacroManager::scaling_frame_width;
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetWindowTitle("Model::interaction_value: "+ofToString(Model::interaction_value));

    // ===================== [KINECT & BOX AREA] =====================
    ofSetColor(255);
    ofNoFill();
    ofDrawRectangle(0,0,MacroManager::frame_width,MacroManager::frame_height);

    ofDrawBitmapString("Astral Body",
                       frame_edge_x_up,
                       frame_edge_y_up-10);
    ofDrawRectangle(frame_edge_x_up,
                    frame_edge_y_up,
                    MacroManager::scaling_frame_height,
                    MacroManager::scaling_frame_width);
    ofDrawBitmapString("x",
                       frame_edge_x_up + MacroManager::scaling_frame_height - 10,
                       frame_edge_y_up + MacroManager::scaling_frame_width + 10);
    ofDrawBitmapString("y",
                       frame_edge_x_up - 10,
                       frame_edge_y_up + 10);
    
    ofDrawLine(frame_edge_x_up + MacroManager::scaling_frame_to_wall_w + MacroManager::scaling_frame_height,
               frame_edge_y_up - MacroManager::scaling_frame_to_wall_h,
               frame_edge_x_up + MacroManager::scaling_frame_to_wall_w + MacroManager::scaling_frame_height,
               frame_edge_y_up + MacroManager::scaling_frame_width + 100);
    
    ofDrawLine(frame_edge_x_up + MacroManager::scaling_frame_to_wall_w + MacroManager::scaling_frame_height,
               frame_edge_y_up - MacroManager::scaling_frame_to_wall_h,
               frame_edge_x_up - 100,
               frame_edge_y_up - MacroManager::scaling_frame_to_wall_h);
    

    ofDrawBitmapString("Kinect",
                       frame_edge_x_down + MacroManager::scaling_distance_kinect_to_frame,
                       ofGetHeight()/2-MacroManager::scaling_kinect_width/2 -10);
    ofDrawRectangle(frame_edge_x_down + MacroManager::scaling_distance_kinect_to_frame,
                    ofGetHeight()/2-MacroManager::scaling_kinect_width/2,
                    MacroManager::scaling_kinect_height,
                    MacroManager::scaling_kinect_width
                    );
    // ===================== [KINECT & BOX AREA] =====================


    // ===================== [DRAW ROOMBA] =====================
    ofVec2f roomba_pos = ofVec2f(ofMap(Model::x, MacroManager::frame_height, 0, frame_edge_x_down, frame_edge_x_up),
                                 ofMap(Model::y, 0, MacroManager::frame_width, frame_edge_y_down, frame_edge_y_up));
    ofSetColor(255);
    ofDrawBitmapString("Roomba / [x:"+ ofToString(Model::x) +"/y:" + ofToString(Model::y) +"]", roomba_pos.x + 10, roomba_pos.y);
    ofFill();
    ofSetColor(255,0,0,127);
    ofDrawCircle(roomba_pos.x, roomba_pos.y, 10);
    ofDrawCircle(roomba_pos.x, roomba_pos.y, 25);
    // ===================== [DRAW ROOMBA] =====================


    // ===================== [Mouse Cursor] =====================
    ofSetColor(255,0,0,127);
    ofDrawCircle(mouseX, mouseY, 10);
    ofSetColor(255,0,0,127);
    ofDrawCircle(mouseX, mouseY, 50);
    ofSetColor(255);
    ofDrawLine(mouseX,
               mouseY,
               frame_edge_x_down + MacroManager::scaling_distance_kinect_to_frame,
               ofGetHeight()/2);
    ofDrawLine(mouseX, mouseY, frame_edge_x_down, mouseY);

    ofDrawBitmapString("nearest_y : "+ofToString(Model::nearest_y), frame_edge_x_down, mouseY-10);
    ofDrawBitmapString("nearest_depth : "+ofToString(Model::nearest_depth), frame_edge_x_down, mouseY+15);
    // ===================== [Mouse Cursor] =====================
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    float nearest_y = ofMap(y, frame_edge_y_up , frame_edge_y_down ,MacroManager::frame_width ,0);
    float nearest_depth = ofMap(x-frame_edge_x_down, 0, MacroManager::scaling_distance_kinect_to_frame,0,MacroManager::distance_kinect_to_frame);
    Model::update_values(nearest_y,  nearest_depth);
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
