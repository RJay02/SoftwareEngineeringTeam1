#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	state = States::MENU; // sets the initial state to menu
	ofBackground(255);

	//loading font files
	mainFont.load("font.otf", 12);
	subFont.load("sub.otf", 17);
	headFont.load("header.ttf", 22);

	// set coordinates for buttons
	exitBTN.set(ofGetWidth() - 75, 25, 50, 50);
	usernameBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 200, ofGetWidth() - 200, 50);
	enterPasswordBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 350, ofGetWidth() - 200, 50);
	reEnterPasswordBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 500, ofGetWidth() - 200, 50);
	createBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 400) / 2, 600, ofGetWidth() - 400, 50);
	loginBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 300) / 2, 700, ofGetWidth() - 300, 50);
	homeBTN.set(ofGetWidth() / 2 - 100, 400, 200, 50);
}


//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(50); // sets colour of following object(s)
	ofDrawRectangle(exitBTN); // drawing a rectangle based on values set in setup
	ofSetColor(255);
	mainFont.drawString("Exit", ofGetWidth() - 50 - mainFont.stringWidth("Exit") / 2, 50 + mainFont.getSize() / 2); // drawing text on screen

	if (state == States::MENU) { // checking the state and drawing the designated objects
		ofSetColor(50); 
		ofDrawRectangle(createBTN);
		ofDrawRectangle(loginBTN);
		ofDrawRectangle(homeBTN);
		ofSetColor(255); 
		headFont.drawString("Create", ofGetWidth() / 2 - headFont.stringWidth("Create") / 2, 635);
		headFont.drawString("Login", ofGetWidth() / 2 - headFont.stringWidth("Login") / 2, 735);
		headFont.drawString("Home", ofGetWidth() / 2 - headFont.stringWidth("Home") / 2, 435);
		ofSetColor(50);
		headFont.drawString("Password Manager", ofGetWidth() / 2 - headFont.stringWidth("Password Manager") / 2, 100);
	}

	if (state == States::LOGIN or state == States::CREATE) { // if its either login or create screen
		ofSetColor(50);
		ofDrawRectangle(createBTN);
		ofDrawRectangle(loginBTN);
		ofSetColor(225);
		ofDrawRectangle(usernameBTN);
		ofDrawRectangle(enterPasswordBTN);

		// make this a separate function
		// Username text box
		if (usernameInput.empty()) {
			ofSetColor(150);
			mainFont.drawString("Enter username", usernameBTN.x + 10, usernameBTN.y + 30);
		}
		else {
			ofSetColor(0);
			mainFont.drawString(usernameInput, usernameBTN.x + 10, usernameBTN.y + 30);
		}

		// Password text box
		if (passwordInput.empty()) {
			ofSetColor(150);
			mainFont.drawString("Enter password", enterPasswordBTN.x + 10, enterPasswordBTN.y + 30);
		}
		else {
			ofSetColor(0);
			//string hiddenPassword(passwordInput.length(), '*'); // makes the inputed text appear as *
			mainFont.drawString(passwordInput, enterPasswordBTN.x + 10, enterPasswordBTN.y + 30);
		}
	}

	if (state == States::LOGIN) {
		ofSetColor(50);
		headFont.drawString("Login", ofGetWidth() / 2 - headFont.stringWidth("Login") / 2, 100);
		ofSetColor(255);
		headFont.drawString("Don't have an account?", ofGetWidth() / 2 - headFont.stringWidth("Dont' have an account") / 2, 635);
		headFont.drawString("Login", ofGetWidth() / 2 - headFont.stringWidth("Login") / 2, 735);
	}

	if (state == States::CREATE) {
		ofSetColor(50);
		headFont.drawString("Create", ofGetWidth() / 2 - headFont.stringWidth("Create") / 2, 100);
		ofSetColor(255);
		headFont.drawString("Create account", ofGetWidth() / 2 - headFont.stringWidth("Create account") / 2, 635);
		headFont.drawString("Already have an account?", ofGetWidth() / 2 - headFont.stringWidth("Already have an account?") / 2, 735);
		ofSetColor(225);
		ofDrawRectangle(reEnterPasswordBTN);


		if (reenterPasswordInput.empty()) {
			ofSetColor(150);
			mainFont.drawString("Re enter password", reEnterPasswordBTN.x + 10, reEnterPasswordBTN.y + 30);
		}
		else {
			ofSetColor(0);
			mainFont.drawString(reenterPasswordInput, reEnterPasswordBTN.x + 10, reEnterPasswordBTN.y + 30);
		}
	}

	if (state == States::HOME) {
		ofSetColor(50);
		headFont.drawString("Home", ofGetWidth() / 2 - headFont.stringWidth("Home") / 2, 100);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) { // for typing into boxes 
	if (typingUsername) { // allows input if the user clicked onto the username box
		if (key == OF_KEY_BACKSPACE && usernameInput.length() > 0) {
			usernameInput = usernameInput.substr(0, usernameInput.length() - 1); // removes the last inputted character
		}
		else if (key >= 32 && key <= 126) { // only allow printable characters
			usernameInput += (char)key;
		}
		// enter key goes to the next box?
	}
	else if (typingPassword) {
		if (key == OF_KEY_BACKSPACE && passwordInput.length() > 0) {
			passwordInput = passwordInput.substr(0, passwordInput.length() - 1);
		}
		else if (key >= 32 && key <= 126) {
			passwordInput += (char)key;
		}
	}
	else if (retypingPassword) {
		if (key == OF_KEY_BACKSPACE && reenterPasswordInput.length() > 0) {
			reenterPasswordInput = reenterPasswordInput.substr(0, reenterPasswordInput.length() - 1);
		}
		else if (key >= 32 && key <= 126) {
			reenterPasswordInput += (char)key;
		}
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (state == States::MENU) { // when the mouse is pressed checks to see if the coordinates match with the button
		if (createBTN.inside(x, y)) {
			state = States::CREATE;
			return;
		}
		if (loginBTN.inside(x, y)) {
			state = States::LOGIN;
			return;
		}
		if (homeBTN.inside(x, y)) {
			state = States::HOME;
			return;
		}
	}
	if (state == States::LOGIN) {
		if (loginBTN.inside(x, y)) {
			state = States::HOME;
			return;
		}
		if (createBTN.inside(x, y)) {
			state = States::CREATE;
			return;
		}
	}

	if (state == States::CREATE) {
		if (loginBTN.inside(x, y)) {
			state = States::LOGIN;
			return;
		}
		if (createBTN.inside(x, y)) {
			state = States::HOME;
			return;
		}
	}
	if (exitBTN.inside(x, y)) { // exits the solution
		ofExit();
	}
	if (usernameBTN.inside(x, y)) { // tells the system what text box should be active
		typingUsername = true;
		typingPassword = false;
		retypingPassword = false;
	}
	else if (enterPasswordBTN.inside(x, y)) {
		typingUsername = false;
		typingPassword = true;
		retypingPassword = false;
	}
	else if (reEnterPasswordBTN.inside(x, y)) {
		typingUsername = false;
		typingPassword = false;
		retypingPassword = true;
	}
	else {
		typingUsername = false;
		typingPassword = false;
		retypingPassword = false;
	}
}