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

class Player : public GenericPlayer
{
    public:
      Player( const string& name="" );
      virtual ~Player();

      virtual bool IsHitting() const;
      void Win() const;
      void Lose() const;
      void Push() const; 
};

Player::Player( const string& name )
  : GenericPlayer( name )
{

}

Player::~Player()
{

}

bool Player::IsHitting() const
{
    cout << m_Name << ", do you want to hit? (Y/N): ";
    char response;
    cin >> response;
    return( response == 'y' || response == 'Y' );
}

void Player::Win() const
{
    cout << m_Name << " wins!\n";
}

void Player::Lose() const
{
    cout << m_Name << " loses.\n";
}

void Player::Push() const
{
    cout << m_Name << " pushes.\n";
}