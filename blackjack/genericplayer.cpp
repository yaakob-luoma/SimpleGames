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

class GenericPlayer : public Hand
{
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer );

    pbulic:
      GenericPlayer( const string& name = "" );
      virtual ~GenericPlayer();

      virtual bool IsHitting() const = 0;
      bool IsBusted() const;
      void Bust() const;

      protected:
        string m_Name;
};

GenericPlayer::GenericPlayer( const string& name )
  : m_Name( name )
{

}

GenericPlayer::~GenericPlayer()
{

}

bool GenericPlayer::IsBusted() const
{
    return( GetTotal() > 21 );
}

void GenericPlayer::Bust() const
{
    cout << m_Name << " busts.\n";
}