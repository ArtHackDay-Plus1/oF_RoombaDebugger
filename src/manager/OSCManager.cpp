//
//  OSCManager.cpp
//  oF_OSC_ReceiverSample
//
//  Created by HirokiNaganuma on 2018/03/10.
//

#include "OSCManager.hpp"

ofxOscReceiver OSCManager::receiver;
ofxOscMessage OSCManager::message;

// OSC最終受信時刻を保持
string OSCManager::latest_updated_time;

//--------------------------------------------------------------
void OSCManager::setup(){
    // receriver初期化
    receiver.setup(MacroManager::osc_port_num);

    // windowのtitleを設定
    ofSetWindowTitle("listening for osc messages on port" + ofToString(MacroManager::osc_port_num));

    // OSC listen on the given port
    cout << "listening for osc messages on port " << MacroManager::osc_port_num << "\n";

    // OSC最終受信時刻の初期化
    latest_updated_time = "";
}

//--------------------------------------------------------------
void OSCManager::update(){

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

//        // OSCの受信時刻が更新された場合、それは新しい値なので取得値のupdate
//        if(osc_update_time != latest_updated_time){
//
//            // 受信時刻更新
//            latest_updated_time = osc_update_time;
//
//            // 値の更新
//            int osc_input_data_x = message.getArgAsInt(1);
//            int osc_input_data_y = message.getArgAsInt(2);
//            int osc_input_data_z = message.getArgAsInt(3);
//            int osc_input_data_interactive = message.getArgAsInt(4);
//
//            Model::update_values(osc_input_data_x,
//                                 osc_input_data_y,
//                                 osc_input_data_z,
//                                 osc_input_data_interactive);
//
//            // 値のlog出し
//            ofLog() << "[" <<osc_update_time << "] x :"<< osc_input_data_x;
//            ofLog() << "[" <<osc_update_time << "] y :"<< osc_input_data_y;
//            ofLog() << "[" <<osc_update_time << "] z :"<< osc_input_data_z;
//            ofLog() << "[" <<osc_update_time << "] interactive :"<< osc_input_data_interactive;
//
//        }
    }
};


//--------------------------------------------------------------
void OSCManager::draw(){
}
