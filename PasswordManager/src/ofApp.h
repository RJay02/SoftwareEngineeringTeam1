#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void draw();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void clearInput();

	ofRectangle createBTN, loginBTN, homeBTN, menuBTN, usernameBTN, enterPasswordBTN, reEnterPasswordBTN, exitBTN, backBTN, hidePasswordBTN, searchBTN, passwordBox;

	ofTrueTypeFont headFont, mainFont, subFont;

	enum class States { CREATE, LOGIN, HOME, MENU };
	States state;

	vector<string> service = {"apple", "amazon", "microsoft"}; // placeholder values
	vector<string> username = {"sadasd", "agsfvdv", "askda" };
	vector<string> password = {"bdfsbk", "hsdbfjohb", "hsabdbf"};

	string usernameInput;
	string passwordInput;
	string reenterPasswordInput;
	string hiddenPassword;
	string searchInput;
	bool typingUsername = false;
	bool typingPassword = false;
	bool retypingPassword = false;
	bool hidePasword = true;
	bool searching = false;
	int maxWordCount = 12;

	ofImage backIMG, eyeIMG;

};
