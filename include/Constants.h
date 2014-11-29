#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace Constants {
    static string RESOURCE_DIR = "resources";
    namespace SpriteTypes {
        static string ABSTRACT_SPRITE = "ABSTRACT_SPRITE";
        static string ANIMATED_SPRITE = "ANIMATED_SPRITE";
        static string STATIC_SPRITE = "STATIC_SPRITE";
        static string MOUSE_CURSOR = "MOUSE_CURSOR";
        static string UI_BUTTON = "UI_BUTTON";
        static string LINE_TEXT = "LINE_TEXT";
        static string BACKGROUND = "BACKGROUND";
    }
    const string pathSeparator =
    #ifdef _WIN32
        "\\";
    #else
        "/";
    #endif
}
#endif // CONSTANTS_H
