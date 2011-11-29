#include "Bot.h"

using namespace std;

//constructor
Bot::Bot()
{
    map<Location,Location> orders;
};

//plays a single game of Ants.
void Bot::playGame()
{
    //reads the game parameters and sets up
    cin >> state;
    state.setup();
    endTurn();

    //continues making moves while the game is not over
    while(cin >> state)
    {
        state.updateVisionInformation();
        // makeMoves();
	doTurn();
        endTurn();
    }
};

bool Bot::doMoveDirection(const Location &l, int d)
{
    Location nLoc = state.getLocation(l,d);
    if(state.free(nLoc) && orders.find(nLoc) == orders.end())
    {
        state.makeMove(l,d);
	orders.insert(pair<Location, Location > (nLoc,l) );
	printf(">>>>>>> (%d,%d) added to orders\n",nLoc.row,nLoc.col);
	return true;
    }
    else
        return false;
}

void Bot::doTurn()
{
    orders.clear();
    for(int ant=0;ant<(int)state.myAnts.size();ant++)
       for(int d=0;d<TDIRECTIONS;d++)
          if(doMoveDirection(state.myAnts[ant],d)) break;
}

//makes the bots moves for the turn
void Bot::makeMoves()
{
    state.bug << "turn " << state.turn << ":" << endl;
    state.bug << state << endl;

    //picks out moves for each ant
    for(int ant=0; ant<(int)state.myAnts.size(); ant++)
    {
        for(int d=0; d<TDIRECTIONS; d++)
        {
            Location loc = state.getLocation(state.myAnts[ant], d);

            if(!state.grid[loc.row][loc.col].isWater && state.grid[loc.row][loc.col].ant == -1)
            {
                state.makeMove(state.myAnts[ant], d);
                break;
            }
        }
    }

    state.bug << "time taken: " << state.timer.getTime() << "ms" << endl << endl;
};

//finishes the turn
void Bot::endTurn()
{
    if(state.turn > 0)
        state.reset();
    state.turn++;

    cout << "go" << endl;
};
