#ifndef BOT_H_
#define BOT_H_

#include "State.h"

/*
    This struct represents your bot in the game of Ants
*/
struct Bot
{
    State state;

    std::map<Location,Location> orders;
    std::map<Location,Location> foodTargets;

    Bot();

    void playGame();    //plays a single game of Ants

    bool doMoveDirection( const Location &l, int d);
    bool doMoveLocation(Location antLoc, Location destLoc);

    void doTurn();

    void makeMoves();   //makes moves for a single turn
    void endTurn();     //indicates to the engine that it has made its moves
    
    bool shortest_dist_first(Route first, Route second);
};

#endif //BOT_H_
