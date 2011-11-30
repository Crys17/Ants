#ifndef ROUTE_H_
#define ROUTH_H_

/**
 * Represents a route from one Location to another
 */

struct Route{

    // VARIABLES THAT DESCRIBE A ROUTE
    Location start, end;
    double distance;

    // INIT & COPY CONSTRUCTOR
    Route()
    { 
      start.row = 0; start.col =0;
      end.row = 0; end.col = 0;
      distance = 0;
    };
	
    Route(Location s, Location e, double d)
    {
    	start = s;
	end = e;
	distance = d;
    };

    bool operator==(const Route &other)
    {
    	return start==other.start&&end==other.end&&distance==other.distance;
    }

    bool operator<(const Route &other)
    {
    	return distance<other.distance;
    }	

    // COMPARISON FOR SORTING
    double diff(Route route)
    {
    	return distance - route.distance;
    };
 };

 #endif //ROUTE_H_
