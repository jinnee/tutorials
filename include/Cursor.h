#ifndef CURSOR_H
#define CURSOR_H

#include "AnimatedSprite.h"

class Cursor : public AnimatedSprite
{
    public:
        Cursor(string& pathCursor);
        virtual ~Cursor();
        void render(SDL_Surface* screen);
        void changeCursor(string& pathCursor);
    private:
        string pathCursor;
};

#endif // CURSOR_H
