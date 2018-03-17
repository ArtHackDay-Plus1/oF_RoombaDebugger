//
//  OSCManager.cpp
//  oF_OSC_ReceiverSample
//
//  Created by HirokiNaganuma on 2018/03/10.
//

#include "OSCManager.hpp"

ofxOscReceiver OSCManager::receiver;
ofxOscMessage OSCManager::message;
ofxOscSender OSCManager::sender;

// OSC最終受信時刻を保持
string OSCManager::latest_updated_time;

//--------------------------------------------------------------
void OSCManager::setup(){
    setup_receiver();
    setup_sender();
}

void OSCManager::setup_receiver(){
    // receriver初期化
    receiver.setup(MacroManager::receiver_osc_port_num);

    // windowのtitleを設定
    ofSetWindowTitle("listening for osc messages on port" + ofToString(MacroManager::receiver_osc_port_num));

    // OSC listen on the given port
    cout << "listening for osc messages on port " << MacroManager::receiver_osc_port_num << "\n";

    // OSC最終受信時刻の初期化
    latest_updated_time = "";
}

void OSCManager::setup_sender(){
    sender.setup(MacroManager::osc_sender_ip, MacroManager::sender_osc_port_num);
}

//--------------------------------------------------------------
void OSCManager::update(){
    update_receiver();
    update_sender();
};

void OSCManager::update_receiver(){

    receiver.getNextMessage(message);
    //untill all address of osc are got.

    if(message.getAddress() == "/data"){

        // OSCでデータを取得
        // OSC最終受信時刻の取得
        string osc_update_time = message.getArgAsString(0);

        int osc_input_data_x = message.getArgAsInt(1);
        int osc_input_data_y = message.getArgAsInt(2);
        int osc_input_data_z = message.getArgAsInt(3);
        int osc_input_data_interactive = message.getArgAsInt(4);

        Model::update_values(osc_input_data_x,
                             osc_input_data_y,
                             osc_input_data_z,
                             osc_input_data_interactive);

        // 値のlog出し
        ofLog() << "[" <<osc_update_time << "] x :"<< osc_input_data_x;
        ofLog() << "[" <<osc_update_time << "] y :"<< osc_input_data_y;
        ofLog() << "[" <<osc_update_time << "] z :"<< osc_input_data_z;
        ofLog() << "[" <<osc_update_time << "] interactive :"<< osc_input_data_interactive;

    }
}

//--------------------------------------------------------------
void OSCManager::update_sender(){

    if(ofGetElapsedTimeMillis()%1000 < 200){

        //osc message instance
        ofxOscMessage m;

        //set osc address
        m.setAddress("/data");

        //set current mouse position as OSC arguments
        m.addIntArg(Model::nearest_y);
        m.addIntArg(Model::nearest_depth);
        m.addIntArg(Model::num_of_people);

        //send message
        sender.sendMessage(m);

        ofLog() << "nearest_x : " <<"[" <<Model::nearest_y << "]";
        ofLog() << "nearest_depth : " <<"[" <<Model::nearest_depth << "]";
        ofLog() << "num_of_people : " <<"[" <<Model::num_of_people << "]";
    }
}

