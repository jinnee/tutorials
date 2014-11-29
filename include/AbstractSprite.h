#ifndef ABSTRACTSPRITE_H
#define ABSTRACTSPRITE_H

#include "ImageInstruments.h"
/*
Абстрактен клас установяващ:
    име, тип, група, позиция, рендване и скриване, както и
    абстрактни функции за събитията
*/
class AbstractSprite : public ImageInstruments
{
    public:
        AbstractSprite();
        virtual ~AbstractSprite();
        //име на спрайта
        void setName(string name){this->name = name;}
        string getName(){return this->name;}
        //тип на спрайта
        void setType(string type){this->type = type;}
        string getType(){return this->type;}
        //група на спрайта
        void setGroup(string group){this->group = group;}
        string getGroup(){return this->group;}
        //установява позиция по X
        void setX( Sint16 cx ){oldPosition = position; position.x = cx; }
        Sint16 getX(){ return position.x; }
        //установява позиция по Y
        void setY( Sint16 cy ){oldPosition = position; position.y = cy; }
        Sint16 getY(){ return position.y; }
        //установява позиция
        void setPosition (Sint16 xp, Sint16 yp){oldPosition = position; position.x = xp;position.y = yp;}
        SDL_Rect getOldPosition(){return oldPosition;}
        SDL_Rect getPosition (){return position;}
        //преместване по X
        void moveX(int);
        //преместване по Y
        void moveY(int);
        //посока на движение по остта X
        int getXDirection(){return position.x - oldPosition.x;}
        //посока на движение по остта Y
        int getYDirection(){return position.y - oldPosition.y;}

        //рендване
        void render(SDL_Surface* screen, SDL_Surface* screen1, int x, int y, int x2, int y2, int w, int h);
        void render(SDL_Surface* screen);
        //скриване
        void setHide(SDL_Surface* screen, bool hide);
        void setHide(bool hide);
        bool isHide();
        void setScreen(SDL_Surface*);
        void setAsActiveSprite();
        string getActiveSprite();

        virtual void setMousePosX(int)=0;
        virtual void setMouseButtonDown(bool)=0;
        virtual void setMousePosY(int)=0;
        virtual void setMousePosXY(int,int)=0;
        virtual bool isMouseButtonDown()=0;
        virtual void setKeyReleased(bool)=0;
        virtual bool isKeyReleased()=0;
        virtual void setTypeKeyReleased(string)=0;
    protected:
        string name;
        string type;
        string group;
        SDL_Rect oldPosition;
        SDL_Rect position;
        string activeName;
        bool hide;
    private:
};

#endif // AbstractSprite_H
