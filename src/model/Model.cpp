//
//  Model.cpp
//  oF_OSC_ReceiverSample
//
//  Created by HirokiNaganuma on 2018/03/10.
//

#include "Model.hpp"

int Model::x;
int Model::y;
int Model::z;
int Model::interaction_value;

void Model::setup(){

}

void Model::update(){

}

void Model::draw(){

}

void Model::update_values(int x, int y, int z, int interaction_value){
    Model::x = x;
    Model::y = y;
    Model::z = z;
    Model::interaction_value = interaction_value;
}
