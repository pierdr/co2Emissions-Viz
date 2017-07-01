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
            if(it->second>250000)
            {
                int indexTmp = 0;
                for (int i=0;i<mostToleastBig.size();i++){
                    
                    if(it->second>co2byCountries[mostToleastBig[i]])
                    {
                        break;
                        
                    }
                    indexTmp ++;
                }
                mostToleastBig.insert(mostToleastBig.begin()+indexTmp,ofToString( it->first));
            }
    }
    printf("hello");
    
    myfont.loadFont("sansserif_100.ttf", 8);
    myfont.setGlobalDpi(360);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
   // int xpos = 30;
    int ypos = 50;
    int workingXsize = 0;
    ofBackground(0, 0, 0);
    
    ofSetColor(255);
    string str = "%f top polluters from 1751 to 2014 - billion metric tons of CO2 from fossil fuel";
    ofStringReplace(str, "%f", ofToString(mostToleastBig.size()));
   // myfont.drawString(str,30,30);
    ofDrawBitmapString(str,30,30);
    int prevWidth = 0;
    int prevPosY = 0;
    for( int i = 0; i < mostToleastBig.size(); i++){
        //102,40,194
        //48,76,221
        
        workingXsize = ofMap(co2byCountries[mostToleastBig[i]], minCO2Value, maxCO2Value, 0, ofGetWidth()-500);
        
        ofSetColor(ofMap(workingXsize,0,ofGetWidth()-500,48,102), ofMap(workingXsize,0,ofGetWidth()-500,76,40), ofMap(workingXsize,0,ofGetWidth()-500,221,76));
        
        ofDrawRectangle(300, ypos, workingXsize, 10 );

        if(workingXsize>5)
        {
            int xTmp = ((ypos-prevPosY<10 )?285-prevWidth:285);
            ofPushMatrix();

            ofTranslate(xTmp-(myfont.stringWidth(mostToleastBig[i])), ypos+(((ofGetHeight()-60)/mostToleastBig.size())/2));
            //ofRotate(45);
            ofSetColor(255, 255, 255);
            myfont.drawString(mostToleastBig[i],0,0 );
            ofPopMatrix();
            
            ofSetColor(180);
            myfont.drawString(ofToString((int)co2byCountries[mostToleastBig[i]]/1000),320+workingXsize,ypos+10);
            
            ofSetLineWidth(0.5);
            ofSetColor(128,126);
            //ofLine(xTmp+5,ypos,300,ypos);

            prevWidth = (ypos-prevPosY<20 )?prevWidth+myfont.stringWidth(mostToleastBig[i])+20:myfont.stringWidth(mostToleastBig[i])+20;
            prevPosY = ypos;
        }
        ypos+= ((ofGetHeight()-60)/mostToleastBig.size());

    }
//    for (map<string, float>::iterator it=co2byCountries.begin(); it!=co2byCountries.end(); ++it){
//        ofSetColor(255, 255, 255);
//        workingXsize = ofMap(it->second, minCO2Value, maxCO2Value, 0, ofGetWidth()-500);
//        
//        ofDrawRectangle(480, ypos, workingXsize, (ofGetHeight()-15)/co2byCountries.size() );
//        
//        if(workingXsize>15)
//        {
//            int xTmp = ((ypos-prevPosY<20 )?470-prevWidth:470);
//            ofPushMatrix();
//            
//            ofTranslate(xTmp-(myfont.stringWidth(it->first)), ypos);
//            //ofRotate(45);
//            ofSetColor(255, 255, 255);
//            myfont.drawString(it->first,0,0 );
//            ofPopMatrix();
//            ofSetLineWidth(0.5);
//            ofSetColor(128,126);
//            ofLine(xTmp+5,ypos,480,ypos);
//            
//            prevWidth = (ypos-prevPosY<20 )?prevWidth+myfont.stringWidth(it->first)+20:myfont.stringWidth(it->first)+20;
//            prevPosY = ypos;
//        }
//        ypos+= (ofGetHeight()-15)/co2byCountries.size();
//
//    }
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
