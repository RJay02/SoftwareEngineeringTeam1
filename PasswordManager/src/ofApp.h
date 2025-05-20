#pragma once

#include "ofMain.h"
#include <vector>

class ofApp : public ofBaseApp {

public:
	// Core OF functions
	void setup();
	void draw();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void clearInput();
	void search();

	// Buttons and UI elements
	ofRectangle createBTN, loginBTN, homeBTN, menuBTN, usernameBTN, enterPasswordBTN, reEnterPasswordBTN, exitBTN, backBTN, hidePasswordBTN, searchBTN, passwordBox, clearSearchBTN, serviceBTN, usernameBTNNew, passwordBTNNew, cancelNewEntryBTN, confirmNewEntryBTN;

	// Fonts
	ofTrueTypeFont headFont, mainFont, subFont;

	// enum to handle program states (interface changes)
	enum class States { CREATE, LOGIN, HOME, MENU };
	States state;

	// vectors to store account data
	vector<string> masterUsername = { "ted", "jack", "zack" };
	vector<string> masterPassword = { "det", "kcaj", "kcaz" };

	vector<string> service = {"apple"}; // placeholder values
	vector<string> username = {"sadasd"};
	vector<string> password = {"bdfsbk"};
	vector<bool> hidePasswordList;

	// image objects
	ofImage backIMG, eyeIMG, deleteIMG, addIMG;

	string usernameInput;
	string passwordInput;
	string reenterPasswordInput;
	string hiddenPassword;
	string searchInput;
	string emptySearch = "Search";
	string newServiceInput;
	string newUsernameInput;
	string newPasswordInput;
	bool typingUsername = false;
	bool typingPassword = false;
	bool retypingPassword = false;
	bool hidePasword = true;
	bool searching = false;
	bool validLogin = false;
	bool addingNewEntry = false;
	bool typingService = false;
	bool typingNewUsername = false;
	bool typingNewPassword = false;
	int maxWordCount = 12;
	int searchIndex = -1; // -1 means no search applied
};
