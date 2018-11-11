/*==================================================================================================
 PROGRAMMER:				Zackh Tucker // Josiah McGurty
 COURSE:					CSC 525/625
 MODIFIED BY:				Zackh Tucker <tucker117> // Josiah McGurty <mcgurty1337>
 ELECTRONIC FILE LOCATIONS:	\\trace\Class\CSC-525-625\001\tucker117\projects\project2\
							\\trace\Class\CSC-525-625\001\McGurty1337\projects\project2\
 CONTRIBUTION BREAKDOWN:	
 LAST MODIFIED DATE:		11.5.2018
 DESCRIPTION:				Lab project 2, using GLUT to create a 
 NOTE:						
 FILES:						project2.cpp, (labProject.sln, ...)
 IDE/COMPILER:				MicroSoft Visual Studio 2017
 INSTRUCTION FOR COMPILATION AND EXECUTION:
	0.		Copy file 'Mandelbrot.ppm' to C:\TEMP\Mandelbrot.ppm.
	1.		Double click on projProject.sln	to OPEN the project
	2.		a. In Solution Explorer, right-click 'projProject' and select Properties.
			b. Select Preprocessor, Edit Preprocessor Definitions to include '_CRT_SECURE_NO_WARNINGS'.
			c. Click OK, click OK.
	2.		Press Ctrl+F7					to COMPILE
	3.		Press Ctrl+F5					to EXECUTE
==================================================================================================*/

#include <iostream>
#include <gl/glut.h>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

//****************************************************************************

vector <string> s = { "" };
int lineNumber = 0;
int lineHeight = 30;

GLfloat colorChosen[3] = {0, 0, 0};

int font;

void drawHelpMessage() {
	string s1 = "Welcome to the best text editor ever!";
	string s2 = "You may select from three fonts, three colors and even save your work!";
	string s3 = "--------------------";
	string s4 = "You may hide this window at any time by left-clicking in it.";
	string s5 = "Use the right-click menu in the Editor window to:";
	string s6 = "-Display this help window";
	string s7 = "-Set text options (color, font)";
	string s8 = "-Save your work to a text file (C:\\TEMP\\typed.txt)";
	string s9 = "\t-Exit the program";

	glColor3f(1.0, 1.0, 1.0);

	glRasterPos2f(0, 280);
	for (int i = 0; i < s1.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, int(s1[i]));
	}
	glRasterPos2f(0, 250);
	for (int i = 0; i < s2.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, int(s2[i]));
	}
	glRasterPos2f(0, 220);
	for (int i = 0; i < s3.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, int(s3[i]));
	}
	glRasterPos2f(0, 190);
	for (int i = 0; i < s4.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, int(s4[i]));
	}
	glRasterPos2f(0, 160);
	for (int i = 0; i < s5.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, int(s5[i]));
	}
	glRasterPos2f(50, 130);
	for (int i = 0; i < s6.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, int(s6[i]));
	}
	glRasterPos2f(50, 100);
	for (int i = 0; i < s7.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, int(s7[i]));
	}
	glRasterPos2f(50, 70);
	for (int i = 0; i < s8.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, int(s8[i]));
	}
	glRasterPos2f(50, 40);
	for (int i = 0; i < s9.length(); ++i) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, int(s9[i]));
	}
	glEnd();
}

void typethings() {
	glPointSize(1);		// change point size back to 1

	glColor3f(1, 1, 1);
	if ((s[lineNumber].length() % 50 == 0 && s[lineNumber].length() != 0) || lineNumber == 0) {
		//if statement characters in line does not = 0; each line is 50 characters, or line number is 0;
		lineNumber++;
		s.push_back("");
	}

	for (int h = 0; h <= lineNumber; h++) {
		glRasterPos2i(0, 1000 - (lineHeight * h));
		for (int i = 0; i < s[h].length(); i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[h][i]);
		}
	}
}

//***********************************************************************************
void myDisplayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	typethings();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************
void myDisplayCallback1()
{
	glClear(GL_COLOR_BUFFER_BIT);	// draw the background

	drawHelpMessage();

	glFlush(); // flush out the buffer contents
}

//***********************************************************************************
void myInit()
{
	glClearColor(0.3, 0.3, 0.3, 0);			// specify a background color: white 
	gluOrtho2D(0, 500, 0, 1000);  // specify a viewing area
}

//***********************************************************************************
void myInfoInit()
{
	glClearColor(0.3, 0.3, 0.3, 0);			// specify a background color: white 
	gluOrtho2D(0, 710, 0, 300);  // specify a viewing area
}

//***********************************************************************************
void myMouseCallback1(int button, int state, int mouseX, int mouseY) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		glutHideWindow();
	}
}

//***********************************************************************************
void FirstMenu(int x)
{
	if (x == 4) {
		exit(0);
	}

	if (x == 1) {
		glutSetWindow(2);
		glutShowWindow();
	}
}

//***********************************************************************************
void runFontMenu(int x) {
	myDisplayCallback();
	if (x == 1) {
		font = 1;
	}
	if (x == 2) {
		font = 2;
	}
	if (x == 3) {
		font = 3;
	}
}

//***********************************************************************************
void runColorMenu(int x) {
	myDisplayCallback();
	if (x == 1) {
		colorChosen[0] = 1.0;
		colorChosen[1] = 0.0;
		colorChosen[2] = 0.0;
	}
	if (x == 2) {
		colorChosen[0] = 0.0;
		colorChosen[1] = 1.0;
		colorChosen[2] = 0.0;
	}
	if (x == 3) {
		colorChosen[0] = 1.0;
		colorChosen[1] = 1.0;
		colorChosen[2] = 1.0;
	}
}

//***********************************************************************************
void myTypingFunc(unsigned char key, int x, int y) {
	if (key == 13) {
		lineNumber++;
		s.push_back("");
	}
	else if (key == 8) {
		if (s[lineNumber].length() == 0 && lineNumber != 1) {
			lineNumber--;
			s.pop_back();
		}
		else if (s[lineNumber].length() == 0 && lineNumber == 1) {
			cout << "System Sound\n";
		}
		else {
			s[lineNumber].pop_back();
			//if none of the other conditions are met, 
			//then pop the last char and continue. 
		}
	}
	else {
		s[lineNumber] += key;
	}

	glutPostRedisplay();
}

//***********************************************************************************
int main(int argc, char ** argv) {
	glutInitWindowSize(500, 1000);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("Editor Window");

	myInit();
	glutKeyboardFunc(myTypingFunc);
	glutDisplayFunc(myDisplayCallback);

	int fontMenu = glutCreateMenu(runFontMenu);
	glutAddMenuEntry("Times New Roman 24", 1);
	glutAddMenuEntry("Helvetica 12", 2);

	int colorMenu = glutCreateMenu(runColorMenu);
	glutAddMenuEntry("Red", 1);
	glutAddMenuEntry("Green", 2);
	glutAddMenuEntry("White", 3);

	int mainMenu = glutCreateMenu(FirstMenu);
	glutAddMenuEntry("Help", 1);
	glutAddSubMenu("Font Selection", fontMenu);
	glutAddSubMenu("Color Selection", colorMenu);
	glutAddMenuEntry("Exit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutInitWindowSize(710, 300);
	glutInitWindowPosition(650, 0);
	glutCreateWindow("Info Window");
	glutDisplayFunc(myDisplayCallback1);
	glutMouseFunc(myMouseCallback1);
	myInfoInit();

	glutMainLoop();							// get into an infinite loop

	return 0;
}