#pragma once

#include "ofMain.h"
#include "Model.hpp"
#include "OSCManager.hpp"
#include "RippleView.hpp"
#include "MacroManager.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    RippleView mRippleView;

    float frame_edge_x_up;
    float frame_edge_x_down;
    float frame_edge_y_up;
    float frame_edge_y_down;
};
