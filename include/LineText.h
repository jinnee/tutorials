#ifndef LINETEXT_H_INCLUDED
#define LINETEXT_H_INCLUDED

#include "BmpFont.h"
#include "StaticSprite.h"

class LineText : public StaticSprite
{
    public:
        LineText();
        virtual ~LineText();
        void render(SDL_Surface* screen);
        void setFont(BmpFont*);
        void setText(wstring);
        int getHeight();
        int getWidth();
    protected:
        wstring text;
    private:
        BmpFont* bmpFont;
        int width;
        int height;
        int numberOfLetters;
};

#endif // LINETEXT_H_INCLUDED
