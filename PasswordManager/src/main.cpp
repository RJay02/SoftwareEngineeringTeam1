#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){	
	ofGLFWWindowSettings settings;
	settings.resizable = false; // Disable window resizing
	settings.decorated = true;  // Keep window title bar (set to false for borderless)
	settings.setSize(1280, 720); // Sets window size
	ofCreateWindow(settings);
	ofRunApp(new ofApp());
}

/*
int main() {
	ofSetupOpenGL(1024, 768, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
		ofRunApp(new ofApp());
*/