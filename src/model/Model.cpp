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

int Model::nearest_y;
int Model::nearest_depth;
int Model::num_of_people;

void Model::update_values(int nearest_y, int nearest_depth, int num_of_people){
    Model::nearest_y = nearest_y;
    Model::nearest_depth = nearest_depth;
    Model::num_of_people = num_of_people;
}

void Model::update_values(int nearest_y, int nearest_depth){
    Model::nearest_y = nearest_y;
    Model::nearest_depth = nearest_depth;
}
