//#include <iostream>
//#include <cassert>
//#include "Die.h"
//#include "Player.h"
//#include "Board.h"
//#include "BeatThat.h"
//
//
//void clearScreen( );
//
//int main()
//{
//    using namespace cs31;
//    using namespace std;
//
//    clearScreen();
//
//    BeatThat game;
//    std::string action, message = "(r)oll (q)uit: ";
//    std::cout << message;
//
//    do
//    {
//        getline( cin, action );
//        while (action.size() == 0)
//        {
//            getline( cin, action );  // no blank entries allowed....
//        }
//        switch (action[0])
//        {
//            default:   // if bad move, nobody moves
//                cout << '\a' << endl;  // beep
//                continue;
//            case 'Q':
//            case 'q':
//                return 0;
//            case 'r':
//            case 'R':
//                game.humanPlay();
//                game.computerPlay();
//                game.endTurn();
//                cout << game.display( message ) << endl;
//                break;
//        }
//    } while( !game.isGameOver() );
//    cout << game.endingMessage() << endl;
//
//    return( 0 );
//}

#include <iostream>
#include <string>
#include <cassert>
#include "RandomNumber.h"
#include "Die.h"
#include "Player.h"
#include "Board.h"
#include "BeatThat.h"

int main()
{
    using namespace std;
    using namespace cs31;

    // check initial conditions of board
    Board b;
    assert( b.getHumanRoundsWon( ) == 0 );
    assert( b.getComputerRoundsWon( ) == 0 );
    assert( b.getTurnsLeft( ) == 0 );
    assert( ! b.didHumanWin( ) );
    assert( ! b.didComputerWin( ) );
    assert( ! b.isGameOver() );

    // check board setters
    b.setHumanRoundsWon( 1 );
    b.setComputerRoundsWon( 2 );
    b.setTurnsLeft( 3 );
    assert( b.getHumanRoundsWon( ) == 1 );
    assert( b.getComputerRoundsWon( ) == 2 );
    assert( b.getTurnsLeft( ) == 3 );

    // check cheating & marking computer as winner
    b.markComputerAsWinner( );
    assert( ! b.didHumanWin( ) );
    assert( b.didComputerWin( ) );
    assert( b.isGameOver( ) );

    // check cheating & marking tie game
    b.markTied( );
    assert( ! b.didHumanWin( ) );
    assert( ! b.didComputerWin( ) );
    assert( b.isGameOver( ) );

    // check cheating & marking human as winner
    b.markHumanAsWinner( );
    assert( b.didHumanWin( ) );
    assert( ! b.didComputerWin( ) );
    assert( b.isGameOver( ) );

    // check initial conditions of game
    BeatThat game;
    assert( game.turnsLeft( ) == 5 );
    assert( game.isGameOver( ) == false );
    assert( game.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );

    // set and check cheating dice
    // check that setting value = 0 or 7 sets it to 1 instead
    Die d0;
    d0.setValue( 0 );
    assert( d0.getValue( ) == 1 );
    Die d1;
    d1.setValue( 1 );
    assert( d1.getValue( ) == 1 );
    Die d2;
    d2.setValue( 2 );
    assert( d2.getValue( ) == 2 );
    Die d3;
    d3.setValue( 3 );
    assert( d3.getValue( ) == 3 );
    Die d4;
    d4.setValue( 4 );
    assert( d4.getValue( ) == 4 );
    Die d5;
    d5.setValue( 5 );
    assert( d5.getValue( ) == 5 );
    Die d6;
    d6.setValue( 6 );
    assert( d6.getValue( ) == 6 );
    Die d7;
    d7.setValue( 7 );
    assert( d7.getValue( ) == 1 );

    // test player class and player's dice rolling
    // check what same dice rolled does
    Player p;
    assert( p.getRoundsWon( ) == 0 );
    p.wonARound( );
    assert( p.getRoundsWon( ) == 1 );
    p.roll( d1, d6 );
    assert( p.whatWasRolled( ) == "Die1: 1 Die2: 6" );
    assert( p.getDie1( ).getValue( ) == 1 );
    assert( p.getDie2( ).getValue( ) == 6 );
    assert( p.largestDie( ).getValue( ) == 6 );
    assert( p.smallestDie( ).getValue( ) == 1 );
    p.roll( d2, d2 );
    assert( p.whatWasRolled( ) == "Die1: 2 Die2: 2" );
    assert( p.getDie1( ).getValue( ) == 2 );
    assert( p.getDie2( ).getValue( ) == 2 );
    assert( p.largestDie( ).getValue( ) == 2 );
    assert( p.smallestDie( ).getValue( ) == 2 );

    // tie game
    // check turns left, game over?, human rounds won, computer rounds won, and game outcome at every step
    assert( game.turnsLeft( ) == 5 );
    game.humanPlay( d1, d2 );
    game.computerPlay( d2, d1 );
    game.endTurn( );
    assert( game.turnsLeft( ) == 4 );
    assert( game.isGameOver( ) == false );
    assert( game.getHuman( ).getRoundsWon( ) == 0 );
    assert( game.getComputer( ).getRoundsWon( ) == 0);
    assert( game.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game.humanPlay( d4, d4 );
    game.computerPlay( d6, d1 );
    game.endTurn( );
    assert( game.turnsLeft( ) == 3 );
    assert( game.isGameOver( ) == false );
    assert( game.getHuman( ).getRoundsWon( ) == 0 );
    assert( game.getComputer( ).getRoundsWon( ) == 1 );
    assert( game.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game.humanPlay( d6, d5 );
    game.computerPlay( d6, d2 );
    game.endTurn( );
    assert( game.turnsLeft( ) == 2 );
    assert( game.isGameOver( ) == false );
    assert( game.getHuman( ).getRoundsWon( ) == 1 );
    assert( game.getComputer( ).getRoundsWon( ) == 1 );
    assert( game.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game.humanPlay( d3, d3 );
    game.computerPlay( d3, d3 );
    game.endTurn( );
    assert( game.turnsLeft( ) == 1 );
    assert( game.isGameOver( ) == false );
    assert( game.getHuman( ).getRoundsWon( ) == 1 );
    assert( game.getComputer( ).getRoundsWon( ) == 1 );
    assert( game.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game.humanPlay( d5, d4 );
    game.computerPlay( d4, d5 );
    game.endTurn( );
    assert( game.turnsLeft( ) == 0 );
    assert( game.isGameOver( ) == true );
    assert( game.getHuman( ).getRoundsWon( ) == 1 );
    assert( game.getComputer( ).getRoundsWon( ) == 1 );
    assert( game.determineGameOutcome( ) == cs31::BeatThat::TIEDGAME );

    // human wins game
    // check turns left, game over?, human rounds won, computer rounds won, and game outcome at every step
    BeatThat game2;
    assert( game2.turnsLeft( ) == 5 );
    game2.humanPlay( d1, d3 );
    game2.computerPlay( d2, d1 );
    game2.endTurn( );
    assert( game2.turnsLeft( ) == 4 );
    assert( game2.isGameOver( ) == false );
    assert( game2.getHuman( ).getRoundsWon( ) == 1 );
    assert( game2.getComputer( ).getRoundsWon( ) == 0);
    assert( game2.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game2.humanPlay( d4, d4 );
    game2.computerPlay( d6, d1 );
    game2.endTurn( );
    assert( game2.turnsLeft( ) == 3 );
    assert( game2.isGameOver( ) == false );
    assert( game2.getHuman( ).getRoundsWon( ) == 1 );
    assert( game2.getComputer( ).getRoundsWon( ) == 1 );
    assert( game2.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game2.humanPlay( d6, d5 );
    game2.computerPlay( d6, d5 );
    game2.endTurn( );
    assert( game2.turnsLeft( ) == 2 );
    assert( game2.isGameOver( ) == false );
    assert( game2.getHuman( ).getRoundsWon( ) == 1 );
    assert( game2.getComputer( ).getRoundsWon( ) == 1 );
    assert( game2.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game2.humanPlay( d3, d6 );
    game2.computerPlay( d5, d3 );
    game2.endTurn( );
    assert( game2.turnsLeft( ) == 1 );
    assert( game2.isGameOver( ) == false );
    assert( game2.getHuman( ).getRoundsWon( ) == 2 );
    assert( game2.getComputer( ).getRoundsWon( ) == 1 );
    assert( game2.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game2.humanPlay( d5, d6 );
    game2.computerPlay( d4, d5 );
    game2.endTurn( );
    assert( game2.turnsLeft( ) == 0 );
    assert( game2.isGameOver( ) == true );
    assert( game2.getHuman( ).getRoundsWon( ) == 3 );
    assert( game2.getComputer( ).getRoundsWon( ) == 1 );
    assert( game2.determineGameOutcome( ) == cs31::BeatThat::HUMANWONGAME );

    // computer wins game
    // check turns left, game over?, human rounds won, computer rounds won, and game outcome at every step
    BeatThat game3;
    assert( game3.turnsLeft( ) == 5 );
    game3.humanPlay( d1, d3 );
    game3.computerPlay( d2, d1 );
    game3.endTurn( );
    assert( game3.turnsLeft( ) == 4 );
    assert( game3.isGameOver( ) == false );
    assert( game3.getHuman( ).getRoundsWon( ) == 1 );
    assert( game3.getComputer( ).getRoundsWon( ) == 0);
    assert( game3.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game3.humanPlay( d4, d4 );
    game3.computerPlay( d6, d1 );
    game3.endTurn( );
    assert( game3.turnsLeft( ) == 3 );
    assert( game3.isGameOver( ) == false );
    assert( game3.getHuman( ).getRoundsWon( ) == 1 );
    assert( game3.getComputer( ).getRoundsWon( ) == 1 );
    assert( game3.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game3.humanPlay( d6, d5 );
    game3.computerPlay( d6, d5 );
    game3.endTurn( );
    assert( game3.turnsLeft( ) == 2 );
    assert( game3.isGameOver( ) == false );
    assert( game3.getHuman( ).getRoundsWon( ) == 1 );
    assert( game3.getComputer( ).getRoundsWon( ) == 1 );
    assert( game3.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game3.humanPlay( d3, d1 );
    game3.computerPlay( d5, d6 );
    game3.endTurn( );
    assert( game3.turnsLeft( ) == 1 );
    assert( game3.isGameOver( ) == false );
    assert( game3.getHuman( ).getRoundsWon( ) == 1 );
    assert( game3.getComputer( ).getRoundsWon( ) == 2 );
    assert( game3.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game3.humanPlay( d5, d6 );
    game3.computerPlay( d6, d6 );
    game3.endTurn( );
    assert( game3.turnsLeft( ) == 0 );
    assert( game3.isGameOver( ) == true );
    assert( game3.getHuman( ).getRoundsWon( ) == 1 );
    assert( game3.getComputer( ).getRoundsWon( ) == 3 );
    assert( game3.determineGameOutcome( ) == cs31::BeatThat::COMPUTERWONGAME );

    // extreme tie game
    // check turns left, game over?, human rounds won, computer rounds won, and game outcome at every step
    BeatThat game4;
    assert( game4.turnsLeft( ) == 5 );
    game4.humanPlay( d1, d2 );
    game4.computerPlay( d2, d1 );
    game4.endTurn( );
    assert( game4.turnsLeft( ) == 4 );
    assert( game4.isGameOver( ) == false );
    assert( game4.getHuman( ).getRoundsWon( ) == 0 );
    assert( game4.getComputer( ).getRoundsWon( ) == 0);
    assert( game4.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game4.humanPlay( d6, d4 );
    game4.computerPlay( d6, d4 );
    game4.endTurn( );
    assert( game4.turnsLeft( ) == 3 );
    assert( game4.isGameOver( ) == false );
    assert( game4.getHuman( ).getRoundsWon( ) == 0 );
    assert( game4.getComputer( ).getRoundsWon( ) == 0 );
    assert( game4.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game4.humanPlay( d6, d2 );
    game4.computerPlay( d6, d2 );
    game4.endTurn( );
    assert( game4.turnsLeft( ) == 2 );
    assert( game4.isGameOver( ) == false );
    assert( game4.getHuman( ).getRoundsWon( ) == 0 );
    assert( game4.getComputer( ).getRoundsWon( ) == 0 );
    assert( game4.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game4.humanPlay( d3, d3 );
    game4.computerPlay( d3, d3 );
    game4.endTurn( );
    assert( game4.turnsLeft( ) == 1 );
    assert( game4.isGameOver( ) == false );
    assert( game4.getHuman( ).getRoundsWon( ) == 0 );
    assert( game4.getComputer( ).getRoundsWon( ) == 0 );
    assert( game4.determineGameOutcome( ) == cs31::BeatThat::GAMENOTOVER );
    game4.humanPlay( d1, d4 );
    game4.computerPlay( d4, d1 );
    game4.endTurn( );
    assert( game4.turnsLeft( ) == 0 );
    assert( game4.isGameOver( ) == true );
    assert( game4.getHuman( ).getRoundsWon( ) == 0 );
    assert( game4.getComputer( ).getRoundsWon( ) == 0 );
    assert( game4.determineGameOutcome( ) == cs31::BeatThat::TIEDGAME );

    cerr << "all tests passed!" << endl;
    return 0;
}

///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif


