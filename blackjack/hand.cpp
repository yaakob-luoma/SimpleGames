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

class Hand
{
  Hand();
  virtual ~Hand();
  void Add( Card* pCard );
  void Clear();
  int GetTotal() const;

  protected:
    vector< Card* >m_Cards;
};

Hand::Hand()
{
    m_Cards.reserve(7);
}

Hand::~Hand()
{
    Clear();
}

void Hand::Add( Card* pCard )
{
    m_Cards.push_back( pCard );
}

void Hand::Clear()
{
    vector< Card* >::iterator iter = m_Cards.begin();
    for( iter = m_Cards.begin(); iter != m_Cards.end(); ++iter )
    {
        delete *iter;
        *iter = 0;
    }
    m_Cards.clear();
}

int Hand::GetTotal() const
{
    if( m_Cards.empty() )
    {
        return 0;
    }
    
    //if first card has value of 0, then card is face down
    if( m_Cards[0]->GetValue() == 0 )
    {
        return 0;
    }
    
    int total = 0;
    bool containsAce = false;
    vector< Card*>::const_iterator iter;
    for( iter=m_Cards.begin(); iter != m_Cards.end(); ++iter )
    {
        total += (*iter)->GetValue();
        if( !containsAce )
        {
          if( (*iter)->GetValue() == CARD::ACE )
          {
            containsAce = true;
          }
        }
        
    }

    if( containsAce && total <= 11 )
    {
        total += 10;
    }

    return total;
}