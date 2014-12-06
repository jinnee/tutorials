
#include "../include/Button.h"

Button::Button(): StaticSprite() {
    name = "BUTTON";
    type = Constants::SpriteTypes::UI_BUTTON;
    setX(0);
    setY(0);
}

Button::~Button() {
}

//смяна на картинката, когато курсора е върху бутона (или го напуска)
void Button::render(SDL_Surface* screen) {
    if ( this->isCursorInSprite() ) {
        SpriteManager::mouseEventFrom = this->getName();
        StaticSprite::render(screen, image,this->getX(),this->getY(),0,image->h/2,image->w, image->h/2);
    } else if (this->isCursorInSprite() && this->isMouseButtonDown()) {
        SpriteManager::mouseEventFrom = this->getName();
    } else {
        StaticSprite::render(screen, image,this->getX(),this->getY(),0,0,image->w, image->h/2);
    }
}

