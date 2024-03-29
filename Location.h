#ifndef LOCATION_H_
#define LOCATION_H_

/*
    struct for representing locations in the grid.
*/
struct Location
{
    int row, col;

    Location()
    {
        row = col = 0;
    };

    Location(int r, int c)
    {
        row = r;
        col = c;
    };

    bool operator==(const Location &other) const
    {
        return ( row == other.row && col == other.col);
    }

    bool operator<(const Location &other) const
    {
        if(row<other.row)
	    return true;
	else if (row==other.row)
	    return(col<other.col);
	else return false;
    }

    bool operator!=(const Location &other) const
    {
    	return !( *this == other );
    }

    bool operator<=(const Location &other) const
    {
        return (*this < other) || (*this == other);
    }

    bool operator >(const Location &other) const
    {
        return !(*this <= other);
    }
    
    bool operator>=(const Location &other) const
    {
        return !(*this < other);
    }
};

#endif //LOCATION_H_
