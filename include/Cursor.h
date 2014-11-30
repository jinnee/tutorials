#ifndef CURSOR_H
#define CURSOR_H

#include "AnimatedSprite.h"

class Cursor : public AnimatedSprite
{
    public:
        static Cursor* getCursor();
        static void setPath(string& pathCursor);
        virtual ~Cursor();
        void render(SDL_Surface* screen);
        void changeCursor(string& pathCursor);
    private:
        Cursor();
        static Cursor* cursor;
        static string pathCursor;
};

#endif // CURSOR_H
