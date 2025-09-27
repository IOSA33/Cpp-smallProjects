#include <cassert> // for assert()
#include <cmath> // for std::sqrt
#include <iostream>

/*
 *Asserts are better than comments because they have both document
 *and enforce a condition. Comments can become stale when the code
 *changes and the comment isn’t updated. An assert that has become out of date
 *is a code correctness issue, so developers are less likely to let them languish.
 */

double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
{
    // If gravity is negative it returns false, and if false program return assert and exit program
    assert(gravity > 0.0); // The object won't reach the ground unless there is positive gravity.

    /*
    * Example if we need to add commet to assert.
    1:
    assert(found && "Car could not be found in database");

    2:
    assert(moved && "Need to handle case where student was just moved to another classroom");
    */
    if (initialHeight <= 0.0)
    {
        // The object is already on the ground. Or buried.
        return 0.0;
    }

    return std::sqrt((2.0 * initialHeight) / gravity);
}

int main()
{
    std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " second(s)\n";

    return 0;
}