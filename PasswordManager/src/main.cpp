#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp(new ofApp());

}


//Just added this function to make sure the screen is a fixed size and not rizeable but after implementing this the design around
//the buttons and the layout just got messed up so I just left it as a comment if someone wants to use it - RJ 
////========================================================================
//int main() {
//    ofGLFWWindowSettings settings;
//    settings.setSize(550, 900);          // Fixed resolution
//    settings.resizable = false;          // Disable window resizing
//    settings.decorated = true;           // Keep window title bar (set to false for borderless)
//    ofCreateWindow(settings);
//
//    ofRunApp(new ofApp());
//}