#ifndef OUTPUT_H
#define OUTPUT_H

#define SCREEN_WIDTH 30
#define SCREEN_HEIGHT 25

//time between each frame
#define DELTA_TIME 0.0417

//handy defines for colors
#define FOREGROUND_WHITE FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define BACKGROUND_WHITE BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY
#define FOREGROUND_PURPLE FOREGROUND_BLUE | FOREGROUND_RED
#define BACKGROUND_PURPLE BACKGROUND_BLUE | BACKGROUND_RED
#define FOREGROUND_LIGHT_BLUE FOREGROUND_BLUE | FOREGROUND_GREEN
#define BACKGROUND_LIGHT_BLUE BACKGROUND_BLUE | BACKGROUND_GREEN
#define FOREGROUND_POOP FOREGROUND_GREEN | FOREGROUND_RED
#define BACKGROUND_POOP BACKGROUND_GREEN | BACKGROUND_RED
#define FOREGROUND_YELLOW FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY
#define BACKGROUND_YELLOW BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY

#include <windows.h>
#include <chrono>
#include <thread>

class Output
{
    public:
        //print a single character at the given coordinates with the given color
        void PrintChar(const COORD &position, const char &glyph, const WORD &color);
        //print a string of characters given the position and the color
        void PrintString(const COORD &position, const std::string &string, const WORD &color);
        //print a string at y position at the center of the screen
        void PrintString(const int &yPos, const std::string &string, const WORD &color);
        //return the character at a given position
        char GetChar(const COORD &position);
        //print a rectangle of chars given the coordinates of top left and the size of the rect
        void FillChar(const COORD &pos, const COORD &rectSize, const char &glyph, const WORD &color);
        void Start();
        void Update();
        static Output& Get();
    private:
        Output();

        HANDLE m_screenBuffer;
        COORD m_bufferSize;
        SMALL_RECT m_writeRect; //where to write data
        CHAR_INFO m_charBuffer[SCREEN_WIDTH * SCREEN_HEIGHT]; //game display matrix
};

#endif // OUTPUT_H
