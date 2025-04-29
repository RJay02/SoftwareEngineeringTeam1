#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void draw();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);

	ofRectangle createBTN, loginBTN, homeBTN, menuBTN;

	ofTrueTypeFont headFont, mainFont, subFont, exitBTN;

	enum class States { CREATE, LOGIN, HOME, MENU };
	States state;

};
