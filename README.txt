This is v1 of step 2.

VERSION CHANGES:

-Route.h
This is a new class that stores a start location and an end location
and a distance between the two locations.

-State.cc / State.h
This contains a new function called getDirection(const Location &from,
const Location &to). Given a 'from' and 'to' location, it'll return a
direction in which the ant should move.

-Bot.cc
Added map<Location,Location> foodTargets to variables
Added doMoveLocation, shortest_dist_first, and a redone doTurn.

foodTargets is to make sure that only one ant is assigned to one food item
similar to orders.

doMoveLocation will take an ant Location and a target Location, then
attempt to do the move.

doTurn has been redone to:
1. Build a list of every ant to food combo and store distance
2. Sort the list so the shortest distance is first when looping.
   ! Notes: This doesn't work yet, still must be worked on. That is why
            this is only version 1.  If you want to help, we must complete
	    bool shortest_dist_first.

	    shortest_dist_first is a functor that will help us sort the
	    list so our list has the shortest distance first.

	    For an example http://www.cplusplus.com/reference/stl/list/sort/

3. Loop through all combos and if the ant hasn't been ordered, and food
   hasn't been targeted, issue new order.
4. At the end, we save this order into foodTargets.
