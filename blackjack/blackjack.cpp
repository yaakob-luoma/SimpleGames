//blackjack 
//plays a simple version of the game blackjack for 1 - 7 players

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

class BlackjackGame
{
    public:
    BlackjackGame( const vector< string >& names );
    ~BlackjackGame();

    void Play();
    
    private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};

BlackjackGame::BlackjackGame( const vector< string>& names )
{
  vector< string>::const_iterator pName;
  for( pName = names.begin(); pName != names.end(); ++pName )
  {
    m_Players.push_back( Player( *pName ) );
  }

  srand( static_cast< unsigned int>(time(0)));
  m_Deck.Populate();
  m_Deck.Shuffle();
}

BlackjackGame::~BlackjackGame()
{

}

void BlackjackGame::Play()
{
    vector<Player>::iterator pPlayer;
    for( int i = 0; i < 2; ++i )
    {
        for( pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++ pPlayer )
        {
            m_Deck.Deal( *pPlayer );
        }
        m_Deck.Deal( m_House );
    }

    m_House.FlipFirstCard();

    for( pPlayer=m_Players.begin(); pPlayer !=m_Players.end(); ++pPlayer )
    {
        cout << *pPlayer << endl;
    }
    
    cout << m_House << endl;

    for( pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer )
    {
        m_Deck.AdditionalCards(*pPlayer);
    }

    m_House.FlipFirstCard();
    cout << endl << m_House;

    m_Deck.AdditionalCards( m_House );

    if( m_House.IsBusted )
    {
        for( pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer )
        {
            if( !(pPlayer->IsBusted() ))
            {
                pPlayer->Win();
            }
        }
    }
    else
    {
        for( pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer )
        {
            if( !(pPlayer->IsBusted() ))
            {
                if( pPlayer->GetTotal() > m_House.GetTotal() )
                {
                    pPlayer->Win();
                }
                else if( pPlayer->GetTotal() < m_House.GetTotal() )
                {
                    pPlayer->Lose();
                }
                else
                {
                    pPlayer->Push();
                }
            }
        }
    }

    for( pPlayer = m_Players.begin(); pPlayer != m_Players.end; ++pPlayer )
    {
        pPlayer->Clear();
    }
    m_House.Clear();
}

