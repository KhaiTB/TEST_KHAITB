/*************************************************
*                                                *
*  EasyBMP Cross-Platform Windows Bitmap Library *
*                                                *
*  Author: Paul Macklin                          *
*   email: macklin01@users.sourceforge.net       *
* support: http://easybmp.sourceforge.net        *
*                                                *
*          file: EasyBMPsample.cpp               *
*    date added: 03-31-2006                      *
* date modified: 12-01-2006                      *
*       version: 1.06                            *
*                                                *
*   License: BSD (revised/modified)              *
* Copyright: 2005-6 by the EasyBMP Project       *
*                                                *
* description: Sample application to demonstrate *
*              some functions and capabilities   *
*                                                *
*************************************************/

#include "EasyBMP.h"
#include <windows.h>
#include <iostream>

#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib, "User32.lib")

using namespace std;

void DrwImage(std::string imagePath, HDC* console);
int main()
{
    //Get current console handle
    HWND console = GetConsoleWindow();
    //Get a handle to console
    HDC dc = GetDC(console);
    // Call DrwImage. It must be a bitmap image

    while (true)
    {
        DrwImage("5b27291ba6e054be0df1.bmp", &dc);
        Sleep(5000);
    }

    return 0;
}
void DrwImage(std::string imagePath, HDC* console) {

    BMP image;
    image.ReadFromFile(imagePath.c_str());
    //image.SetBitDepth(32);
    for (int x = 0; x < image.TellWidth(); x++)
    {
        for (int y = 0; y < image.TellHeight(); y++)
        {
            int RED = image.GetPixel(x, y).Red;
            int GREEN = image.GetPixel(x, y).Green;
            int BLUE = image.GetPixel(x, y).Blue;

            int ALPHA = image.GetPixel(x, y).Alpha;

            COLORREF COLOUR = RGB(RED, GREEN, BLUE);
            if (ALPHA == 0) {
                SetPixel(*console, x, y, COLOUR);
            }
        }
    }
}
