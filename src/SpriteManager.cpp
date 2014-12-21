#include "../include/SpriteManager.h"

SpriteManager::SpriteManager()
{

}

void SpriteManager::addSprite(AbstractSprite* ss){
    vectorOfSprites.push_back(ss);
}

void SpriteManager::deleteSprite(string name){
    std::vector<AbstractSprite*>::iterator it = vectorOfSprites.begin();
    int v_size = vectorOfSprites.size();
    for (unsigned int i = 0; i < v_size; i++) {
        if ( vectorOfSprites[i]->getName() == name ) {
            it = vectorOfSprites.begin()+i;
            vectorOfSprites.erase(it);
//            cout << "delete:" << (*it)->getName() << endl;
//            delete *it;
//            *it = 0;
            break;
        }
    }
}

void SpriteManager::deleteSpritesByGroup(string name){
    cout << "delete group" << endl;
    std::vector<AbstractSprite*>::iterator it = vectorOfSprites.begin();
    int v_size = vectorOfSprites.size();
    for (unsigned int i = 0; i < v_size; i++) {
        if ( vectorOfSprites[i]->getGroup() == name ) {
            it = vectorOfSprites.begin()+i;
            vectorOfSprites.erase(it);
            cout << "delete group" << endl;
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
