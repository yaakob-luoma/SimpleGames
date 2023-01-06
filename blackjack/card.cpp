#ifndef INCLUDED_IOSTREAM
#include <iostream>
#define INCLUDED_IOSTREAM
#endif

#ifndef INCLUDED_STRING
#include <string>
#define INCLUDED_STRING
#endif

#ifndef INCLUDED_VECTOR
#include <vector>
#define INCLUDED_VECTOR
#endif 

#ifndef INCLUDED_ALGORITHM
#include <algorithm>
#define INCLUDED_ALGORITHM
#endif

#ifndef INCLUDED_CTIME
#include <ctime>
#define INCLUDED_CTIME
#endif

using namespace std;

class Card
{
    public:
      enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
      enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

      //overloading << operator so can send Card object to standard output
      friend ostream& operator<<(ostream& os, const Card& aCard );

      Card( rank r = ACE, suit s = SPADES, bool isfaceup = true );

      //returns the value of a card, 1 - 11
      int GetValue() const;
      
      //flips a card;, if face up, become face down and vice versa
      void Flip();

      private:
        rank m_Rank;
        suit m_Suit;
        bool m_IsFaceUp;
};

Card::Card( rank r, suit s, bool isfaceup )
  : m_Rank( r )
  , m_Suit( s )
  , m_IsFaceUp( isfaceup )
{

}

int Card::GetValue() const
{
    int value = 0;
    if( m_IsFaceUp )
    {
        value = m_Rank;
        if( value > 10 )
        {
            value = 10;
        }
    }
    return value;
}

void Card::Flip()
{
    m_IsFaceUp = !( m_IsFaceUp );
}