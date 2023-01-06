#include "DiceBag.h"

DiceBag::DiceBag()
{
    d4 = BaseDie( 4 );
    d6 = BaseDie( 6 );
    d8 = BaseDie( 8 );
    d10 = BaseDie( 10 );
    d12 = BaseDie( 12 );
    d20 = BaseDie( 20 );
    d100 = BaseDie( 100 );
}

unsigned int DiceBag::roll(unsigned int sides)
{
    unsigned int result = 0;
    switch ( sides)
    {
        case 4:
            result = d4.roll();
            break;
        case 6:
            result = d6.roll();
            break;
        case 8:
            result = d8.roll();
            break;
        case 10:
            result = d10.roll();
            break;
        case 12:
            result = d12.roll();
            break;
        case 20:
            result = d20.roll();
            break;
        case 100:
            result = d100.roll();
            break;
        default:
            BaseDie temp( sides );
            result = temp.roll();
    }
    return  result;
}

unsigned int *DiceBag::roll(unsigned int sides, unsigned int numberOfRolls)
{
    unsigned int results[ numberOfRolls + 1];
    unsigned int sum = 0;
    for( unsigned int i = 0; i < numberOfRolls; i++ )
    {
        results[ i + 1 ] = roll( sides );
        sum += results[ i + 1 ];
    }
    results[0] = sum;
    return results;

}
