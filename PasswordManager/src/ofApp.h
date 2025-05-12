#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:
	void setup();
	void draw();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void clearInput();
	void search();

	ofRectangle createBTN, loginBTN, homeBTN, menuBTN, usernameBTN, enterPasswordBTN, reEnterPasswordBTN, exitBTN, backBTN, hidePasswordBTN, searchBTN, passwordBox, clearSearchBTN;

	ofTrueTypeFont headFont, mainFont, subFont;

	enum class States { CREATE, LOGIN, HOME, MENU };
	States state;

	vector<string> service = {"apple", "amazon", "microsoft"}; // placeholder values
	vector<string> username = {"sadasd", "agsfvdv", "askda" };
	vector<string> password = {"bdfsbk", "hsdbfjohb", "hsabdbf"};
	vector<bool> hidePasswordList;

	string usernameInput;
	string passwordInput;
	string reenterPasswordInput;
	string hiddenPassword;
	string searchInput;
	string emptySearch = "Search";
	bool typingUsername = false;
	bool typingPassword = false;
	bool retypingPassword = false;
	bool hidePasword = true;
	bool searching = false;
	int maxWordCount = 12;
	int searchIndex = -1; // -1 means no search applied

	ofImage backIMG, eyeIMG;
};
