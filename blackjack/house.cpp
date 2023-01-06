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

class House : public GenericPlayer
{
    public:
      House( const string& name = "House");
      virtual ~House();

      virtual bool IsHitting() const;
      void FlipFirstCard();
};

House::House( const string& name )
  : GenericPlayer( name )
{

}

House::~House()
{

}

bool House::IsHitting() const
{
    return( GetTotal() <= 16 );
}

void House::FlipFirstCard()
{
    if( !(m_Cards.empty() ) )
    {
        m_Cards[0]->Flip();
    }
    else
    {
      cout << "No card to flip!\n";
    }
}