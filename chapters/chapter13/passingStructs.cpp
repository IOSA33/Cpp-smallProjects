#include <iostream>

struct Employee
{
    int id {}; // The value initialization
    int age {};
    double wage {};
};

struct Point3d {
    double x {0.0};
    double y {0.0};
    double z {0.0};
};

struct AdRevenue {
    int adsWatched;
    int percentageOfUsersClicks;
    int revenuePerClick;
};

void printDataOfTheDay(const AdRevenue& adRevenue) {
    std::cout << adRevenue.adsWatched << '\n';
    std::cout << adRevenue.percentageOfUsersClicks << '\n';
    std::cout << adRevenue.revenuePerClick << '\n';

    std::cout << "Day revenue of ads is: " << adRevenue.adsWatched * adRevenue.percentageOfUsersClicks / 100 * adRevenue.revenuePerClick << '\n';
}

// note pass by reference here
void printEmployee(const Employee& employee)
{
    std::cout << "ID:   " << employee.id << '\n';
    std::cout << "Age:  " << employee.age << '\n';
    std::cout << "Wage: " << employee.wage << '\n';
}

Point3d getZeroPoint() {
    return Point3d { 0.0, 0.0, 0.0 }; // return an unnamed Point3d
}


int main()
{
    Employee joe { .age  = 32, .wage = 24.15 };
    Employee frank { 15, 28, 18.27 };

    Point3d zero{getZeroPoint()};
    if (zero.x == 0.0 && zero.y == 0.0 && zero.z == 0.0)
        std::cout << "The point is zero\n";
    else
        std::cout << "The point is not zero\n";

    // Print Joe's information
    printEmployee(joe);
    printEmployee(Employee {1, 18, 23.2});

    // construct a temporary Employee to pass to function (type deduced from parameter)
    printEmployee({ 15, 28, 18.27 });

    std::cout << '\n';

    // Print Frank's information
    printEmployee(frank);
    std::cout << '\n';
    printDataOfTheDay(AdRevenue {.adsWatched = 9342, .percentageOfUsersClicks = 47, .revenuePerClick = 2});

    return 0;
}