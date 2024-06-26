#include <raylib.h>
#include <iostream>
#include <string>
using namespace std;

string NumericChar(int CODE)
{

	string VALUE = "";

	if (CODE >= 48 && CODE <= 57) VALUE = to_string(CODE - 48);
	if (CODE >= 320 && CODE <= 329) VALUE = to_string(CODE - 320);
	if (CODE == 46 || CODE == 330) VALUE = ".";
	return VALUE;
}

float NumText2Float(string TEXT)
{
	if (TEXT == "") return 0.0;
	if (TEXT == "-") return 0.0;
	if (TEXT != "" and TEXT != "-") return stof(TEXT);
}

bool BCGntextbox(Font FONT, int FONTSIZE, string TEXT, string *INPUT, int INPUT_MAX, bool ALLOW_NEGATIVE, Rectangle RECT, bool FOCUS , bool EDITABLE)
{
	bool PRESSED = false;
	Vector2 TEXT_SIZE = MeasureTextEx(FONT, TEXT.c_str(), FONTSIZE, 0);
	float Y_RECT = 0;
	if (!RECT.height)
	{
		Y_RECT = TEXT_SIZE.y;
	}
	else
	{
		Y_RECT = RECT.height;
	}
	Rectangle _INPUT_RECT = Rectangle{ RECT.x + TEXT_SIZE.x,RECT.y,RECT.width - TEXT_SIZE.x ,Y_RECT };

	if (EDITABLE)
	{
		if (FOCUS)
		{
			int k = GetKeyPressed();
			if (INPUT->length() == 0 and ALLOW_NEGATIVE and (k == 45 || k == 333)) *INPUT += "-";
			if (INPUT->length() < INPUT_MAX)
			{
				if (NumericChar(k) != ".") *INPUT += NumericChar(k);
				else
				{
					if (INPUT->rfind(".") > INPUT_MAX) *INPUT += NumericChar(k);
				}
			}
			if (k == 259 and INPUT->length() > 0) *INPUT = INPUT->substr(0, INPUT->length() - 1);


			if (!CheckCollisionPointRec(GetMousePosition(), _INPUT_RECT) && IsMouseButtonDown(MOUSE_BUTTON_LEFT))
			{
				DrawRectangleLinesEx(_INPUT_RECT, 2, RAYWHITE);
				PRESSED = true;

			}
			DrawRectangleLinesEx(_INPUT_RECT, 2, BLUE);
		}
		else
		{

			if (INPUT->rfind(".") == INPUT->length() - 1)*INPUT = INPUT->substr(0, INPUT->length() - 1);


			if (CheckCollisionPointRec(GetMousePosition(), _INPUT_RECT))
			{
				DrawRectangleLinesEx(_INPUT_RECT, 2, YELLOW);
				if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
				{

					PRESSED = true;
				}
			}
			else
			{
				DrawRectangleLinesEx(_INPUT_RECT, 2, RAYWHITE);
			}
		}
	}
	else DrawRectangleLinesEx(_INPUT_RECT, 2, GRAY);
	

	
	
	DrawTextEx(FONT, INPUT->c_str(), Vector2{RECT.x + TEXT_SIZE.x + 2,RECT.y}, FONTSIZE, 0, WHITE);
	DrawTextEx(FONT, TEXT.c_str(), Vector2{ RECT.x,RECT.y }, FONTSIZE, 0, WHITE);

	return PRESSED;
}

bool BCGbutton(Font FONT, int FONTSIZE, string TEXT, Rectangle RECT, int MODE)
{
	Vector2 TEXT_SIZE = MeasureTextEx(FONT, TEXT.c_str(), FONTSIZE, 0);
	bool PRESSED = false;
	DrawTextEx(FONT, TEXT.c_str(), Vector2{ RECT.x + RECT.width/2 - (TEXT_SIZE.x/2),RECT.y + RECT.height / 2 - (TEXT_SIZE.y / 2) }, FONTSIZE, 0, WHITE);
	DrawRectangleLinesEx(RECT, 2, WHITE);
	if (CheckCollisionPointRec(GetMousePosition(), RECT))
	{
		DrawRectangleLinesEx(RECT, 2, YELLOW);

		if (MODE == 0) {
			if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
			{
				DrawRectangleLinesEx(RECT, 2, BLUE);
				PRESSED = true;

			}
		}
		if (MODE == 1) {
			if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
			{
				DrawRectangleLinesEx(RECT, 2, BLUE);
				PRESSED = true;
				

			}
		}
		if (MODE == 2) {
			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
			{
				DrawRectangleLinesEx(RECT, 2, BLUE);
				PRESSED = true;
				
			}
		}
		
	}
	else DrawRectangleLinesEx(RECT, 2, WHITE);
	return PRESSED;

}

