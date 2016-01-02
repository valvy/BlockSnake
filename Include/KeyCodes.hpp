
#ifndef KEY_CODES_HPP
#define KEY_CODES_HPP



namespace KeyCodes {
#ifdef __APPLE__

    constexpr unsigned short SPACE_BAR = 49;
    constexpr unsigned short UP_KEY = 126;
    constexpr unsigned short DOWN_KEY = 125;
    constexpr unsigned short LEFT_KEY = 124;
    constexpr unsigned short RIGHT_KEY = 123;
    constexpr unsigned short ESCAPE_KEY = 53;

#endif
#ifdef _WIN32
    constexpr unsigned short SPACE_BAR = 49;
    constexpr unsigned short UP_KEY = 126;
    constexpr unsigned short DOWN_KEY = 125;
    constexpr unsigned short LEFT_KEY = 124;
    constexpr unsigned short RIGHT_KEY = 123;
    constexpr unsigned short ESCAPE_KEY = 53;

#endif
#ifdef __linux__
    constexpr unsigned short SPACE_BAR = 65;
    constexpr unsigned short UP_KEY = 111;
    constexpr unsigned short DOWN_KEY = 116;
    constexpr unsigned short LEFT_KEY = 114;
    constexpr unsigned short RIGHT_KEY = 113;
    constexpr unsigned short ESCAPE_KEY = 9;

#endif

}


#endif

