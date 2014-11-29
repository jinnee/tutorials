#include "../include/SpriteManager.h"

SpriteManager::SpriteManager()
{

}

void SpriteManager::addSprite(AbstractSprite* ss){
    vectorOfSprites.push_back(ss);
}

void SpriteManager::deleteSprite(string name){
    std::vector<AbstractSprite*>::iterator it = vectorOfSprites.begin();
    for (unsigned int i = 0; i < vectorOfSprites.size(); i++) {
        if ( vectorOfSprites[i]->getName() == name ) {
            it = vectorOfSprites.begin()+i;
            vectorOfSprites.erase(it);
            break;
        }
    }
}

AbstractSprite* SpriteManager::getSprite(string &name){
    std::vector<AbstractSprite*>::iterator it = vectorOfSprites.begin();
    for (unsigned int i = 0; i < vectorOfSprites.size(); i++) {
        if ( vectorOfSprites[i]->getName() == name ) {
            it = vectorOfSprites.begin()+i;
            return vectorOfSprites[i];
        }
    }
    return 0;
}

SpriteManager::~SpriteManager()
{
    //dtor
}

string SpriteManager::getEventFrom(){
    return SpriteManager::mouseEventFrom;
}

void SpriteManager::setEventFrom(string &mouseEventFrom){
    SpriteManager::mouseEventFrom = mouseEventFrom;
}

vector<AbstractSprite*> SpriteManager::vectorOfSprites ;
string SpriteManager::mouseEventFrom = "";
