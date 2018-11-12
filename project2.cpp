/*======================================================================================
 PROGRAMMER:			Zackh Tucker & Josiah McGurty
 COURSE:					CSC-525-001
 MODIFIED BY:			Zackh Tucker <tucker117> & Josiah McGurty <McGurty1337>
 ELECTRONIC FILE LOCATIONS:	\\trace\Class\CSC-525-625\001\tucker117\projects\project2\
                            \\trace\Class\CSC-525-625\001\McGurty1337\projects\project2\
 CONTRIBUTION BREAKDOWN:
 LAST MODIFIED DATE:		11.11.2018
 DESCRIPTION:			Lab project 2, learning to use GLUT to create
                   a (very) simple text editor with a few options.
 NOTE:
 FILES:						project2.cpp, (labProject.sln, ...)
 IDE/COMPILER:		MicroSoft Visual Studio 2017
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	1.		Double click on projProject.sln	to OPEN the project
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+F5					to EXECUTE
======================================================================================*/

#include <iostream>
#include <fstream>
#include <GL/glut.h>
#include <string>
#include <vector>

using namespace std;

vector <string> textStringVector = { "" };
int lineNumber = 0; int lineHeight = 30;
int editorWindow; int infoWindow;
int font = 2; int color = 1;
int intX = 0; int intY = 0;

void drawHelpMessage() {
	string s1 = "Welcome to the best text editor ever!";
	string s2 = "You may select from three fonts, three colors and even save your work!";
	string s3 = "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ";
	string s4 = "You may hide this window at any time by left-clicking in it.";
	string s5 = "Use the right-click menu in the Editor Window to:";
	string s6 = "-Display this Information Window";
	string s7 = "-Select text options (Font, Color)";
	string s8 = "-Save your work to a text file (C:\\TEMP\\typed.txt)";
	string s9 = "-Exit the program";
	glColor3f(1.0, 1.0, 1.0); glRasterPos2f(5, 245);
	for (int i = 0; i < s1.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int(s1[i]));
	} glRasterPos2f(5, 215); for (int i = 0; i < s2.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int(s2[i]));
	} glRasterPos2f(5, 185); for (int i = 0; i < s3.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int(s3[i]));
	} glRasterPos2f(5, 155); for (int i = 0; i < s4.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int(s4[i]));
	} glRasterPos2f(5, 125); for (int i = 0; i < s5.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int(s5[i]));
	} glRasterPos2f(45, 95); for (int i = 0; i < s6.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int(s6[i]));
	} glRasterPos2f(45, 65); for (int i = 0; i < s7.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int(s7[i]));
	} glRasterPos2f(45, 35); for (int i = 0; i < s8.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int(s8[i]));
	} glRasterPos2f(45, 05); for (int i = 0; i < s9.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, int(s9[i]));
	} glEnd();
}

/*
	This function returns the length of a line of a string Vector
	without any formatting characters counted.

	Font: ^Ff0 (8x13), ^Ff1 (9x15), ^Ff2 (Helv 12)
	Color: ^Cc0 (Red), ^Cc1 (Green), ^Cc2 (Blue)
*/
int getLineLength(vector <string> stringVector, int lineNumber) {
	int count = 0;
	for (int i = 0; i < stringVector[lineNumber].length(); i++) {
		//cout << stringVector[lineNumber][i];
		/*if (stringVector[lineNumber][i] == '^') {
			count -= 4; i += 4;
		}*/
		count += 1;
	}
	//cout << "Count: " << count << endl;
	return count;
}

void drawInputText() {
	glPointSize(1); // change point size to 1
	if (color == 0) {glColor3f(1.0, 0.0, 0.0);} // change drawing color to red
	if (color == 1) {glColor3f(0.0, 1.0, 0.0);} // change drawing color to green
	if (color == 2) {glColor3f(0.193, 0.459, 0.778);} // change drawing color to blue
	if ((textStringVector[lineNumber].length() % 45 == 0 && textStringVector[lineNumber].length() != 0) || lineNumber == 0) {
		// if line is not empty and has 45 characters in length OR it's the first line
		// increment lineNumber and create a new string in the vector for a new line of text
		lineNumber++;
		textStringVector.push_back("");
	} for (int h = 0; h <= lineNumber; h++) {
		int y = (1000 - (lineHeight * h));
		int pos [] = {0, 0, 0, 0};
		glRasterPos2i(0, y);
		glGetIntegerv(GL_CURRENT_RASTER_POSITION, pos);
		//cout << "X pos: " << pos[0] << "; Y pos: " << pos[1] << endl;
		for (int i = 0; i < textStringVector[h].length(); i++) {
			if (font == 0) {glutBitmapCharacter(GLUT_BITMAP_8_BY_13, textStringVector[h][i]);}
			if (font == 1) {glutBitmapCharacter(GLUT_BITMAP_9_BY_15, textStringVector[h][i]);}
			if (font == 2) {glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, textStringVector[h][i]);}
		}
	}
}

//***********************************************************************************
void myInfoDisplayCallback() {
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background
	drawHelpMessage(); glFlush(); // flush out the buffer contents
}

//***********************************************************************************
void myEditorDisplayCallback() {
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background
	drawInputText(); glFlush(); // flush out the buffer contents
}

//***********************************************************************************
void myInfoInit() {
	glClearColor(0.1, 0.1, 0.1, 0); // specify a background clor: dark gray
	gluOrtho2D(0, 710, 0, 270);	// specify a viewing area
}

//***********************************************************************************
void myEditorInit() {
 	glClearColor(0.1, 0.1, 0.1, 0); // specify a background clor: dark gray
	gluOrtho2D(0, 600, 0, 1000);	// specify a viewing area
}

//***********************************************************************************
void myInfoMouseCallback(int button, int state, int mouseX, int mouseY) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		glutDestroyWindow(infoWindow); glutSetWindow(editorWindow);
	}
}

//***********************************************************************************
void myEditorMouseCallback(int button, int state, int mouseX, int mouseY) {
	if ((button == GLUT_LEFT_BUTTON || button == GLUT_MIDDLE_BUTTON) &&
	 		 state == GLUT_DOWN) {
		cout << "mouseX: " << mouseX << ", mouseY: " << mouseY << endl;
		intX = mouseX; intY = mouseY;
	}
}

//***********************************************************************************
void runMainMenu(int x) {
	if (x == 9) {exit(0);}
	if (x == 1) { //dump this to a text file instead of console
		ofstream outfile ("C:\\TEMP\\typed.txt");
		if (outfile.is_open()) {
			for (int h = 0; h <= lineNumber; h++) {
			 for (int i = 0; i < textStringVector[h].length(); i++) {
				outfile << textStringVector[h][i];
		}
		outfile << endl;
	}
} else { cout << "Error outputting file\n"; }
} if (x == 0) {
		glutSetWindow(infoWindow);
		if (glutGetWindow() == 2) { // Only re-create the Info Window if it does not exist
			glutInitWindowSize(710, 270);
			glutInitWindowPosition(750, 0);
			infoWindow = glutCreateWindow("Information Window");
			myInfoInit();
			glutDisplayFunc(myInfoDisplayCallback);
			glutMouseFunc(myInfoMouseCallback);
		}
	}
}

//***********************************************************************************
void runFontMenu(int x) {
	myEditorDisplayCallback();
	if (x == 0) {font = 0;} // Times New Roman (10 pt)
	if (x == 1) {font = 1;} // Helvetica (10 pt)
	if (x == 2) {font = 2;} // Bitmap Font (8x13)
}

//***********************************************************************************
void runColorMenu(int x) {
	myEditorDisplayCallback();
	if (x == 0) {color = 0;} // Red
	if (x == 1) {color = 1;} // Green
	if (x == 2) {color = 2;} // Blue
}

//***********************************************************************************
void myEditorTypingFunc(unsigned char key, int x, int y) {
	if (key == 13) { //Enter (Carriage Return)
		lineNumber++;
		textStringVector.push_back("");
	} else if (key == 8) { //Backspace
		if (textStringVector[lineNumber].length() == 0 && lineNumber != 1) {
			lineNumber--;
			textStringVector.pop_back();
		} else if (textStringVector[lineNumber].length() == 0 && lineNumber == 1) {
			cout << "System Sound\n";
		} else {
			textStringVector[lineNumber].pop_back();
			//if none of the other conditions are met,
			//then pop the last char and continue.
		}
	} else if (key == 94) { /* do not a thing */ } else {
		textStringVector[lineNumber] += key;
		//cout << "Key: " << key << endl;
	} glutPostRedisplay();
}

//***********************************************************************************
int main(int argc, char ** argv) {
	glutInit(& argc, argv); // optional in some environments

	// Information Window Initialization
	glutInitWindowSize(710, 270);
	glutInitWindowPosition(750, 0);
	infoWindow = glutCreateWindow("Information Window");
	myInfoInit();
	glutDisplayFunc(myInfoDisplayCallback);
	glutMouseFunc(myInfoMouseCallback);

	// Editor Window Initialization
	glutInitWindowSize(600, 1000);
	glutInitWindowPosition(100, 0);
	editorWindow = glutCreateWindow("Editor Window");
	myEditorInit();
	glutDisplayFunc(myEditorDisplayCallback);
	glutKeyboardFunc(myEditorTypingFunc);
	glutMouseFunc(myEditorMouseCallback);

	// Font Menu Initialization
	int fontMenu = glutCreateMenu(runFontMenu);
	glutAddMenuEntry("Bitmap Font (8 x 13)", 0);
	glutAddMenuEntry("Bitmap Font (9 x 15)", 1);
	glutAddMenuEntry("Helvetica (12 point)", 2);

	// Color Menu Initialization
	int colorMenu = glutCreateMenu(runColorMenu);
	glutAddMenuEntry("Red", 0);
	glutAddMenuEntry("Green", 1);
	glutAddMenuEntry("Blue", 2);

	// Right-click Menu Initialization
	int mainMenu = glutCreateMenu(runMainMenu);
	glutAddMenuEntry("Information Window", 0);
	glutAddSubMenu("Font Selection", fontMenu);
	glutAddSubMenu("Color Selection", colorMenu);
	glutAddMenuEntry("Save to text (C:\\TEMP\\typed.txt)", 1);
	glutAddMenuEntry("Exit", 9);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop(); // Get into an infinite loop

	return 0;
}
