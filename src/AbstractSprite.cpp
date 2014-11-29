/* 
 * File:   AbstractSprite.cpp
 * Author: jinnee
 * 
 * Created on October 28, 2014, 2:32 PM
 */

#include "../include/AbstractSprite.h"

AbstractSprite::AbstractSprite():ImageInstruments()
{
    name = "AbstractSprite";
    type = Constants::SpriteTypes::ABSTRACT_SPRITE;
    hide = false;
    activeName = "AbstractSprite";
}

void AbstractSprite::setAsActiveSprite() {
    activeName = name;
}

AbstractSprite::~AbstractSprite()
{
}

string AbstractSprite::getActiveSprite() {
    return activeName;
}

void AbstractSprite::setHide(SDL_Surface* screen, bool hide){
    this->render(screen, image, position.x, position.y, image->w, image->h, image->w, image->h );
    this->hide = hide;
}

void AbstractSprite::setHide(bool hide){
    this->hide = hide;
}

bool AbstractSprite::isHide() {
    return this->hide;
}

void AbstractSprite::render(SDL_Surface* screen) {
    if (!hide) {
        SDL_BlitSurface(image, 0, screen, &position);
    }
}

void AbstractSprite::moveX(int dx)
{
    oldPosition.x = position.x;
    position.x +=dx;
}

void AbstractSprite::moveY(int dy)
{
    oldPosition.y = position.y;
    position.y +=dy;
}

void AbstractSprite::render(SDL_Surface* sDest, SDL_Surface* sSrc, int x, int y, int x2, int y2, int w, int h) {
    if( sDest == 0 || sSrc == 0 ) {
        return;
    }

    if (!hide){
        SDL_Rect DestR;

        DestR.x = x;
        DestR.y = y;

        SDL_Rect SrcR;

        SrcR.x = x2;
        SrcR.y = y2;
        SrcR.w = w;
        SrcR.h = h;

        SDL_BlitSurface(sSrc, &SrcR, sDest, &DestR);
    }
}

