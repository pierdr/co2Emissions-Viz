#pragma once

#include "ofMain.h"
#include "ofxCsv.h"
#include "ofxJSON.h"

struct ofxCoordinates {
    float lat;
    float lon;
};

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
    
        ofxCsv csvOP;
        vector<ofxCoordinates> containerOp;
    
        map<string, float> co2byCountries;
    
        float maxCO2Value;
        float minCO2Value;
		
};
