#include "BaseDie.h"

BaseDie::BaseDie( unsigned int sides)
    : numberOfSides( sides)
{
    initializeRandomSeed();
}

BaseDie::BaseDie(const BaseDie &copy)
    : numberOfSides( copy.getNumberOfSides() )
{
    initializeRandomSeed();
}

BaseDie::~BaseDie()
{

}

BaseDie &BaseDie::operator=(const BaseDie &assign)
{
    numberOfSides = assign.getNumberOfSides();
    return *this;
}

unsigned int BaseDie::roll()
{
    return rand() % numberOfSides + 1;
}

unsigned int BaseDie::getNumberOfSides() const
{
    return numberOfSides;
}

void BaseDie::setNumberOfSides(unsigned int value)
{
    numberOfSides = value;
}

void BaseDie::initializeRandomSeed()
{
    srand( time( NULL ) );
}
