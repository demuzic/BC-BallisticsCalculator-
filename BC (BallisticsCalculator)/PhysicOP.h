#ifndef PHYSICOP_H_INCLUDED
#define PHYSICO_H_INCLUDED
float deg2rad(float DEG);
float distance1(double ANGLE, double V0, double g); //return dS
float hitpoint1(double dS, double V0, double g);
float Cimpact_timer(double ANGLE, double V0, double g);
Vector2 functime(double ANGLE, double V0, double g, float TIME); // TIME = [0,1]

#endif