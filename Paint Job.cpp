#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double GALLONS_PER_SQFT = 1.0 / 110.0;
const double HOURS_PER_SQFT = 8.0 / 110.0;
const double LABOR_CHARGE_PER_HOUR = 25.00;

int getNumRooms();
double getPricePerGallon();
double getSqFt(int roomNumber);
int gallonsForRoom(double sqFt);
double laborHoursForRoom(double sqFt);
void displayEstimate(double paintCost, double laborCost, int gallons, double laborHours);

int main()
{
    int numRooms;
    double pricePerGallon;
    double sqFt;
    int totalGallons = 0;
    double totalLaborHours = 0;
    double paintCost;
    double laborCost;

    cout << "Paint Job Estimator" << endl;

    numRooms = getNumRooms();
    pricePerGallon = getPricePerGallon();

    for (int room = 1; room <= numRooms; room++)
    {
        sqFt = getSqFt(room);

        totalGallons += gallonsForRoom(sqFt);
        totalLaborHours += laborHoursForRoom(sqFt);
    }

    paintCost = totalGallons * pricePerGallon;
    laborCost = totalLaborHours * LABOR_CHARGE_PER_HOUR;

    displayEstimate(paintCost, laborCost, totalGallons, totalLaborHours);

    return 0;
}

/*
Purpose:
Gets and validates the number of rooms to be painted.

Parameters:
None.

Preconditions:
None.

Postconditions:
Returns a number of rooms that is at least 1.
*/
int getNumRooms()
{
    int rooms;

    cout << "Enter the number of rooms to be painted: ";
    cin >> rooms;

    while (rooms < 1)
    {
        cout << "Invalid input. Number of rooms must be at least 1." << endl;
        cout << "Enter the number of rooms to be painted: ";
        cin >> rooms;
    }

    return rooms;
}

/*
Purpose:
Gets and validates the price per gallon of paint.

Parameters:
None.

Preconditions:
None.

Postconditions:
Returns a paint price that is at least $10.00.
*/
double getPricePerGallon()
{
    double price;

    cout << "Enter the price per gallon of paint: ";
    cin >> price;

    while (price < 10.00)
    {
        cout << "Invalid input. Price per gallon must be $10.00 or greater." << endl;
        cout << "Enter the price per gallon of paint: ";
        cin >> price;
    }

    return price;
}

/*
Purpose:
Gets and validates the square feet of wall space for one room.

Parameters:
roomNumber is the number of the room currently being entered.

Preconditions:
roomNumber is a valid room number.

Postconditions:
Returns square footage that is 0 or greater.
*/
double getSqFt(int roomNumber)
{
    double sqFt;

    cout << "Enter the square feet of wall space for room " << roomNumber << ": ";
    cin >> sqFt;

    while (sqFt < 0)
    {
        cout << "Invalid input. Square footage must be 0 or greater." << endl;
        cout << "Enter the square feet of wall space for room " << roomNumber << ": ";
        cin >> sqFt;
    }

    return sqFt;
}

/*
Purpose:
Calculates the gallons of paint needed for one room.

Parameters:
sqFt is the square feet of wall space for the room.

Preconditions:
sqFt is 0 or greater.

Postconditions:
Returns the number of gallons needed, rounded up.
*/
int gallonsForRoom(double sqFt)
{
    return ceil(sqFt * GALLONS_PER_SQFT);
}

/*
Purpose:
Calculates the labor hours needed for one room.

Parameters:
sqFt is the square feet of wall space for the room.

Preconditions:
sqFt is 0 or greater.

Postconditions:
Returns the labor hours needed for the room.
*/
double laborHoursForRoom(double sqFt)
{
    return sqFt * HOURS_PER_SQFT;
}

/*
Purpose:
Displays the complete paint job estimate.

Parameters:
paintCost is the total cost of paint.
laborCost is the total labor charge.
gallons is the total gallons of paint required.
laborHours is the total labor hours required.

Preconditions:
All values have already been calculated.

Postconditions:
The estimate is displayed to the console.
*/
void displayEstimate(double paintCost, double laborCost, int gallons, double laborHours)
{
    cout << fixed << setprecision(2);

    cout << endl;
    cout << "Paint Job Estimate" << endl;
    cout << "Total gallons of paint required: " << gallons << endl;
    cout << "Total labor hours required: " << laborHours << endl;
    cout << "Cost of paint: $" << paintCost << endl;
    cout << "Labor charges: $" << laborCost << endl;
    cout << "Total cost of paint job: $" << paintCost + laborCost << endl;
}