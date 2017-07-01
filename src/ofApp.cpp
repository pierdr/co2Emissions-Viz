#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    csvOP.load(ofToDataPath("fossil-fuel-co2-emissions-by-nation.csv"));
    
    minCO2Value = 999999;
    maxCO2Value = -1;
    
    float workingFloat = 0;
    string workingString = "";
    for(int i=0;i<csvOP.getNumRows();i++)
    {
        
        workingString = ofToString(csvOP.getData()[i][1]);
         workingFloat = ofToFloat(csvOP.getData()[i][2]);
        
        if(co2byCountries.find(workingString)!=co2byCountries.end() )
        {
            co2byCountries[workingString] += workingFloat;
        }
        else
        {
            co2byCountries[workingString] = workingFloat;
        }
        //MIN
        if(co2byCountries[workingString] <minCO2Value)
        {
            minCO2Value=co2byCountries[workingString] ;
        }
        //MAX
        if(co2byCountries[workingString] >maxCO2Value){
            maxCO2Value=co2byCountries[workingString] ;
        }
        
    }
    printf("hello");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    int xpos = 0;
    int ypos = 20;
    int workingYOrigin = 0;
    ofBackground(0, 0, 0);
    ofSetColor(255, 255, 255);
    for (map<string, float>::iterator it=co2byCountries.begin(); it!=co2byCountries.end(); ++it){
        // it->first contains the key
        cout << " this is the key " << it->first << endl;
        // it->second contains the value
        workingYOrigin = ofMap(it->second, minCO2Value, maxCO2Value, 0, ofGetHeight()/2);
        
            ofDrawRectangle(xpos, ofGetHeight()/2-workingYOrigin, ofGetWidth()/co2byCountries.size()-1, workingYOrigin);
            xpos+= (ofGetWidth()-200)/co2byCountries.size();
        if(workingYOrigin>15)
        {
        
            ofDrawBitmapString(it->first, xpos, ofGetHeight()/2+(ypos));

            ypos+=20;
            if(ypos>ofGetHeight()/2)
            {
                ypos = 20;
            }
        }
    }
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
