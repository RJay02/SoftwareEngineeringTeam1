#include "ofApp.h"

//--------------------------------------------------------------
// Setup: Initialize UI elements, fonts, and default state
//--------------------------------------------------------------
void ofApp::setup() {
	state = States::MENU; // sets the initial state to menu
	ofBackground(18, 50, 75); // sets initial background colour

	// load font files
	mainFont.load("font.otf", 12);
	subFont.load("sub.otf", 17);

	// load image files
	headFont.load("header.ttf", 22);
	backIMG.load("back.png");
	eyeIMG.load("eye-icon.png");
	deleteIMG.load("delete.png");
	addIMG.load("add.png");
	upIMG.load("up.png");
	downIMG.load("down.png");
	logoIMG.load("LockR-Logo-transparent.png");

	// set coordinates for buttons
	exitBTN.set(ofGetWidth() - 75, 25, 50, 50);
	usernameBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 200, ofGetWidth() - 200, 50);
	enterPasswordBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 350, ofGetWidth() - 200, 50);
	reEnterPasswordBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 500, ofGetWidth() - 200, 50);
	createBTN.set(ofGetWidth() / 2 - 128, 650, 260, 50);
	loginBTN.set(ofGetWidth() / 2 - 128, 570, 260, 50);
	backBTN.set(15, 25, 50, 50);
	hidePasswordBTN.set(enterPasswordBTN.x + enterPasswordBTN.width + 10, enterPasswordBTN.y, 50, enterPasswordBTN.height);
	searchBTN.set(200, 200, ofGetWidth() - 400, 50);
	clearSearchBTN.set(200, searchBTN.y - 50, 150, 40); 
	passwordBox.set(300, 300, ofGetWidth() - 600, 100);
	serviceBTN.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 300, ofGetWidth() - 200, 50);
	usernameBTNNew.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 400, ofGetWidth() - 200, 50);
	passwordBTNNew.set(ofGetWidth() / 2 - (ofGetWidth() - 200) / 2, 500, ofGetWidth() - 200, 50);
	cancelNewEntryBTN.set(ofGetWidth() / 2 + 250, passwordBTNNew.y + 70, 100, 40);
	confirmNewEntryBTN.set(ofGetWidth() / 2 - 350, passwordBTNNew.y + 70, 100, 40);
	scrollUpBTN.set(ofGetWidth() - 170, ofGetHeight() / 2 - 50, 120, 50);
	scrollDownBTN.set(ofGetWidth() - 170, ofGetHeight() / 2 + 50, 120, 50);

	hidePasswordList = vector<bool>(password.size(), true); // initially hide all passwords

	confirmDeleteYesBTN.set(200, 500, 100, 40); // Confirm button
	confirmDeleteNoBTN.set(350, 500, 100, 40);  // Cancel button
	readUsers(); //fetches all the accounts
}


//--------------------------------------------------------------
// Draw: Draw UI based on the current state
//--------------------------------------------------------------
void ofApp::draw() {
	// sets gradient background colour
	ofColor topColour(14, 82, 135);
	ofColor bottomColour(18, 50, 75);
	ofBackgroundGradient(topColour, bottomColour, OF_GRADIENT_LINEAR);

	// Draw Exit Button
	ofSetColor(65, 87, 103); // sets colour of following object(s)
	ofDrawRectRounded(exitBTN.x, exitBTN.y, exitBTN.width, exitBTN.height, 10); // Draw button based on values set in setup
	//Draw Exit button outline
	ofNoFill(); // Disable fill colour (outline only)
	ofSetColor(255);
	ofSetLineWidth(3);
	ofDrawRectRounded(exitBTN.x, exitBTN.y, exitBTN.width, exitBTN.height, 20);
	ofFill();
	mainFont.drawString("Exit", ofGetWidth() - 50 - mainFont.stringWidth("Exit") / 2, 50 + mainFont.getSize() / 2); // drawing text on screen

	// Draw Menu Screen
	if (state == States::MENU) { // checking the state and drawing the designated objects

		// Draw Menu Buttons
		ofSetColor(65, 87, 103);
		ofDrawRectRounded(createBTN.x, createBTN.y, createBTN.width, createBTN.height, 20);
		ofDrawRectRounded(loginBTN.x, loginBTN.y, loginBTN.width, loginBTN.height, 20);

		// Draw Menu Button Outlines
		ofNoFill(); // Disable fill colour (outline only)
		ofSetColor(255);   // border colour
		ofSetLineWidth(3);  // border thickness
		ofDrawRectRounded(createBTN.x, createBTN.y, createBTN.width, createBTN.height, 20); // Create outline
		ofDrawRectRounded(loginBTN.x, loginBTN.y, loginBTN.width, loginBTN.height, 20); // Login outline
		ofFill();

		// Draw Menu Button text
		headFont.drawString("Create Account", ofGetWidth() / 2 - headFont.stringWidth("Create Account") / 2, createBTN.y + 35);
		headFont.drawString("Login", ofGetWidth() / 2 - headFont.stringWidth("Login") / 2, loginBTN.y + 35);

		// Draw LockR Title
		ofNoFill(); 
		ofSetColor(255); 
		ofDrawRectRounded(380, 10, 520, 80, 20);
		ofFill();
		headFont.drawString("LockR: Password Manager", ofGetWidth() / 2 - headFont.stringWidth("LockR: Password Manager") / 2, 60);

		// Draw LockR Logo
		logoIMG.draw((ofGetWidth() / 2) - 150, 130, 300, 300);
	}

	if (state == States::LOGIN or state == States::CREATE) { // if its either login or create screen
		ofSetColor(65, 87, 103);
		ofDrawRectRounded(createBTN.x - 48, createBTN.y, createBTN.width + 90, createBTN.height, 20);
		ofDrawRectRounded(loginBTN.x - 48, loginBTN.y, loginBTN.width + 90, loginBTN.height, 20);
		ofSetColor(225);
		ofDrawRectRounded(usernameBTN.x, usernameBTN.y, usernameBTN.width, usernameBTN.height, 20);
		ofDrawRectRounded(enterPasswordBTN.x, enterPasswordBTN.y, enterPasswordBTN.width, enterPasswordBTN.height, 20);
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
	// Draw Login Screen
	if (state == States::LOGIN) { 
		// Draw Login title
		ofSetColor(255);
		headFont.drawString("Login", ofGetWidth() / 2 - headFont.stringWidth("Login") / 2, 100);	
		ofNoFill();
		ofDrawRectRounded(580, 60, 125, 60, 20);
		ofFill();
		headFont.drawString("Login", ofGetWidth() / 2 - headFont.stringWidth("Login") / 2, 605);
		headFont.drawString("Don't have an account?", ofGetWidth() / 2 - headFont.stringWidth("Don't have an account?") / 2, 685);
	}
	
	// Draw Create Screen
	if (state == States::CREATE) {
		ofSetColor(50);
		headFont.drawString("Create", ofGetWidth() / 2 - headFont.stringWidth("Create") / 2, 100);
		ofSetColor(255);
		headFont.drawString("Already have an account ?", ofGetWidth() / 2 - headFont.stringWidth("Already have an account ?") / 2, 605);
		headFont.drawString("Create account", ofGetWidth() / 2 - headFont.stringWidth("Create account") / 2, 685);
		ofSetColor(225);
		ofDrawRectRounded(reEnterPasswordBTN, 20); 

		if (!createAccountErrorMsg.empty()) {
			ofSetColor(255, 0, 0); // red for error
			mainFont.drawString(createAccountErrorMsg, ofGetWidth() / 2 - mainFont.stringWidth(createAccountErrorMsg) / 2, 580);
		}

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

	// Draw Home Screen
	if (state == States::HOME) {

		ofSetColor(225);
		headFont.drawString("Home", ofGetWidth() / 2 - headFont.stringWidth("Home") / 2, 100);
		subFont.drawString(currentUser, ofGetWidth() / 2 - subFont.stringWidth(currentUser) / 2, 150);
		backIMG.draw(backBTN);
		ofDrawRectRounded(searchBTN, 20);
		

		if (searchInput.empty()) {
			ofSetColor(150);
			mainFont.drawString(emptySearch, searchBTN.x + 10, searchBTN.y + 30);
		}
		else {
			ofSetColor(0);
			mainFont.drawString(searchInput, searchBTN.x + 10, searchBTN.y + 30);
		}
		addIMG.draw(searchBTN.x + 820, searchBTN.y, 50, 50);

		glEnable(GL_SCISSOR_TEST); // chatgpt was used to generate the code with the prompt: how to stop rendering areas in open frameworks
		glScissor(0, 0, ofGetWidth(), ofGetHeight() - 250);  

		ofPushMatrix();
		ofTranslate(0, -scrollOffset); // apply scroll 

		if (searchIndex != -1 && user[searchIndex] == currentUser) { // checks whether the user has tried to search and if search matches the current user
			// clear search button
			ofSetColor(200, 50, 50); 
			ofDrawRectRounded(clearSearchBTN, 20);
			ofSetColor(255);
			mainFont.drawString("Clear Search", clearSearchBTN.x + 10, clearSearchBTN.y + 25);

			int i = searchIndex;
			ofSetColor(225);
			ofDrawRectRounded(passwordBox.x, passwordBox.y, passwordBox.width, passwordBox.height, 20);
			eyeIMG.draw(passwordBox.x + 630, passwordBox.y + 55, 35, 35);
			deleteIMG.draw(passwordBox.x + 635, passwordBox.y + 10, 25, 25);
			ofSetColor(225);
			subFont.drawString(service[i], passwordBox.x + 10, passwordBox.y - 20);  // fixed position
			ofSetColor(50);
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
		// no search applied
		else { 
			ofSetColor(255);
			upIMG.draw(scrollUpBTN);
			downIMG.draw(scrollDownBTN);
			int displayCount = 0;

			for (int i = 0; i < service.size(); i++) {
				if (user[i] != currentUser) continue;

				ofSetColor(225);
				ofDrawRectRounded(passwordBox.x, passwordBox.y + displayCount * 150, passwordBox.width, passwordBox.height, 20);
				eyeIMG.draw(passwordBox.x + 630, passwordBox.y + displayCount * 150 + 55, 35, 35);
				deleteIMG.draw(passwordBox.x + 635, passwordBox.y + displayCount * 150 + 10, 25, 25);

				ofSetColor(225);
				subFont.drawString(service[i], passwordBox.x + 10, passwordBox.y + (displayCount * 150) - 20);
				ofSetColor(50);
				mainFont.drawString("Username: ", passwordBox.x + 10, passwordBox.y + (displayCount * 150) + 30);
				mainFont.drawString(username[i], passwordBox.x + 100, passwordBox.y + (displayCount * 150) + 30);
				mainFont.drawString("password: ", passwordBox.x + 10, passwordBox.y + (displayCount * 150) + 80);

				if (hidePasswordList[i]) {
					hiddenPassword = string(password[i].length(), '*');
					mainFont.drawString(hiddenPassword, passwordBox.x + 100, passwordBox.y + (displayCount * 150) + 80);
				}
				else {
					mainFont.drawString(password[i], passwordBox.x + 100, passwordBox.y + (displayCount * 150) + 80);
				}

				displayCount++;
			}
		}

		if (addingNewEntry) {
			ofSetColor(0, 0, 0, 150); // semi-transparent dark overlay
			ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
			ofSetColor(200);
			ofDrawRectangle(serviceBTN.x - 10, serviceBTN.y - 30, serviceBTN.width + 20, (passwordBTNNew.y + passwordBTNNew.height) - (serviceBTN.y - 30) + 10);
			ofSetColor(180, 50, 50);  
			ofDrawRectangle(cancelNewEntryBTN);
			ofSetColor(50, 180, 50);
			ofDrawRectangle(confirmNewEntryBTN);
			ofSetColor(255);
			mainFont.drawString("Cancel", cancelNewEntryBTN.x + 20, cancelNewEntryBTN.y + 25);
			mainFont.drawString("Confirm", confirmNewEntryBTN.x + 20, confirmNewEntryBTN.y + 25);
			ofSetColor(0);
			ofDrawRectangle(serviceBTN);
			ofDrawRectangle(usernameBTNNew);
			ofDrawRectangle(passwordBTNNew);
			ofSetColor(50);
			mainFont.drawString("Service:", serviceBTN.x, serviceBTN.y - 10);
			mainFont.drawString("Username:", usernameBTNNew.x, usernameBTNNew.y - 10);
			mainFont.drawString("Password:", passwordBTNNew.x, passwordBTNNew.y - 10);

			// Service Input
			if (newServiceInput.empty()) {
				ofSetColor(150);
				mainFont.drawString("Enter service", serviceBTN.x + 10, serviceBTN.y + 30);
			}
			else {
				ofSetColor(255);
				mainFont.drawString(newServiceInput, serviceBTN.x + 10, serviceBTN.y + 30);
			}

			// Username Input
			if (newUsernameInput.empty()) {
				ofSetColor(150);
				mainFont.drawString("Enter username", usernameBTNNew.x + 10, usernameBTNNew.y + 30);
			}
			else {
				ofSetColor(255);
				mainFont.drawString(newUsernameInput, usernameBTNNew.x + 10, usernameBTNNew.y + 30);
			}

			// Password Input
			if (newPasswordInput.empty()) {
				ofSetColor(150);
				mainFont.drawString("Enter password", passwordBTNNew.x + 10, passwordBTNNew.y + 30);
			}
			else {
				ofSetColor(255);
				mainFont.drawString(newPasswordInput, passwordBTNNew.x + 10, passwordBTNNew.y + 30);
			}
		}

		ofPopMatrix();  // end scroll
		glDisable(GL_SCISSOR_TEST);

		if (showingDeleteConfirmation) {
			ofSetColor(0, 0, 0, 150); // semi-transparent dark overlay
			ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());

			ofSetColor(255);
			int boxWidth = 400;
			int boxHeight = 150;
			int boxX = (ofGetWidth() - boxWidth) / 2;
			int boxY = (ofGetHeight() - boxHeight) / 2;

			ofSetColor(255);
			ofDrawRectangle(boxX, boxY, boxWidth, boxHeight);

			// Confirmation message text
			ofSetColor(0);
			mainFont.drawString("Are you sure you want to delete this entry?", boxX + 20, boxY + 50);

			// Buttons (repositioned relative to the box)
			confirmDeleteYesBTN.set(boxX + 50, boxY + 90, 100, 40);
			confirmDeleteNoBTN.set(boxX + 250, boxY + 90, 100, 40);

			// Draw Yes button
			ofSetColor(200, 50, 50);
			ofDrawRectangle(confirmDeleteYesBTN);
			ofSetColor(255);
			mainFont.drawString("Yes", confirmDeleteYesBTN.x + 30, confirmDeleteYesBTN.y + 25);

			// Draw No button
			ofSetColor(50, 180, 50);
			ofDrawRectangle(confirmDeleteNoBTN);
			ofSetColor(255);
			mainFont.drawString("No", confirmDeleteNoBTN.x + 35, confirmDeleteNoBTN.y + 25);
		}



	}
}

//--------------------------------------------------------------
// keyPressed: Handles keyboard interaction
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
	else if (addingNewEntry) {
		string* activeInput = nullptr;

		if (typingService) activeInput = &newServiceInput;
		else if (typingNewUsername) activeInput = &newUsernameInput;
		else if (typingNewPassword) activeInput = &newPasswordInput;

		if (activeInput != nullptr) {
			if (key == OF_KEY_BACKSPACE && activeInput->length() > 0) {
				*activeInput = activeInput->substr(0, activeInput->length() - 1);
			}
			else if (key >= 32 && key <= 126 && activeInput->length() < maxWordCount) {
				*activeInput += (char)key;
			}
		}
	}
}

//--------------------------------------------------------------
// mousePressed: Handles Mouse interaction
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
	}

	if (state == States::LOGIN) {
		if (loginBTN.inside(x - 48, y)) {
			validLogin = false;
			for (int i = 0; i < masterUsername.size(); i++) {
				if (usernameInput == masterUsername[i] && passwordInput == masterPassword[i]) {
					validLogin = true;
					break;
				}
			}
			if (validLogin) {
				currentUser = usernameInput;
				state = States::HOME;
				readPasswords();
				clearInput();
			}
			else {
				clearInput(); // add feedback to the user that the input was invalid?
			}
			return;
		}
		if (createBTN.inside(x - 48, y)) {
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
			if (passwordInput != reenterPasswordInput) {
				createAccountErrorMsg = "Passwords do not match.";
			}
			else {
				string passwordValidationResult = isValidPassword(passwordInput);
				if (!passwordValidationResult.empty()) {
					createAccountErrorMsg = passwordValidationResult;
				}
				else {
					masterUsername.push_back(usernameInput);
					masterPassword.push_back(passwordInput);
					currentUser = usernameInput;
					ofstream outUsersFile("Users.csv", ios::app);
					if (outUsersFile.is_open()) {
						outUsersFile << usernameInput << "," << passwordInput << '\n';
						outUsersFile.close();
					}
					else {
						cout << "Error: failed to access users file." << endl;
					}
					state = States::HOME;
					readPasswords();
					createAccountErrorMsg.clear();
					clearInput();
					return;
				}
			}
		}
	}

	if (state == States::HOME) {

		// logic for scrolling
		if (scrollDownBTN.inside(x, y)) {
			scrollOffset = max(0.0f, scrollOffset - scrollStep);
		}
		if (scrollUpBTN.inside(x, y)) {
			maxScrollOffset = max(0.0f, (float)(service.size() * 130) - ofGetHeight());
			scrollOffset = min(scrollOffset + scrollStep, maxScrollOffset);
		}

		int adjustedY = y + scrollOffset;  // Adjust y for scrolling content
		int displayCount = 0;

		for (int i = 0; i < service.size(); i++) {
			if (user[i] != currentUser) continue;

			ofRectangle deleteArea(passwordBox.x + 390, passwordBox.y + displayCount * 150 + 10, 25, 25);
			if (deleteArea.inside(x, adjustedY)) {
				showingDeleteConfirmation = true;
				deleteCandidateIndex = i;
				return;
			}
			if (showingDeleteConfirmation) {
				if (confirmDeleteYesBTN.inside(x, y)) {
					if (deleteCandidateIndex != -1) {
						user.erase(user.begin() + deleteCandidateIndex);
						username.erase(username.begin() + deleteCandidateIndex);
						password.erase(password.begin() + deleteCandidateIndex);
						service.erase(service.begin() + deleteCandidateIndex);
						hidePasswordList.erase(hidePasswordList.begin() + deleteCandidateIndex);
						ofstream passwordFile("Passwords.csv");
						if (passwordFile.is_open()) {
							for (int j = 0; j < service.size(); j++) { 
								passwordFile << user[j] << "," << service[j] << "," << username[j] << "," << password[j] << '\n'; //rewrites the passwords file but without the newly deleted password 
							}
							passwordFile.close();
						}
						else {
							cout << "Error: failed to access password file." << endl;
						}
					}
					showingDeleteConfirmation = false;
					deleteCandidateIndex = -1;
					return;
				}
				if (confirmDeleteNoBTN.inside(x, y)) {
					showingDeleteConfirmation = false;
					deleteCandidateIndex = -1;
					return;
				}
			}
			ofRectangle eyeArea(passwordBox.x + 350, passwordBox.y + displayCount * 150 + 55, 35, 35);
			if (eyeArea.inside(x, adjustedY)) {
				hidePasswordList[i] = !hidePasswordList[i];
				break;
			}

			displayCount++;
		}

		ofRectangle addArea(searchBTN.x + 820, searchBTN.y, 50, 50);
		if (addArea.inside(x, y) && state == States::HOME) {
			addingNewEntry = true; // new boolean flag
			clearInput();
			return;
		}
		if (searchIndex != -1 && clearSearchBTN.inside(x, y)) {
			searchIndex = -1;
		}

		if (addingNewEntry) {
			if (serviceBTN.inside(x, y)) {
				typingService = true;
				typingNewUsername = false;
				typingNewPassword = false;
			}
			else if (usernameBTNNew.inside(x, y)) {
				typingService = false;
				typingNewUsername = true;
				typingNewPassword = false;
			}
			else if (passwordBTNNew.inside(x, y)) {
				typingService = false;
				typingNewUsername = false;
				typingNewPassword = true;
			}
			else {
				typingService = typingNewUsername = typingNewPassword = false;
			}
		}

		if (addingNewEntry && cancelNewEntryBTN.inside(x, y)) {
			addingNewEntry = false;    // Exit the add new service screen
			newServiceInput.clear();   // Optionally clear inputs
			newUsernameInput.clear();
			newPasswordInput.clear();
			typingService = typingNewUsername = typingNewPassword = false;
			return;
		}
		if (addingNewEntry && confirmNewEntryBTN.inside(x, y)) {
			for (int i = 0; i < service.size(); ++i) {
				if (user[i] == currentUser && service[i] == newServiceInput) {
					newServiceInput = "Service already exists";
					return; // Duplicate found, do nothing
				}
			}
			user.push_back(currentUser);
			service.push_back(newServiceInput);
			username.push_back(newUsernameInput);
			password.push_back(newPasswordInput);
			hidePasswordList.push_back(true);
			ofstream outPasswordFile("Passwords.csv", ios::app);
			if (outPasswordFile.is_open()) {
				outPasswordFile << currentUser << "," << newServiceInput << "," << newUsernameInput << "," << newPasswordInput << '\n';
				outPasswordFile.close();
			}
			else {
				cout << "Error: failed to access password file." << endl;
			}
			addingNewEntry = false;   
			newServiceInput.clear();
			newUsernameInput.clear();
			newPasswordInput.clear();
			typingService = typingNewUsername = typingNewPassword = false;
		}
	}
	
	if (exitBTN.inside(x, y)) { // exits the solution
		ofExit();
	}
	if (backBTN.inside(x, y)) {
		currentUser.clear();
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

//--------------------------------------------------------------
// clearInput: Clears text inputs
//--------------------------------------------------------------
void ofApp::clearInput() {
	usernameInput.clear();
	passwordInput.clear();
	reenterPasswordInput.clear();
	searchInput.clear();
}

//--------------------------------------------------------------
// search: Searches for password entries by service name
//--------------------------------------------------------------
void ofApp::search() {
	searchIndex = -1;  // Default to not found
	emptySearch = "Invalid search";

	for (int i = 0; i < service.size(); i++) {
		if (searchInput == service[i] && user[i] == currentUser) {
			searchIndex = i;
			emptySearch = "Search";
			break;  // Valid match found, stop loop
		}
	}

	searchInput.clear();  // Clear search either way
}

//--------------------------------------------------------------
// isValidPassword: Validates the password based on length and character requirements
//--------------------------------------------------------------
string ofApp::isValidPassword(const string& password) {
	if (password.length() < 12) return "Password is too short (min 12 characters).";

	bool hasUpper = false;
	bool hasDigit = false;

	for (char c : password) {
		if (isupper(c)) hasUpper = true;
		if (isdigit(c)) hasDigit = true;
	}

	if (!hasUpper) return "Password must include at least one uppercase letter.";
	if (!hasDigit) return "Password must include at least one number.";

	return ""; // Empty string means it's valid
}

//--------------------------------------------------------------
// readPasswords: Reads from the passwords file 
//--------------------------------------------------------------
void ofApp::readPasswords() {
	user.clear();
	service.clear();
	username.clear();			//needs to clear the vectors to prevent filling them with duplicate data
	password.clear();
	ifstream inPasswordFile("Passwords.csv");
	if (inPasswordFile.is_open()) {
		string line, readUser, readService, readUsername, readPassword;
		while (getline(inPasswordFile, line)) {
			stringstream stream(line);
			getline(stream, readUser, ',');
			user.push_back(readUser);
			getline(stream, readService, ',');
			service.push_back(readService);
			getline(stream, readUsername, ',');
			username.push_back(readUsername);
			getline(stream, readPassword, ',');
			password.push_back(readPassword);
			hidePasswordList.push_back(true);
		}
	}
	else {
		cout << "Error: failed to access password file." << endl;
	}
};

//--------------------------------------------------------------
// readUsers: Reads from the users file 
//--------------------------------------------------------------
void ofApp::readUsers() {
	masterUsername.clear();			
	masterPassword.clear();
	ifstream inPasswordFile("Users.csv");
	if (inPasswordFile.is_open()) {
		string line, readMUsername, readMPassword;
		while (getline(inPasswordFile, line)) {
			stringstream stream(line);
			getline(stream, readMUsername, ',');
			masterUsername.push_back(readMUsername);
			getline(stream, readMPassword, ',');
			masterPassword.push_back(readMPassword);
		}
	}
	else {
		cout << "Error: failed to access users file." << endl;
	}
};