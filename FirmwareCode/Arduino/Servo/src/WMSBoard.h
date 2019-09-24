#ifndef WMBoard_H
#define WMBoard_H

#define NC (0)


typedef struct
{
	uint8_t pin1;
	uint8_t pin2;
}WMPin;

/*********************  WMBoard GPIO Map *********************************/

WMPin wmPortS[9] = 
{
	{NC,NC},{1,0},{3,11},
	{9,10},{12,A6},{A0,A1},
	{A2,A3},{7,5},{8,6}
};

#endif

