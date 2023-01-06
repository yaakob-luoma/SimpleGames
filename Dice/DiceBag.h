#ifndef DICEBAG_H
#define DICEBAG_H

#include "BaseDie.h"

class DiceBag
{
public:
    DiceBag();

    unsigned int roll( unsigned int sides );
    unsigned int* roll( unsigned int sides, unsigned int numberOfRolls );

private:
    BaseDie d4;
    BaseDie d6;
    BaseDie d8;
    BaseDie d10;
    BaseDie d12;
    BaseDie d20;
    BaseDie d100;
};

#endif // DICEBAG_H
