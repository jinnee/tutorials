#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "ImageInstruments.h"

#include "AbstractSprite.h"

class SpriteManager
{
    public:
        SpriteManager();
        virtual ~SpriteManager();

        static string getEventFrom();
        static void setEventFrom(string &mouseEventFrom);
        static void addSprite(AbstractSprite* ss);
        static void deleteSprite(string name);
        static AbstractSprite* getSprite(string &name);
        static string mouseEventFrom;
        static vector<AbstractSprite*> vectorOfSprites;
    private:
};

#endif // SPRITEMANAGER_H
