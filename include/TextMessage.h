#ifndef TEXTMESSAGE_H
#define TEXTMESSAGE_H

#include "BmpFont.h"
#include "LineText.h"
#include "StaticSprite.h"

class TextMessage : public StaticSprite
{
    public:
        TextMessage();
        void init();
        void setWidth(int);
        void setHeight(int);
        void render(SDL_Surface* screen);
        void setShowTextMessage(bool);
        bool getShowTextMessage();
        void setBmpFont(BmpFont* bmpFont);
        void setTitle(wstring);
        void setContent(wstring);
        virtual ~TextMessage();
    private:
        SDL_Surface* txtSurface;
        Uint32 rmask, gmask, bmask, amask;
        int widthNewSurface;
        int heightNewSurface;
        int xPosTextMessage;
        int yPosTextMessage;
        bool showTextMessage;
        BmpFont* bmpFont;
        LineText* textTitle;
        LineText* textContent;
};

#endif // TEXTMESSAGE_H
