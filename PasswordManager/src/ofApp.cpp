#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	state = States::MENU; // sets the initial state to menu
	ofBackground(255);

	//loading font files
	mainFont.load("font.otf", 12);
	subFont.load("sub.otf", 17);
	headFont.load("header.ttf", 22);
	backIMG.load("back.png");
	eyeIMG.load("eye-icon.png");

	// set coordinates for buttons
	exitBTN.set(ofGetWidth() - 75, 25, 50, 50);
	usernameBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 200, ofGetWidth() - 200, 50);
	enterPasswordBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 350, ofGetWidth() - 200, 50);
	reEnterPasswordBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 500, ofGetWidth() - 200, 50);
	createBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 400) / 2, 600, ofGetWidth() - 400, 50);
	loginBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 300) / 2, 700, ofGetWidth() - 300, 50);
	homeBTN.set(ofGetWidth() / 2 - 100, 400, 200, 50);
	backBTN.set(15, 25, 50, 50);
	hidePasswordBTN.set(enterPasswordBTN.x + enterPasswordBTN.width + 10, enterPasswordBTN.y, 50, enterPasswordBTN.height);
	searchBTN.set(200, 200, ofGetWidth() - 400, 50);
	clearSearchBTN.set(200, searchBTN.y - 50, 150, 40); 
	passwordBox.set(300, 300, ofGetWidth() - 600, 100);

	hidePasswordList = vector<bool>(password.size(), true); // initially hide all passwrods
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
		backIMG.draw(backBTN);
		eyeIMG.draw(hidePasswordBTN);

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
			if (hidePasword) {
				hiddenPassword = string(passwordInput.length(), '*');
				mainFont.drawString(hiddenPassword, enterPasswordBTN.x + 10, enterPasswordBTN.y + 30);
			}
			else {
				mainFont.drawString(passwordInput, enterPasswordBTN.x + 10, enterPasswordBTN.y + 30);
			}
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
			if (hidePasword) {
				hiddenPassword = string(reenterPasswordInput.length(), '*');
				mainFont.drawString(hiddenPassword, reEnterPasswordBTN.x + 10, reEnterPasswordBTN.y + 30);
			}
			else {
				mainFont.drawString(reenterPasswordInput, reEnterPasswordBTN.x + 10, reEnterPasswordBTN.y + 30);
			}
		}
	}

	if (state == States::HOME) {
		ofSetColor(50);
		headFont.drawString("Home", ofGetWidth() / 2 - headFont.stringWidth("Home") / 2, 100);
		ofSetColor(225);
		backIMG.draw(backBTN);
		ofDrawRectangle(searchBTN);

		if (searchInput.empty()) {
			ofSetColor(150);
			mainFont.drawString(emptySearch, searchBTN.x + 10, searchBTN.y + 30);
		}
		else {
			ofSetColor(0);
			mainFont.drawString(searchInput, searchBTN.x + 10, searchBTN.y + 30);
		}
		if (searchIndex != -1) { // checks whether the user has tryed to search
			// clear search button
			ofSetColor(200, 50, 50); 
			ofDrawRectangle(clearSearchBTN);
			ofSetColor(255);
			mainFont.drawString("Clear Search", clearSearchBTN.x + 10, clearSearchBTN.y + 25);

			int i = searchIndex;
			ofSetColor(225);
			ofDrawRectangle(passwordBox.x, passwordBox.y, passwordBox.width, passwordBox.height);
			eyeIMG.draw(passwordBox.x + 350, passwordBox.y + 55, 35, 35);
			ofSetColor(50);
			mainFont.drawString(service[i], passwordBox.x + 10, passwordBox.y - 20);
			mainFont.drawString("Username: ", passwordBox.x + 10, passwordBox.y + 30);
			mainFont.drawString(username[i], passwordBox.x + 100, passwordBox.y + 30);
			mainFont.drawString("password: ", passwordBox.x + 10, passwordBox.y + 80);
			if (hidePasswordList[i]) {
				hiddenPassword = string(password[i].length(), '*');
				mainFont.drawString(hiddenPassword, passwordBox.x + 100, passwordBox.y + 80);
			}
			else {
				mainFont.drawString(password[i], passwordBox.x + 100, passwordBox.y + 80);
			}
		}
		else { // no search applied
			for (int i = 0; i < service.size(); i++) {
				ofSetColor(225);
				ofDrawRectangle(passwordBox.x, passwordBox.y + i * 150, passwordBox.width, passwordBox.height);
				eyeIMG.draw(passwordBox.x + 350, passwordBox.y + i * 150 + 55, 35, 35);
				ofSetColor(50);
				mainFont.drawString(service[i], passwordBox.x + 10, passwordBox.y + (i * 150) - 20);
				mainFont.drawString("Username: ", passwordBox.x + 10, passwordBox.y + (i * 150) + 30);
				mainFont.drawString(username[i], passwordBox.x + 100, passwordBox.y + (i * 150) + 30);
				mainFont.drawString("password: ", passwordBox.x + 10, passwordBox.y + (i * 150) + 80);
				if (hidePasswordList[i]) {
					hiddenPassword = string(password[i].length(), '*');
					mainFont.drawString(hiddenPassword, passwordBox.x + 100, passwordBox.y + (i * 150) + 80);
				}
				else {
					mainFont.drawString(password[i], passwordBox.x + 100, passwordBox.y + (i * 150) + 80);
				}
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) { // for typing into boxes 
	if (typingUsername) { // allows input if the user clicked onto the username box
		if (key == OF_KEY_BACKSPACE && usernameInput.length() > 0) {
			usernameInput = usernameInput.substr(0, usernameInput.length() - 1); // removes the last inputted character
		}
		else if (key >= 32 && key <= 126 && usernameInput.length() < maxWordCount) { // only allow printable characters
			usernameInput += (char)key;
		}
		// enter key goes to the next box?
	}
	else if (typingPassword) {
		if (key == OF_KEY_BACKSPACE && passwordInput.length() > 0) {
			passwordInput = passwordInput.substr(0, passwordInput.length() - 1);
		}
		else if (key >= 32 && key <= 126 && passwordInput.length() < maxWordCount) {
			passwordInput += (char)key;
		}
	}
	else if (retypingPassword) {
		if (key == OF_KEY_BACKSPACE && reenterPasswordInput.length() > 0) {
			reenterPasswordInput = reenterPasswordInput.substr(0, reenterPasswordInput.length() - 1);
		}
		else if (key >= 32 && key <= 126 && reenterPasswordInput.length() < maxWordCount) {
			reenterPasswordInput += (char)key;
		}
	}
	else if (searching) {
		if (key == OF_KEY_BACKSPACE && searchInput.length() > 0) {
			searchInput = searchInput.substr(0, searchInput.length() - 1);
		}
		else if (key >= 32 && key <= 126 && searchInput.length() < maxWordCount) {
			searchInput += (char)key;
		}
		else if (key == OF_KEY_RETURN) {
			search();
		}
	}
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (state == States::MENU) { // when the mouse is pressed checks to see if the coordinates match with the button
		if (createBTN.inside(x, y)) {
			state = States::CREATE;
			clearInput();
			return;
		}
		if (loginBTN.inside(x, y)) {
			state = States::LOGIN;
			clearInput();
			return;
		}
		if (homeBTN.inside(x, y)) {
			state = States::HOME;
			clearInput();
			return;
		}
	}

	if (state == States::LOGIN) {
		if (loginBTN.inside(x, y)) {
			state = States::HOME;
			clearInput();
			return;
		}
		if (createBTN.inside(x, y)) {
			state = States::CREATE;
			clearInput();
			return;
		}
	}

	if (state == States::CREATE) {
		if (loginBTN.inside(x, y)) {
			state = States::LOGIN;
			clearInput();
			return;
		}
		if (createBTN.inside(x, y)) {
			state = States::HOME;
			clearInput();
			return;
		}
	}

	if (state == States::HOME) {
		for (int i = 0; i < service.size(); i++) {
			ofRectangle eyeArea(passwordBox.x + 350, passwordBox.y + i * 150 + 55, 35, 35);
			if (eyeArea.inside(x, y)) {
				hidePasswordList[i] = !hidePasswordList[i];
				break;
			}
		}
		if (searchIndex != -1 && clearSearchBTN.inside(x, y)) {
			searchIndex = -1;
		}
	}
	
	if (exitBTN.inside(x, y)) { // exits the solution
		ofExit();
	}
	if (backBTN.inside(x, y)) {
		state = States::MENU;
		clearInput();
	}
	if (hidePasswordBTN.inside(x, y)) {
		hidePasword = !hidePasword;
	}
	if (usernameBTN.inside(x, y) && (state == States::LOGIN || state == States::CREATE)) { // tells the system what text box should be active
		typingUsername = true;
		typingPassword = false;
		retypingPassword = false;
		searching = false;
	}
	else if (enterPasswordBTN.inside(x, y) && (state == States::LOGIN || state == States::CREATE)) {
		typingUsername = false;
		typingPassword = true;
		retypingPassword = false;
		searching = false;
	}
	else if (reEnterPasswordBTN.inside(x, y) && (state == States::LOGIN || state == States::CREATE)) {
		typingUsername = false;
		typingPassword = false;
		retypingPassword = true;
		searching = false;
	}
	else if (searchBTN.inside(x, y) && state == States::HOME) {
		typingUsername = false;
		typingPassword = false;
		retypingPassword = false;
		searching = true;
	}
	else {
		typingUsername = false;
		typingPassword = false;
		retypingPassword = false;
		searching = false;
	}
}

void ofApp::clearInput() {
	usernameInput.clear();
	passwordInput.clear();
	reenterPasswordInput.clear();
	searchInput.clear();
}

void ofApp::search() {
	for (int i = 0; i < service.size(); i++) {
		if (searchInput == service[i]) {
			searchIndex = i;
			searchInput.clear();
			emptySearch = "Search";
			break;
		} 
		else if (i == service.size() - 1) { // if the user input doesn't match anything
			searchInput.clear();
			emptySearch = "Invalid search";
			searchIndex = -1;
		}
	}
}