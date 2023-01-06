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

ostream& operator<<( ostream& os, const Card& aCard );
ostream& operator<<( ostream& os, const GenericPlayer& aGenericPlayer );

int main()
{
    cout << "\t\tWelcome to Blackjack!\n\n";

    int numPlayers = 0;
    while( numPlayers < 1 || numPlayers > 7 )
    {
        cout << "How many players? ( 1 - 7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for( int i = 0; i < numPlayers; ++i )
    {
        cout <<"Enter player name: ";
        cin >>name;
        names.push_back( name );
    }
    cout << endl;

    BlackjackGame game( names );
    char again='y';
    while( again != 'n' && again !='N')
    {
        game.Play();
        cout << "\nDo you want to play again?( Y/N ): ";
        cin >> again;
    }
    return 0;
}