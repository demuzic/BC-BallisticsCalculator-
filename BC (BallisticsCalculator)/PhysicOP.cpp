#include <math.h>
#include <raylib.h>



float deg2rad(float DEG) { return (DEG * PI) / 180; }
float rad2deg(float RAD) { return (RAD * 180) / PI; }

float distance1(double ANGLE, double V0, double g)
{

	double Vx = cos(deg2rad(ANGLE)) * V0;
	double Vy = sin(deg2rad(ANGLE)) * V0;

	double delta = sqrt(pow(Vy, 2));
	double t = (Vy + delta)/g;
	double dS = Vx * t;

	return dS;
}

float hitpoint1(double dS, double V0, double g)
{
	float dANGLE = rad2deg(asin((dS * g) / pow(V0, 2)));
	
	return 90 - dANGLE/2;
}

float Cimpact_timer(double ANGLE, double V0, double g)
{
	double Vx = cos(deg2rad(ANGLE)) * V0;
	double Vy = sin(deg2rad(ANGLE)) * V0;

	double delta = sqrt(pow(Vy, 2));
	double t = (Vy + delta) / g;
	return t;
}


Vector2 functime(double ANGLE, double V0, double g, float TIME)
{
	
	double Vx = cos(deg2rad(ANGLE)) * V0;
	double Vy = sin(deg2rad(ANGLE)) * V0;
	
	double delta = sqrt(pow(Vy, 2));
	double t = (Vy + delta) / g;
	float rTIME = t * TIME;
	float X = Vx * rTIME;
	float Y = Vy * rTIME - (g * pow(rTIME,2))/2;
	return Vector2{ X,Y };
}