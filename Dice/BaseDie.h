#ifndef BASEDIE_H
#define BASEDIE_H

#include <stdlib.h>
#include <time.h>

class BaseDie
{
public:
    BaseDie(unsigned int sides = 6 );
    BaseDie( const BaseDie& copy );
    ~BaseDie();
    BaseDie& operator=( const BaseDie& assign );

    unsigned int roll();

    unsigned int getNumberOfSides() const;
    void setNumberOfSides(unsigned int value);

private:
    void initializeRandomSeed();
    unsigned int numberOfSides;
};

#endif // BASEDIE_H
