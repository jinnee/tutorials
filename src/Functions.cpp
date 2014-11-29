#include "../include/Functions.h"

namespace ConvertFunctions
{
    /**
        Конвертира char към string
        Ако искаме да конвертираме char:
        char ch = 'd';
        charToString(&ch);
    */
    string charToString(char* ch)
    {
        stringstream stringStream;
        string result;
        stringStream << ch;
        stringStream >> result;
        return result;
    }

    string intToString(int i) // convert int to string
    {
        stringstream s;
        s << i;
        return s.str();
    }
}

