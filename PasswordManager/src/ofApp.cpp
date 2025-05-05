#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	state = States::MENU; // sets the initial state to menu
	ofBackground(255);

	//loading font files
	mainFont.load("font.otf", 12);
	subFont.load("sub.otf", 17);
	headFont.load("header.ttf", 22);

	// load text, images here

	// set coordinates for buttons
	// ofGetWidth() / 2 - 100 centering (- 100 is half othe box width)
	exitBTN.set(ofGetWidth() - 75, 25, 50, 50);
	usernameBTN.set(ofGetWidth() / 2 - 100, 200, 200, 50);
	enterPasswordBTN.set(ofGetWidth() / 2 - 100, 200, 200, 50);
	createBTN.set(ofGetWidth() / 2 - 100, 300, 200, 50);
	loginBTN.set(ofGetWidth() / 2 - 100, 400, 200, 50);
	homeBTN.set(ofGetWidth() / 2 - 100, 500, 200, 50);
}


//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(50); // draws all of the buttons as assigned in setup
	ofDrawRectangle(exitBTN);
	ofSetColor(255);
	mainFont.drawString("Exit", ofGetWidth() - 50 - mainFont.stringWidth("Exit") / 2, 50 + mainFont.getSize() / 2);

	if (state == States::MENU) { // checking the state and drawing the designated text
		ofSetColor(50); // draws all of the buttons as assigned in setup
		ofDrawRectangle(createBTN);
		ofDrawRectangle(loginBTN);
		ofDrawRectangle(homeBTN);
		ofSetColor(255); // drawing the text onto the buttons
		headFont.drawString("Create", ofGetWidth() / 2 - headFont.stringWidth("Create") / 2, 335);
		headFont.drawString("Login", ofGetWidth() / 2 - headFont.stringWidth("Login") / 2, 435);
		headFont.drawString("Home", ofGetWidth() / 2 - headFont.stringWidth("Home") / 2, 535);
		ofSetColor(50);
		headFont.drawString("Password Manager", ofGetWidth() / 2 - headFont.stringWidth("Password Manager") / 2, 100);
	}

	if (state == States::CREATE) {
		ofSetColor(50);
		headFont.drawString("Create", ofGetWidth() / 2 - headFont.stringWidth("Create") / 2, 100);
	}

	if (state == States::LOGIN) {
		ofSetColor(50);
		headFont.drawString("Login", ofGetWidth() / 2 - headFont.stringWidth("Login") / 2, 100);
	}

	if (state == States::HOME) {
		ofSetColor(50);
		headFont.drawString("Home", ofGetWidth() / 2 - headFont.stringWidth("Home") / 2, 100);
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	if (menuBTN.inside(x, y)) { // when the mouse is pressed checks to see if the coordinates match with the button
		state = States::MENU;
	}
	if (createBTN.inside(x, y)) {
		state = States::CREATE;
	}
	if (loginBTN.inside(x, y)) {
		state = States::LOGIN;
	}
	if (homeBTN.inside(x, y)) {
		state = States::HOME;
	}
	if (exitBTN.inside(x, y)) {
		ofExit();
	}
}