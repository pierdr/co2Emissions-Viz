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
    
    for (map<string, float>::iterator it=co2byCountries.begin(); it!=co2byCountries.end(); ++it){
            if(it->second>50000)
            {
                for (map<string, float>::iterator it1=co2byCountries.begin(); it1!=co2byCountries.end(); ++it1){
                    if(it->second<it1->second)
                    {
                        mostToleastBig.insert(mostToleastBig.begin(),ofToString( it->first));
                    }
                }
            }
    }
    printf("hello");
    
    myfont.loadFont("sansserif_100.ttf", 10);
    myfont.setGlobalDpi(360);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
   // int xpos = 30;
    int ypos = 20;
    int workingXsize = 0;
    ofBackground(0, 0, 0);
    
    
    string str = "number of countries: %f";
    ofStringReplace(str, "%f", ofToString(co2byCountries.size()));
    myfont.drawString(str,20,20);
    
    int prevWidth = 0;
    int prevPosY = 0;
    
    for (map<string, float>::iterator it=co2byCountries.begin(); it!=co2byCountries.end(); ++it){
        ofSetColor(255, 255, 255);
        workingXsize = ofMap(it->second, minCO2Value, maxCO2Value, 0, ofGetWidth()-500);
        
        ofDrawRectangle(480, ypos, workingXsize, (ofGetHeight()-15)/co2byCountries.size() );
        
        if(workingXsize>15)
        {
            int xTmp = ((ypos-prevPosY<20 )?470-prevWidth:470);
            ofPushMatrix();
            
            ofTranslate(xTmp-(myfont.stringWidth(it->first)), ypos);
            //ofRotate(45);
            ofSetColor(255, 255, 255);
            myfont.drawString(it->first,0,0 );
            ofPopMatrix();
            ofSetLineWidth(0.5);
            ofSetColor(128,126);
            ofLine(xTmp+5,ypos,480,ypos);
            
            prevWidth = (ypos-prevPosY<20 )?prevWidth+myfont.stringWidth(it->first)+20:myfont.stringWidth(it->first)+20;
            prevPosY = ypos;
        }
        ypos+= (ofGetHeight()-15)/co2byCountries.size();

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
