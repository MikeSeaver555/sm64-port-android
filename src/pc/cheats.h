#ifndef _CHEATS_H
#define _CHEATS_H

#include <stdbool.h>

struct CheatList {
    bool         EnableCheats;
    bool         MoonJump;
    bool         GodMode;
    bool         InfiniteLives;
    bool         SuperSpeed;
    bool         Responsive;
    bool         ExitAnywhere;
    bool         HugeMario;
    bool         TinyMario;
    unsigned int NON;
    bool         LevelReset;
    unsigned int BLJAnywhere;
    bool         Timer;
};

extern struct CheatList Cheats;

#endif // _CHEATS_H
