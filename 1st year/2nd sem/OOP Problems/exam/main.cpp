/*
 * 2)
 * a) Class Vehicle with matriculation number(char*) and maxSpeed(int);
 * b) Classes
 *      Tank: Vehicle with volume(float) and
 *      Truck: Vehicle with capacity(float);
 *
 * Valid for all classes:
 * - init and copy c-tors
 * - operator=
 * - setters, getters
 * - read, print
 * - destructor
 */

#include <iostream>
#include "Vehicle.h"
#include "Truck.h"
#include "Tank.h"

using namespace std;

int main() {
    const char *fileName = "..\\data.txt";
    ifstream fin(fileName);

    Vehicle *vehicle = new Vehicle();
    Vehicle *truck = new Truck();
    Vehicle *tank = new Tank();

    fin >> vehicle;
    fin >> truck;
    fin >> tank;

    cout << vehicle << endl;
    cout << truck << endl;
    cout << tank << endl;

    cout << "Press any key to exit...";
    getchar();

    delete vehicle;
    delete truck;
    delete tank;

    fin.close();
    return 0;
}