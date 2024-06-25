#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>
#include <raymath.h>
#include "BCgui.h"
#include <iostream>
#include <string>

using namespace std;

string NumericChar(int CODE)
{
    
    string VALUE = "";

    if (CODE >= 48 && CODE <= 57) VALUE = to_string(CODE - 48);
    if (CODE >= 320 && CODE <= 329) VALUE = to_string(CODE - 320);
    if (CODE == 44 || CODE == 330) VALUE = ",";
    return VALUE;
}

void main()
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 400, "Ballistics Calculator");
    Font DefaultGuiText = LoadFontEx("C:/Users/muril/Desktop/RobotoCondensed.ttf", 24, 0, 0);
    GuiSetFont(DefaultGuiText);
    SetTargetFPS(60); 
    

    //GUI ELEMENTS
    int SIMULATION_MODE = 0;
    bool SIMULATION_MODE_STATS = false;

    Color GRAVITY_RECT_COLOR = WHITE;
    Rectangle GRAVITY_RECT = { 70,20,180,22 };
    string GRAVITY_GUI_VALUE = "9,8";
    bool GRAVITY_GUI_STATS = false;
    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        ClearBackground(BLACK);
        //GUI
        DrawTextEx(DefaultGuiText, "g(m/s2):", Vector2{ 0,20 }, 24, 0, WHITE);
        BCGntextbox();
 
        DrawRectangleLinesEx(GRAVITY_RECT, 2, GRAVITY_RECT_COLOR);
        DrawTextEx(DefaultGuiText, GRAVITY_GUI_VALUE.c_str(), Vector2{70,20}, 24, 0, WHITE);
        
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionCircleRec(GetMousePosition(), 2, GRAVITY_RECT))
        {
            GRAVITY_RECT_COLOR = BLUE;
            GRAVITY_GUI_STATS = true;
        }
        else

        if (GuiDropdownBox(Rectangle{ 0,0,250,20 }, "DISTANCE (Angle, Vo);HIT POINT (H, dS, Vo);HIT POINT (H, dS, Angle)", &SIMULATION_MODE, SIMULATION_MODE_STATS)) SIMULATION_MODE_STATS = !SIMULATION_MODE_STATS;
        
        
        int k = GetKeyPressed();
        if (k)
        {
 
            cout << NumericChar(k) << endl;
        }
        

        for (int i = 0; i < 50; i++)
        {
            DrawCircle(400 - i, 200 - i, 3, RED);
        }


        EndDrawing();
       
    }

    CloseWindow();
}