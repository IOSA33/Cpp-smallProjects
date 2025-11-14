#include <iostream>
#include "Date.h"

// Second, if you change any of the code in the header, then you’ll need to recompile every file that includes that header.
// This can have a ripple effect, where one minor change causes the entire program to need to recompile.
// The cost of recompilation can vary significantly: a small project may only take a minute or less to build,
// whereas a large commercial project can take hours.

int main()
{
    const Date d { 2015, 10, 14 };
    d.print();

    return 0;
}