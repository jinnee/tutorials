#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "StaticSprite.h"
#include "SpriteManager.h"

class Background : public StaticSprite
{
    public:
        Background();
        virtual ~Background();
        void render(SDL_Surface* screen);
    protected:
    private:
};

#endif // BACKGROUND_H
