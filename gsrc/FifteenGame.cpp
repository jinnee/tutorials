#include <dirent.h>
#include <stdio.h>

#include "FifteenGame.h"

FifteenGame::FifteenGame() {

}

void FifteenGame::init() {
    cout << "init" << endl;
    this->setTitle("Игра 15");

}

void FifteenGame::update(double deltaTime) {
}

void FifteenGame::render() {
}

void FifteenGame::freeResources() {
    cout << "freeResources" << endl;
}

FifteenGame::~FifteenGame() {
}

//int FifteenGame::inGame = 0;
