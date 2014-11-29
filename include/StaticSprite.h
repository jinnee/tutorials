#ifndef STATICSPRITE_H
#define STATICSPRITE_H

#include "AbstractSprite.h"
#include "SpriteManager.h"

/*
Клас реализиращ събитията и мрежата на спрайта
 */
class StaticSprite : public AbstractSprite {
public:
    StaticSprite();
    virtual ~StaticSprite();
    void setMouseButtonDown(bool isDown);
    bool isMouseButtonDown();
    void setMousePosX(int x);
    Sint16 getMousePosX();
    void setMousePosY(int y);
    Sint16 getMousePosY();
    void setMousePosXY(int x, int y);
    bool isCursorInSprite();
    bool isKeyReleased();
    void setKeyReleased(bool);
    void setTypeKeyReleased(string);
    string getTypeKeyReleased();

    int getSpriteWidth() {
        return this->image->w / this->tilesX;
    }

    int getSpriteHeight() {
        return this->image->h / this->tilesY;
    }
    void setTilesXY(int tilesX, int tilesY);
    int getTileX();
    int getTileY();
    SDL_Rect GetBounds();
protected:
    //
    int tilesX;
    int tilesY;
    //
    int tileWidth;
    int tileHeight;
    //координати на мишката върху спрайта
    Sint16 x_mouse, y_mouse;
    //true, ако мишката е натисната върху спрайта
    bool isDown;
    //ако показалецът на мишката е върху sprite
    bool cursorInSprite;
    bool isKeyRel;
    string typeKey;
private:
};

#endif // STATICSPRITE_H
