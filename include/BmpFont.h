#ifndef BMPFONT_H_INCLUDED
#define BMPFONT_H_INCLUDED

#include "ImageInstruments.h"

class BmpFont : public ImageInstruments
{
    public:
        BmpFont();
        void initFont(int,int);
        virtual ~BmpFont();
        int getFontLength();
        map<int, int> getFontMap();
        int getWidth();
        int getHeight();
        void setStringFont(wstring);
    private:
        int width;
        int height;
        int fontLength;
        map<int, int> fontMap;
        wstring stringFont;
        int tilesX;
        int tilesY;
};

#endif // BMPFONT_H_INCLUDED
