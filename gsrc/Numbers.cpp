#include "Numbers.h"

Numbers::Numbers()
{
    startX = 40;
    startY = 40;
    numberWidth = 80;
    numberHeight = 80;
    objectNumbers = new AnimatedSprite();
    objectNumbers->setImage(Constants::RESOURCE_DIR + Constants::pathSeparator + "numbers.png");
    objectNumbers->setName("EMPTY");

    int x = 0;
    int y = 0;
    modelNumbers = getNumberOrder();

    for (int m = 0; m < 16; m++) {
         if (modelNumbers[m] != 0) {
            number = new AnimatedSprite();
            number->setTilesXY(15, 1);
            number->setImage(objectNumbers->getImage());
            number->setGroup("numbers");
            number->setName("number_"+ConvertFunctions::intToString(modelNumbers[m]-1));
            number->setFrameBeginEnd(modelNumbers[m]-1, modelNumbers[m]-1);
            number->calculate(10);

            number->setX(30+80*x);
            number->setY(30+80*y);
            SpriteManager::addSprite(number);
            vectorOfNumbers.push_back(number);
            //bVectorOfNumbers.push_back(number);
        } else {
            vectorOfNumbers.push_back(objectNumbers);
            //bVectorOfNumbers.push_back(objectNumbers);
        }
        x++;

        if ( x % 4 == 0) {
            x = 0;
            y++;
        }
    }
}

void Numbers::render() {
    for (int m = 0; m < 16; m++) {
        if (vectorOfNumbers[m]->isMouseButtonDown()) {
            switch (moveDecision(m)) {
            case LEFT:
                vectorOfNumbers[m]->setX(vectorOfNumbers[m]->getX() - 80);
                vectorOfNumbers[m]->setMouseButtonDown(false);
                swap(vectorOfNumbers[m], vectorOfNumbers[m-1]);
                break;
            case TOP:
                vectorOfNumbers[m]->setY(vectorOfNumbers[m]->getY() - 80);
                vectorOfNumbers[m]->setMouseButtonDown(false);
                swap(vectorOfNumbers[m], vectorOfNumbers[m-4]);
                break;
            case RIGHT:
                vectorOfNumbers[m]->setX(vectorOfNumbers[m]->getX() + 80);
                vectorOfNumbers[m]->setMouseButtonDown(false);
                swap(vectorOfNumbers[m], vectorOfNumbers[m+1]);
                break;
            case BOTTOM:
                vectorOfNumbers[m]->setY(vectorOfNumbers[m]->getY() + 80);
                vectorOfNumbers[m]->setMouseButtonDown(false);
                swap(vectorOfNumbers[m], vectorOfNumbers[m+4]);
                break;
            default:
                break;
            }
        }
        vectorOfNumbers[m]->render(this->screen);
    }
}

Numbers::~Numbers(){
    // изтриване от SpriteManager
    for (int m = 0; m < 16; m++) {
        SpriteManager::deleteSprite("number_"+ConvertFunctions::intToString(modelNumbers[m]-1));
    }
    vectorOfNumbers.clear();
    for (int i = 0; i < vectorOfNumbers.size(); i++) {
        delete vectorOfNumbers[i];
    }
    delete objectNumbers;
    cout << "delete Numbers" << endl;
}

void Numbers::setSurface(SDL_Surface* screen) {
    this->screen = screen;
}

int Numbers::moveDecision(int pos) {
    int left = -1;
    int right = -1;
    int top = -1;
    int bottom = -1;

    int result = 0;

    if (pos - 1 >= 0 && pos % 4 != 0) {
        left = modelNumbers[pos - 1];
    }

    if (pos + 1 <= 15 && pos % 4 != 3) {
        right = modelNumbers[pos + 1];
    }

    if (pos - 4 >= 0) {
        top = modelNumbers[pos - 4];
    }

    if (pos + 4 <= 15) {
        bottom = modelNumbers[pos + 4];
    }

    if (left == 0) {
        modelNumbers[pos - 1] = modelNumbers[pos];
        modelNumbers[pos] = 0;
        result = LEFT;
    } else if (right == 0) {
        modelNumbers[pos + 1] = modelNumbers[pos];
        modelNumbers[pos] = 0;
        result = RIGHT;
    } else if (top == 0) {
        modelNumbers[pos - 4] = modelNumbers[pos];
        modelNumbers[pos] = 0;
        result = TOP;
    } else if (bottom == 0) {
        modelNumbers[pos + 4] = modelNumbers[pos];
        modelNumbers[pos] = 0;
        result = BOTTOM;
    }

    cout << "delete Game15" << endl;

    return result;
}

int* Numbers::getNumberOrder() {
    static int arr[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int inversions= 0;

    do {
        inversions= 0;
        random_shuffle(&arr[0], &arr[16]);
        for (int i = 0; i < 16; i++) {
            for (int j = i+1; j < 16; j++) {
                if ( arr[i] - arr[j] > 0 && arr[j] != 0) {
                    inversions++;
                }
            }
        }
    } while (inversions % 2 != 0);

    return arr;
}
