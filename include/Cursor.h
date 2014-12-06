#ifndef CURSOR_H
#define CURSOR_H

#include "AnimatedSprite.h"

class Cursor : public AnimatedSprite
{
    public:
        static Cursor* getCursor();
        // първоначално сетване на пътя до курсора
        static void setPath(string& pathCursor);
        virtual ~Cursor();
        void render(SDL_Surface* screen);
        // смяна на курсора
        void changeCursor(string& pathCursor);
    private:
        Cursor();
        static Cursor* cursor;
        // път до картинката с курсора
        static string pathCursor;
};

#endif // CURSOR_H
