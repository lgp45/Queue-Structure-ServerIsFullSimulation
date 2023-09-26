#include <Windows.h>
#include <conio.h>
#include <iostream>

static void setCursorPosition(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
}
static void GotoXY(int x, int y)
{

	//*************************************************************************************
	// Void-Function that receives a coordinate-pair and places the cursor at that
	//  coord-location on the screen
	//*************************************************************************************
	COORD coord;
	coord.X = x;
	coord.Y = y;

	//Use a built-in function that will use the "coord" coordinates and place the cursor
	// at the appropriate location on the screen.
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
static void SetTextColor(int foreground, int background)
{
    int finalColor = (16 * background) + foreground;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), finalColor);
    return;
}
static void PrintToCoordinates(int x, int y, const std::string& text)
{
    printf("\033[%d;%dH%s\n", x, x, text.c_str());
}

