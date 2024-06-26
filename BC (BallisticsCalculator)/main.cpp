#define RAYGUI_IMPLEMENTATION

#include <raylib.h>
#include <raygui.h>
#include <raymath.h>
#include "BCgui.h"
#include <iostream>
#include <string>
#include "PhysicOP.h"

string DEFAULT_FONT_PATH = "resources/fonts/RobotoCondensed.ttf";
using namespace std;



void main()
{

    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(800, 400, "Ballistics Calculator");
    Font DEFAULT_FONT = LoadFontEx(DEFAULT_FONT_PATH.c_str(), 24, 0, 0);
    GuiSetFont(DEFAULT_FONT);
    SetTargetFPS(60); 
    

    //GUI ELEMENTS
    int SIMULATION_MODE = 0;
    bool SIMULATION_MODE_STATS = false;


    string GRAVITY_GUI_VALUE = "9.8";
    bool GRAVITY_GUI_STATS = false;

    //PHYSIC INPUT
    string ANGLE_VALUE = "45.0";
    bool ANGLE_GUI_STATS = false;

    string V0_VALUE = "10.0";
    bool V0_GUI_STATS = false;

    string dS_VALUE = "0.0";
    bool dS_GUI_STATS = false;

    string impact_timer = "0.0";

    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        ClearBackground(BLACK);
        //GUI
        
        if (BCGntextbox(DEFAULT_FONT, 24, "g(m/s2): ", &GRAVITY_GUI_VALUE, 8, false, Rectangle{ 0,20,250,0 }, GRAVITY_GUI_STATS, true)) GRAVITY_GUI_STATS = !GRAVITY_GUI_STATS;
        
        switch (SIMULATION_MODE)
        {
        case 0:
            if (BCGntextbox(DEFAULT_FONT, 24, "Angle(DEG): ", &ANGLE_VALUE, 8, false, Rectangle{ 0,45,250,0 }, ANGLE_GUI_STATS, true)) ANGLE_GUI_STATS = !ANGLE_GUI_STATS;
            if (BCGntextbox(DEFAULT_FONT, 24, "Vo(m/s): ", &V0_VALUE, 8, false, Rectangle{ 0,70,250,0 }, V0_GUI_STATS, true)) V0_GUI_STATS = !V0_GUI_STATS;
            BCGntextbox(DEFAULT_FONT, 24, "delta S(m): ", &dS_VALUE, 8, false, Rectangle{ 0,95,250,0 }, false, false);
            if (BCGbutton(DEFAULT_FONT, 24, "FIRE", Rectangle{ 0,145,250,25 }, 1))
            {
                dS_VALUE = to_string(distance1(NumText2Float(ANGLE_VALUE), NumText2Float(V0_VALUE), NumText2Float(GRAVITY_GUI_VALUE)));
                impact_timer = to_string(Cimpact_timer(NumText2Float(ANGLE_VALUE), NumText2Float(V0_VALUE), NumText2Float(GRAVITY_GUI_VALUE)));
            }


            break;
        case 1:
            (BCGntextbox(DEFAULT_FONT, 24, "Angle(DEG): ", &ANGLE_VALUE, 8, false, Rectangle{ 0,45,250,0 }, false, false));
            if (BCGntextbox(DEFAULT_FONT, 24, "Vo(m/s): ", &V0_VALUE, 8, false, Rectangle{ 0,70,250,0 }, V0_GUI_STATS, true)) V0_GUI_STATS = !V0_GUI_STATS;
            if (BCGntextbox(DEFAULT_FONT, 24, "delta S(m): ", &dS_VALUE, 8, false, Rectangle{ 0,95,250,0 }, dS_GUI_STATS, true)) dS_GUI_STATS = !dS_GUI_STATS;
            if (BCGbutton(DEFAULT_FONT, 24, "FIRE", Rectangle{ 0,145,250,25 }, 1))
            {
                ANGLE_VALUE = to_string(hitpoint1(NumText2Float(dS_VALUE), NumText2Float(V0_VALUE), NumText2Float(GRAVITY_GUI_VALUE)));
                if (ANGLE_VALUE == "-nan(ind)")
                {
                    ANGLE_VALUE = "OUT OF RANGE!";
                }
                impact_timer = to_string(Cimpact_timer(NumText2Float(ANGLE_VALUE), NumText2Float(V0_VALUE), NumText2Float(GRAVITY_GUI_VALUE)));
            }
            break;
        case 2:
            if (BCGntextbox(DEFAULT_FONT, 24, "Angle(DEG): ", &ANGLE_VALUE, 8, false, Rectangle{ 0,45,250,0 }, ANGLE_GUI_STATS, true)) ANGLE_GUI_STATS = !ANGLE_GUI_STATS;
            BCGntextbox(DEFAULT_FONT, 24, "Vo(m/s): ", &V0_VALUE, 8, false, Rectangle{ 0,70,250,0 }, false, false);
     
            if (BCGntextbox(DEFAULT_FONT, 24, "delta S(m): ", &dS_VALUE, 8, false, Rectangle{ 0,95,250,0 }, dS_GUI_STATS, true)) dS_GUI_STATS = !dS_GUI_STATS;
            break;
        default:
            break;
        }
        Vector2 START_POINT = { 270, GetScreenHeight() - 50 };
        for (float i = 0; i <= 1;)
        {
            Vector2 POINT_COORDS = functime(NumText2Float(ANGLE_VALUE), NumText2Float(V0_VALUE), NumText2Float(GRAVITY_GUI_VALUE), i);
            DrawCircleV(Vector2{ POINT_COORDS.x*15 + START_POINT.x,-POINT_COORDS .y*15 + START_POINT .y}, 1, WHITE);
            i += 0.0001;
        }
        BCGntextbox(DEFAULT_FONT, 24, "t(s) = ", &impact_timer, 8, false, Rectangle{ 0,120,250,0 }, true, false);
        if (GuiDropdownBox(Rectangle{ 0,0,250,20 }, "DISTANCE (Angle, Vo);HIT POINT (dS, Vo);HIT POINT (dS, Angle)", &SIMULATION_MODE, SIMULATION_MODE_STATS)) SIMULATION_MODE_STATS = !SIMULATION_MODE_STATS;
        
        
        float dH_offset = 0;
       
        

        DrawCircle(START_POINT.x, START_POINT.y, 5, RED);

        EndDrawing();
       
    }

    CloseWindow();
}