#include "../include/TextMessage.h"

TextMessage::TextMessage():StaticSprite() {
    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        amask = 0x000000ff;
    #else
        rmask = 0x000000ff;
        gmask = 0x0000ff00;
        bmask = 0x00ff0000;
        amask = 0xff000000;
    #endif

    widthNewSurface = 150;
    heightNewSurface = 100;
    showTextMessage = true;
    textTitle = new LineText();
    textTitle->setName("title_text");
    textContent = new LineText();
    textContent->setName("text_content");
}

void TextMessage::init() {
    xPosTextMessage = this->getX();
    yPosTextMessage = this->getY();
    txtSurface = SDL_CreateRGBSurface(0, widthNewSurface, heightNewSurface, 32,
                                   rmask, gmask, bmask, amask);
    if(txtSurface == NULL) {
        fprintf(stderr, "CreateRGBSurface failed: %s\n", SDL_GetError());
        exit(1);
    }
}

TextMessage::~TextMessage(){
    if(txtSurface) {
        SDL_FreeSurface(txtSurface);
    }
    if(textTitle) {
        delete textTitle;
    }
    if(textContent) {
        //delete textContent;
    }
}

void TextMessage::render(SDL_Surface* screen){
    if (showTextMessage) {
        SDL_Rect src = {0, 0, widthNewSurface, heightNewSurface}; // x, y, width, height
        SDL_Rect dest = {xPosTextMessage, yPosTextMessage, xPosTextMessage + widthNewSurface, yPosTextMessage + heightNewSurface};
        SDL_FillRect(txtSurface, &src, SDL_MapRGBA(txtSurface->format, 0x00, 0x00, 0x00,150));
        textTitle->render(txtSurface);
        textContent->render(txtSurface);
        SDL_BlitSurface(txtSurface, &src, screen, &dest);
    }
}

void TextMessage::setWidth(int width) {
    this->widthNewSurface = width;
}

void TextMessage::setHeight(int height) {
    this->heightNewSurface = height;
}

void TextMessage::setShowTextMessage(bool show) {
    showTextMessage = show;
}

bool TextMessage::getShowTextMessage() {
    return this->showTextMessage;
}

void TextMessage::setBmpFont(BmpFont *bmpFont){
    this->bmpFont = bmpFont;
}

void TextMessage::setTitle(wstring title) {
    textTitle->setText(title);
    textTitle->setFont(bmpFont);
    textTitle->setX(10);
    textTitle->setY(10);
}

void TextMessage::setContent(wstring content) {
    textContent->setText(content);
    textContent->setFont(bmpFont);
    textContent->setX(10);
    textContent->setY(45);
}

