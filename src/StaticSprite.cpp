#include "../include/StaticSprite.h"

StaticSprite::StaticSprite() : AbstractSprite()
{
    x_mouse = 0;
    y_mouse = 0;
    tilesX = 1;
    tilesY = 1;
    name = "StaticSprite";
    type = Constants::SpriteTypes::STATIC_SPRITE;
    isDown = false;
    isKeyRel = false;
    cursorInSprite = false;
    typeKey = "";
}

StaticSprite::~StaticSprite() {
    SpriteManager::deleteSprite(this->name);
}

void StaticSprite::setMouseButtonDown(bool isDown) {
    this->isDown = isDown;
    this->cursorInSprite = true;
}

//ако е натистан бутона на мишката върху спрайта
bool StaticSprite::isMouseButtonDown() {
    // add event manager
    if (this->cursorInSprite) {
        return this->isDown;
    }
    return false;
}

//позиция на мишката върху спрайта
void StaticSprite::setMousePosX(int x) {
    if ( this->image->w/this->tilesX + this->position.x > x && x >  this->position.x) {
        this->x_mouse = x;
    }
}

Sint16 StaticSprite::getMousePosX() {
    if ( this->image->w/this->tilesX + this->position.x > x_mouse && x_mouse >  this->position.x ) {
        return this->x_mouse;
    }
    return -1;
}

//позиция на мишката върху спрайта
void StaticSprite::setMousePosY(int y) {
    if ( this->image->h/this->tilesY + this->position.y > y && y >  this->position.y) {
        this->y_mouse = y;
    }
}

Sint16 StaticSprite::getMousePosY() {
    if ( this->image->h/this->tilesY + this->position.y > y_mouse && y_mouse >  this->position.y) {
        return this->y_mouse;
    }
    return -1;
}

void StaticSprite::setMousePosXY(int x, int y) {
    if (  this->image->w/this->tilesX + this->position.x > x && x >  this->position.x &&
         this->image->h/this->tilesY + this->position.y > y && y >  this->position.y) {
        x_mouse = x;
        y_mouse = y;
        this->cursorInSprite = true;
    } else {
        this->cursorInSprite = false;
    }
}

bool StaticSprite::isCursorInSprite() {
    return this->cursorInSprite;
}

void StaticSprite::setTilesXY(int tilesX, int tilesY) {
    this->tilesX = tilesX;
    this->tilesY = tilesY;
}

int StaticSprite::getTileX() {
    return this->tilesX;
}

int StaticSprite::getTileY() {
    return this->tilesY;
}

bool StaticSprite::isKeyReleased(){
    return this->isKeyRel;
}

void StaticSprite::setKeyReleased(bool isKeyReleased){
    this->isKeyRel = isKeyReleased;
}
void StaticSprite::setTypeKeyReleased(string type){
    typeKey = type;
}

string StaticSprite::getTypeKeyReleased(){
    return this->typeKey;
}

SDL_Rect StaticSprite::GetBounds() {
	SDL_Rect bounds;
	bounds.x = (Sint16)(position.x - oldPosition.x);
	bounds.y = (Sint16)(position.x - oldPosition.x);
	bounds.w = (Sint16)(tileWidth);
	bounds.h = (Sint16)(tileHeight);

	return bounds;
}
