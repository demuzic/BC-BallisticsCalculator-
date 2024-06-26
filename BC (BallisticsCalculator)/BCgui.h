#ifndef BCGUI_H_INCLUDED
#define BCGUI_H_INCLUDED
#include <raylib.h>
#include <iostream>
using namespace std;
bool BCGntextbox(Font FONT, int FONTSIZE, string TEXT, string *INPUT, int INPUT_MAX, bool ALLOW_NEGATIVE, Rectangle RECT, bool FOCUS, bool EDITABLE);
bool BCGbutton(Font FONT, int FONTSIZE, string TEXT, Rectangle RECT, int MODE); // MODES: 0 - PRESSING, 1 - PRESSED, 2 - RELEASE
float NumText2Float(string TEXT);
string NumericChar(int CODE);


#endif