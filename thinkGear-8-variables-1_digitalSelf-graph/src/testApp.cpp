#include "testApp.h"

void testApp::setup()
{
    ofSetFrameRate(30);
    ofEnableAlphaBlending();
    
    thinkGear.setup();
    ofAddListener(thinkGear.attentionChangeEvent, this, &testApp::attentionListener);
    ofAddListener(thinkGear.meditationChangeEvent, this, &testApp::meditationListener);
	ofAddListener(thinkGear.blinkChangeEvent, this, &testApp::blinkListener);
	ofAddListener(thinkGear.rawChangeEvent, this, &testApp::rawListener);
	ofAddListener(thinkGear.deltaChangeEvent, this, &testApp::deltaListener);
	ofAddListener(thinkGear.thetaChangeEvent, this, &testApp::thetaListener);
	ofAddListener(thinkGear.alpha1ChangeEvent, this, &testApp::alpha1Listener);
	ofAddListener(thinkGear.alpha2ChangeEvent, this, &testApp::alpha2Listener);
	ofAddListener(thinkGear.beta1ChangeEvent, this, &testApp::beta1Listener);
	ofAddListener(thinkGear.beta2ChangeEvent, this, &testApp::beta2Listener);
	ofAddListener(thinkGear.gamma1ChangeEvent, this, &testApp::gamma1Listener);
	ofAddListener(thinkGear.gamma2ChangeEvent, this, &testApp::gamma2Listener);
	
    font.loadFont("font/DroidSansMono.ttf", 20);
    
    distAw = 0.0;
    prevAw = 0.0;
    currAw = 0.0;
	distAwLINE = 0.0;
	
    distMw = 0.0;
    prevMw = 0.0;
    currMw = 0.0;
	distMwLINE = 0.0;
	
	distRw = 0.0;
    prevRw = 0.0;
    currRw = 0.0;
	distRwLINE = 0.0;
	
    distDw = 0.0;
    prevDw = 0.0;
    currDw = 0.0;
	distDwLINE = 0.0;	
	
	distTw = 0.0;
    prevTw = 0.0;
    currTw = 0.0;
	distTwLINE = 0.0;	
	
    distA1w = 0.0;
    prevA1w = 0.0;
    currA1w = 0.0;
	distA1wLINE = 0.0;	
	
	distA2w = 0.0;
    prevA2w = 0.0;
    currA2w = 0.0;
	distA2wLINE = 0.0;	
	
	distB1w = 0.0;
    prevB1w = 0.0;
    currB1w = 0.0;
	distB1wLINE = 0.0;	
	
	distB2w = 0.0;
    prevB2w = 0.0;
    currB2w = 0.0;
	distB2wLINE = 0.0;		
	
	distG1w = 0.0;
    prevG1w = 0.0;
    currG1w = 0.0;
	distG1wLINE = 0.0;		
	
	distG2w = 0.0;
    prevG2w = 0.0;
    currG2w = 0.0;
	distG1wLINE = 0.0;	
    
    atChangeTime = 0.0;
    attention = 0.0;
    meChangeTime = 0.0;
    meditation = 0.0;
	raChangeTime = 0.0;
    raw = 0.0;
    deChangeTime = 0.0;
    delta = 0.0;
	thChangeTime = 0.0;
    theta = 0.0;
    a1ChangeTime = 0.0;
    alpha1 = 0.0;
	a2ChangeTime = 0.0;
    alpha2 = 0.0;
    b1ChangeTime = 0.0;
    beta1 = 0.0;
	b2ChangeTime = 0.0;
    beta2 = 0.0;
    g1ChangeTime = 0.0;
    gamma1 = 0.0;
	g2ChangeTime = 0.0;
    gamma2 = 0.0;
}

void testApp::update()
{
    thinkGear.update();
    
    float cur = ofGetElapsedTimef();
	
    float progress = cur - atChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevAw = currAw;
    currAw = ofxTweenLite::tween(prevAw, distAw, progress, OF_EASE_SINE_INOUT);
    
    progress = cur - meChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevMw = currMw;
    currMw = ofxTweenLite::tween(prevMw, distMw, progress, OF_EASE_SINE_INOUT);
    
	progress = cur - raChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevRw = currRw;
    currRw = ofxTweenLite::tween(prevRw, distRw, progress, OF_EASE_SINE_INOUT);

	progress = cur - deChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevDw = currDw;
    currDw = ofxTweenLite::tween(prevDw, distDw, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - thChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevTw = currTw;
    currTw = ofxTweenLite::tween(prevTw, distTw, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - a1ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevA1w = currA1w;
    currA1w = ofxTweenLite::tween(prevA1w, distA1w, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - a2ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevA2w = currA2w;
    currA2w = ofxTweenLite::tween(prevA2w, distA2w, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - b1ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevB1w = currB1w;
    currB1w = ofxTweenLite::tween(prevB1w, distB1w, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - b2ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevB2w = currB2w;
    currB2w = ofxTweenLite::tween(prevB2w, distB2w, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - g1ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevG1w = currG1w;
    currG1w = ofxTweenLite::tween(prevG1w, distG1w, progress, OF_EASE_SINE_INOUT);
	
	progress = cur - g2ChangeTime;
    progress = ofClamp(progress, 0.0, 1.0);
    if (progress == 0.0) prevG2w = currG2w;
    currG2w = ofxTweenLite::tween(prevG2w, distG2w, progress, OF_EASE_SINE_INOUT);
	
	//add code to smooth out raw data added
}

void testApp::draw()
{
    ofBackgroundGradient(ofColor::darkGray, ofColor::black);
    
    ofPushStyle();
    ofSetColor(ofColor::black);
    string qStr = "";
    if (thinkGear.getSignalQuality() == 0.0)
    {
        qStr = "good";
    }
    else 
    {
        qStr = "poor (" + ofToString(thinkGear.getSignalQuality()) + ")";
    }
    font.drawString("signal quality = " + qStr, 10, 40); 
	font.drawString("signal quality = " + qStr, 10, 40); 

    ofPopStyle();
    
    //attn bar
//    ofPushMatrix();
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("Attention", 10, ofGetHeight()/7 - 10);
//    ofNoFill();
//    ofRect(1, ofGetHeight()/7, ofGetWidth() - 2, 60);
//    ofSetColor(ofColor::magenta, ofMap(currAw, 0.0, ofGetWidth(), 50, 255));
//    ofFill();    
//    ofRect(0, ofGetHeight()/7, currAw, 59);
//    if (attention > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currAw, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(attention), 10, ofGetHeight()/7 + 40);
//    }
//    ofPopStyle();
//    ofPopMatrix();
//    
//    //meditation bar
//	ofPushMatrix();
//    ofTranslate(0, 0);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("Meditation", 10, (ofGetHeight()/3.9) - 10); 
//    ofNoFill();
//    ofRect(1, (ofGetHeight()/3.9), ofGetWidth() - 2, 60);    
//    ofSetColor(ofColor::cyan, ofMap(currMw, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, (ofGetHeight()/3.9), currMw, 59);
//    if (meditation > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currMw, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(meditation), 10, (ofGetHeight()/3.9) + 40);
//    }    
//    ofPopStyle();
//    ofPopMatrix();
//    
//	//raw bar
//    ofPushMatrix();
//    ofTranslate(0, 100);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("Raw", 10, (ofGetHeight()/3.8) - 10); 
//    ofNoFill();
//    ofRect(1, (ofGetHeight()/3.8), ofGetWidth() - 2, 60);    
//    ofSetColor(ofColor::green, ofMap(currRw, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, (ofGetHeight()/3.8), currRw, 59);
//    if (raw > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currRw, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(raw), 10, (ofGetHeight()/3.8) + 40);
//    }    
//    ofPopStyle();
//    ofPopMatrix();
//	
//	//delta bar
//    ofPushMatrix();
//    ofTranslate(0, -40);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("Delta", 10, (ofGetHeight()/1.8) - 10); 
//    ofNoFill();
//    ofRect(1, (ofGetHeight()/1.8), ofGetWidth() - 2, 60);    
//    ofSetColor(ofColor::orange, ofMap(currDw, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, (ofGetHeight()/1.8), currDw, 59);
//    if (delta > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currDw, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(delta), 10, (ofGetHeight()/1.8) + 40);
//    }    
//    ofPopStyle();
//    ofPopMatrix();
//	
//	//theta bar
//    ofPushMatrix();
//    ofTranslate(0, -40);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("Theta", 10, (ofGetHeight()/1.5) - 10); 
//    ofNoFill();
//    ofRect(1, (ofGetHeight()/1.5), ofGetWidth() - 2, 60);    
//    ofSetColor(ofColor::yellow, ofMap(currTw, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, (ofGetHeight()/1.5), currTw, 59);
//    if (theta > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currTw, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(theta), 10, (ofGetHeight()/1.5) + 40);
//    }    
//    ofPopStyle();
//    ofPopMatrix();
//	
//	//alpha1 bar
//	ofPushMatrix();
//    ofTranslate(0, -40);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("Low Alpha", 10, ofGetHeight()-(ofGetHeight()/4.5) - 10); 
//    ofNoFill();
//    ofRect(1, ofGetHeight()-(ofGetHeight()/4.5), ofGetWidth() - 2, 60);    
//    ofSetColor(ofColor::pink, ofMap(currA1w, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, ofGetHeight()-(ofGetHeight()/4.5), currA1w, 59);
//    if (alpha1 > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currA1w, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(alpha1), 10, ofGetHeight()-(ofGetHeight()/4.5) + 40);
//    }    
//    ofPopStyle();
//    ofPopMatrix();
//	
//	//alpha2 bar
//	ofPushMatrix();
//    ofTranslate(0, -40);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("High Alpha", 10, ofGetHeight()-(ofGetHeight()/4.5) - 10); 
//    ofNoFill();
//    ofRect(1, ofGetHeight()-(ofGetHeight()/4.5), ofGetWidth() - 2, 60);    
//    ofSetColor(ofColor::pink, ofMap(currA2w, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, ofGetHeight()-(ofGetHeight()/4.5), currA2w, 59);
//    if (alpha2 > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currA2w, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(alpha2), 10, ofGetHeight()-(ofGetHeight()/4.5) + 40);
//    }    
//    ofPopStyle();
//    ofPopMatrix();
//	
//	//beta1 bar
//	ofPushMatrix();
//    ofTranslate(0, -40);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("Low Beta", 10, ofGetHeight()-(ofGetHeight()/9) - 10); 
//    ofNoFill();
//    ofRect(1, ofGetHeight()-(ofGetHeight()/9), ofGetWidth() - 2, 60);    
//    ofSetColor(ofColor::red, ofMap(currB1w, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, ofGetHeight()-(ofGetHeight()/9), currB1w, 59);
//    if (beta1> 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currB1w, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(beta1), 10, ofGetHeight()-(ofGetHeight()/9) + 40);
//    }    
//    ofPopStyle();
//    ofPopMatrix();
//
//	//beta2 bar
//	ofPushMatrix();
//    ofTranslate(0, -40);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("High Beta", 10, ofGetHeight()-(ofGetHeight()/9) - 10); 
//    ofNoFill();
//    ofRect(1, ofGetHeight()-(ofGetHeight()/9), ofGetWidth() - 2, 60);    
//    ofSetColor(ofColor::red, ofMap(currB2w, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, ofGetHeight()-(ofGetHeight()/9), currB2w, 59);
//    if (beta2> 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currB2w, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(beta2), 10, ofGetHeight()-(ofGetHeight()/9) + 40);
//    }    
//    ofPopStyle();
//    ofPopMatrix();
//	
//	//gamma1 bar
//	ofPushMatrix();
//    ofTranslate(0, -40);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("Low Gamma", 10, ofGetHeight()-(ofGetHeight()/50) - 10); 
//    ofNoFill();
//    ofRect(1, ofGetHeight()-(ofGetHeight()/50), ofGetWidth() - 2, 60);    
//    ofSetColor(ofColor::blue, ofMap(currG1w, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, ofGetHeight()-(ofGetHeight()/50), currG1w, 59);
//    if (gamma1 > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currG1w, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(gamma1), 10, ofGetHeight()-(ofGetHeight()/50) + 40);
//    }    
//    ofPopStyle();
//    ofPopMatrix();
//	
//	//gamma2 bar
//	ofPushMatrix();
//    ofTranslate(0, -40);
//    ofPushStyle();
//    ofSetColor(ofColor::black);
//    font.drawString("High Gamma", 10, ofGetHeight()-(ofGetHeight()/50) - 10); 
//    ofNoFill();
//    ofRect(1, ofGetHeight()-(ofGetHeight()/50), ofGetWidth() - 2, 60);    
//    ofSetColor(ofColor::blue, ofMap(currG2w, 0.0, ofGetWidth(), 50, 255));
//    ofFill();
//    ofRect(0, ofGetHeight()-(ofGetHeight()/50), currG2w, 59);
//    if (gamma2 > 0.0)
//    {
//        ofSetColor(ofColor::black, ofMap(currG2w, 0.0, ofGetWidth(), 50, 255));
//        font.drawString(ofToString(gamma2), 10, ofGetHeight()-(ofGetHeight()/50) + 40);
//    }    
//    ofPopStyle();
//    ofPopMatrix();
	
    
    ofSetWindowTitle("fps = " + ofToString(ofGetFrameRate()));

//Draw polyLine graph	
	
	//attention line: pink
	addRange(line1, distAwLINE);
	ofSetColor(ofColor::blue);
	ofSetLineWidth(3);
	line1.draw();

	//meditation line: yellow
	addRange(line2, distMwLINE);
	ofSetColor(ofColor::yellow);
	ofSetLineWidth(3);
	line2.draw();
	
	//raw line: lime
	addRange(line3, distRwLINE);
	ofSetColor(ofColor::lime);
	ofSetLineWidth(3);
	line3.draw();
	
	//delta line: green
	addRange(line4, distDwLINE);
	ofSetColor(ofColor::green);
	ofSetLineWidth(3);
	line4.draw();
	
	//theta line: purple
	addRange(line5, distTwLINE);
	ofSetColor(ofColor::purple);
	ofSetLineWidth(3);
	line5.draw();
	
	//alpha1 line: orange
	addRange(line6, distA1wLINE);
	ofSetColor(ofColor::orange);
	ofSetLineWidth(3);
	line6.draw();
	
	//alpha2 line: cyan
	addRange(line7, distA2wLINE);
	ofSetColor(ofColor::cyan);
	ofSetLineWidth(3);
	line7.draw();
	
	//beta1 line: red
	addRange(line8, distB1wLINE);
	ofSetColor(ofColor::red);
	ofSetLineWidth(3);
	line8.draw();
	
	//beta2 line: chocolate
	addRange(line9, distB2wLINE);
	ofSetColor(ofColor::chocolate);
	ofSetLineWidth(3);
	line9.draw();
	
	//gamma1 line: lavender
	addRange(line10, distG1wLINE);
	ofSetColor(ofColor::lavender);
	ofSetLineWidth(3);
	line10.draw();
	
	//gamma2 line: honeydew
	addRange(line11, distG2wLINE);
	ofSetColor(ofColor::honeyDew);
	ofSetLineWidth(3);
	line11.draw();
	
	
	string Output = ofToString(distAw)+","+ofToString(distMw)+","+ofToString(distRw)+","+ofToString(distDw)
	+","+ofToString(distTw)+","+ofToString(distA1w)+","+ofToString(distA2w)+","+ofToString(distB1w)+","+ofToString(distB2w)+","+ofToString(distG1w)+","+ofToString(distG2w);}

void testApp::attentionListener(float &param)
{
    attention = param;	
    distAw = ofMap(attention, 0.0, 100.0, 0, ofGetWidth());
	
	distAwLINE = ofMap(attention, 0.0, ofGetHeight()+200, 0, ofGetWidth()/3);
	
    atChangeTime = ofGetElapsedTimef();
}

void testApp::meditationListener(float &param)
{
    meditation = param;
    distMw = ofMap(meditation, 0.0, 100.0, 0, ofGetWidth());
	
	distMwLINE = ofMap(meditation, 0.0, ofGetHeight()+200, 0, ofGetWidth()/3);
	
    meChangeTime = ofGetElapsedTimef();    
}

void testApp::blinkListener(float &param)
{
//    meditation = param;
//    distMw = ofMap(meditation, 0.0, 100.0, 0, ofGetWidth());
//    meChangeTime = ofGetElapsedTimef();   
	cout << "blink: "<<param<<endl;
}

void testApp::rawListener(float &param)
{
	raw = param;
	distRw = ofMap(raw, 0.0, 100.0, 0, ofGetWidth());
	
	distRwLINE = ofMap(raw, 0.0, ofGetHeight()+200, 0, ofGetWidth()/3);
	
	raChangeTime = ofGetElapsedTimef();   
	//cout << "raw: "<<param<<endl;
}

void testApp::deltaListener(float &param)
{
	delta = param;
	distDw = ofMap(delta, 0.0, 100.0, 0, ofGetWidth());
	
	distDwLINE = ofMap(delta, 0.0, ofGetHeight()+200, 0, ofGetWidth()/3);	
	
	deChangeTime = ofGetElapsedTimef(); 
}

void testApp::thetaListener(float &param)
{
	theta = param;
	distTw = ofMap(theta, 0.0, 100.0, 0, ofGetWidth());
	
	distTwLINE = ofMap(theta, 0.0, ofGetHeight()+200, 0, ofGetWidth()/3);
	
	thChangeTime = ofGetElapsedTimef(); 
//	cout << "theta: "<<param<<endl;
}

void testApp::alpha1Listener(float &param)
{
	alpha1 = param;
	distA1w = ofMap(alpha1, 0.0, 100.0, 0, ofGetWidth());
	
	distA1wLINE = ofMap(alpha1, 0.0, ofGetHeight()+200, 0, ofGetWidth()/3);
	
	a1ChangeTime = ofGetElapsedTimef(); 
//	cout << "alpha1: "<<param<<endl;
}

void testApp::alpha2Listener(float &param)
{
	alpha2 = param;
	distA2w = ofMap(alpha2, 0.0, 100.0, 0, ofGetWidth());
	
	distA2wLINE = ofMap(alpha2, 0.0, ofGetHeight()+200, 0, ofGetWidth()/3);	
	
	a2ChangeTime = ofGetElapsedTimef(); 
	//	cout << "alpha2: "<<param<<endl;
}

void testApp::beta1Listener(float &param)
{
	beta1 = param;
	distB1w = ofMap(beta1, 0.0, 100.0, 0, ofGetWidth());
	
	distB1wLINE = ofMap(beta1, 0.0, ofGetHeight()+200, 0, ofGetWidth()/3);	
	
	b1ChangeTime = ofGetElapsedTimef(); 
}

void testApp::beta2Listener(float &param)
{
	beta2 = param;
	distB2w = ofMap(beta2, 0.0, 100.0, 0, ofGetWidth());
	
	distB2wLINE = ofMap(beta2, 0.0, ofGetHeight()+200, 0, ofGetWidth()/3);		
	
	b2ChangeTime = ofGetElapsedTimef(); 
}

void testApp::gamma1Listener(float &param)
{
	gamma1 = param;
	distG1w = ofMap(gamma1, 0.0, 100.0, 0, ofGetWidth());
	
	distG1wLINE = ofMap(gamma1, 0.0, ofGetHeight()+200, 0, ofGetWidth()/3);		
	
	g1ChangeTime = ofGetElapsedTimef(); 
}

void testApp::gamma2Listener(float &param)
{
	gamma2 = param;
	distG2w = ofMap(gamma2, 0.0, 100.0, 0, ofGetWidth());

	distG2wLINE = ofMap(gamma2, 0.0, ofGetHeight()+200, 0, ofGetWidth()/3);			
	
	g2ChangeTime = ofGetElapsedTimef(); 
}

void testApp::addRange( ofPolyline & line, int value ){
    cout << "add "<< value << endl;
    line.addVertex( line.size() * 5, value );
    if ( line.size() > 200 ){
        vector<ofPoint> & verts = line.getVertices();
        // shift points over
        verts.erase(line.getVertices().begin());
        for ( int i=0; i<line.size(); i++){
            verts[i].x -= 10;
        }
    }
}

void testApp::keyPressed(int key){}
void testApp::keyReleased(int key){}
void testApp::mouseMoved(int x, int y){}
void testApp::mouseDragged(int x, int y, int button){}
void testApp::mousePressed(int x, int y, int button){}
void testApp::mouseReleased(int x, int y, int button){}
void testApp::windowResized(int w, int h){}
void testApp::gotMessage(ofMessage msg){}
void testApp::dragEvent(ofDragInfo dragInfo){}