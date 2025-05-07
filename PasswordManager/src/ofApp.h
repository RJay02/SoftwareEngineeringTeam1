#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void draw();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void clearInput();

	ofRectangle createBTN, loginBTN, homeBTN, menuBTN, usernameBTN, enterPasswordBTN, reEnterPasswordBTN, exitBTN, backBTN, hidePasswordBTN;

	ofTrueTypeFont headFont, mainFont, subFont;

	enum class States { CREATE, LOGIN, HOME, MENU };
	States state;

	string usernameInput;
	string passwordInput;
	string reenterPasswordInput;
	string hiddenPassword;
	bool typingUsername = false;
	bool typingPassword = false;
	bool retypingPassword = false;
	bool hidePasword = true;
	int maxWordCount = 12;

	ofImage backIMG, eyeIMG;

};
