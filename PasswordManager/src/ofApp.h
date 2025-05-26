#pragma once

#include "ofMain.h"
#include <vector>
#include <algorithm>

class ofApp : public ofBaseApp {

public:
	// Core OF functions
	void setup();
	void draw();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void clearInput();
	void search();
	void readPasswords();
	void readUsers();

	// Buttons and UI elements
	ofRectangle createBTN, loginBTN, homeBTN, menuBTN, usernameBTN, enterPasswordBTN, reEnterPasswordBTN, exitBTN, backBTN, hidePasswordBTN, searchBTN, passwordBox, clearSearchBTN, serviceBTN, usernameBTNNew, passwordBTNNew, cancelNewEntryBTN, confirmNewEntryBTN, scrollUpBTN, scrollDownBTN;

	// Fonts
	ofTrueTypeFont headFont, mainFont, subFont;

	// enum to handle program states (interface changes)
	enum class States { CREATE, LOGIN, HOME, MENU };
	States state;

	// vectors to store account data
	vector<string> masterUsername = {};
	vector<string> masterPassword = {};

	// vectors to store password entry data
	vector<string> user = {};
	vector<string> service = {};
	vector<string> username = {};
	vector<string> password = {};
	vector<bool> hidePasswordList;

	// image objects
	ofImage backIMG, eyeIMG, deleteIMG, addIMG, upIMG, downIMG, logoIMG;

	string usernameInput;
	string passwordInput;
	string reenterPasswordInput;
	string hiddenPassword;
	string searchInput;
	string emptySearch = "Search";
	string newServiceInput;
	string newUsernameInput;
	string newPasswordInput;
	string currentUser;
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
	int maxWordCount = 99;
	int searchIndex = -1; // -1 means no search applied
	float scrollOffset = 0.0f;
	float scrollStep = 40.0f; // amount to scroll 
	float maxScrollOffset = 0.0f; // how far you can scroll

	// Function to check if the password is valid
	string isValidPassword(const string& password);
	string createAccountErrorMsg;


	bool showingDeleteConfirmation = false;
	int deleteCandidateIndex = -1; // stores index of password to delete

	ofRectangle confirmDeleteYesBTN;
	ofRectangle confirmDeleteNoBTN;
};
