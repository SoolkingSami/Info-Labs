#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <queue>
#include <stack>
#include <tuple>

#define DIM 101

using namespace std;

enum struct City {
    Giurgiu = 1,
    Bucharest,
    Craiova,
    Oradea,
    Iasi,
    Timisoara,
    Urziceni,
    Vaslui,
    Zerind,
    Eforie,
    Neamt,
    Hirsova,
    Sibiu,
    Fagaras,
    Pitesti,
    Drobeta,
    Lugoj,
    Mehadia,
    Arad,
    Ramnicu_Valcea
};

City strToCity(char* str) {
    if (strcmp(str, "Bucharest") == 0) {
        return City::Bucharest;
    } else if (strcmp(str, "Craiova") == 0) {
        return City::Craiova;
    } else if (strcmp(str, "Oradea") == 0) {
        return City::Oradea;
    } else if (strcmp(str, "Iasi") == 0) {
        return City::Iasi;
    } else if (strcmp(str, "Timisoara") == 0) {
        return City::Timisoara;
    } else if (strcmp(str, "Urziceni") == 0) {
        return City::Urziceni;
    } else if (strcmp(str, "Vaslui") == 0) {
        return City::Vaslui;
    } else if (strcmp(str, "Zerind") == 0) {
        return City::Zerind;
    } else if (strcmp(str, "Eforie") == 0) {
        return City::Eforie;
    } else if (strcmp(str, "Neamt") == 0) {
        return City::Neamt;
    } else if (strcmp(str, "Hirsova") == 0) {
        return City::Hirsova;
    } else if (strcmp(str, "Sibiu") == 0) {
        return City::Sibiu;
    } else if (strcmp(str, "Fagaras") == 0) {
        return City::Fagaras;
    } else if (strcmp(str, "Pitesti") == 0) {
        return City::Pitesti;
    } else if (strcmp(str, "Drobeta") == 0) {
        return City::Drobeta;
    } else if (strcmp(str, "Lugoj") == 0) {
        return City::Lugoj;
    } else if (strcmp(str, "Mehadia") == 0) {
        return City::Mehadia;
    } else if (strcmp(str, "Arad") == 0) {
        return City::Arad;
    } else if (strcmp(str, "Ramnicu_Valcea") == 0) {
        return City::Ramnicu_Valcea;
    } else if (strcmp(str, "Giurgiu") == 0) {
        return City::Giurgiu;
    } else {
        cerr << "Invalid city name: " << str << endl;
        exit(1);
    }
}

char* cityToStr(City city) {
    if (city == City::Bucharest)
        return (char*)"Bucharest";
    else if (city == City::Craiova)
        return (char*)"Craiova";
    else if (city == City::Oradea)
        return (char*)"Oradea";
    else if (city == City::Iasi)
        return (char*)"Iasi";
    else if (city == City::Timisoara)
        return (char*)"Timisoara";
    else if (city == City::Urziceni)
        return (char*)"Urziceni";
    else if (city == City::Vaslui)
        return (char*)"Vaslui";
    else if (city == City::Zerind)
        return (char*)"Zerind";
    else if (city == City::Eforie)
        return (char*)"Eforie";
    else if (city == City::Neamt)
        return (char*)"Neamt";
    else if (city == City::Hirsova)
        return (char*)"Hirsova";
    else if (city == City::Sibiu)
        return (char*)"Sibiu";
    else if (city == City::Fagaras)
        return (char*)"Fagaras";
    else if (city == City::Pitesti)
        return (char*)"Pitesti";
    else if (city == City::Drobeta)
        return (char*)"Drobeta";
    else if (city == City::Lugoj)
        return (char*)"Lugoj";
    else if (city == City::Mehadia)
        return (char*)"Mehadia";
    else if (city == City::Arad)
        return (char*)"Arad";
    else if (city == City::Ramnicu_Valcea)
        return (char*)"Ramnicu_Valcea";
    else if (city == City::Giurgiu)
        return (char*)"Giurgiu";
    else {
        cerr << "Invalid city index: " << (int)city << endl;
        exit(1);
    }
}

int nrOfCities = 20;
int adjMatrixForDistance[DIM][DIM], adjMatrixForNrOfCars[DIM][DIM];
double adjMatrixForTime[DIM][DIM];
int averageSpeed = 80;

double getTime(int distance) {
    return (double)distance / averageSpeed;
}

double getTime(int distance, int nrOfCars) {
    return (double)distance / (averageSpeed * (nrOfCars ? nrOfCars : 1));
}

void initAdjMatrix(char* pathToCities) {
    ifstream file(pathToCities);
    char line[DIM];
    while (file.getline(line, DIM)) {
        char* city1 = strtok(line, " ");
        char* city2 = strtok(NULL, " ");
        char* distance = strtok(NULL, " ");
        char* nrOfCars = strtok(NULL, " ");
        int city1_ = (int)strToCity(city1);
        int city2_ = (int)strToCity(city2);

        adjMatrixForNrOfCars[city1_][city2_] =
        adjMatrixForNrOfCars[city2_][city1_] = atoi(nrOfCars);

        adjMatrixForDistance[city1_][city2_] =
        adjMatrixForDistance[city2_][city1_] = atoi(distance);

//        adjMatrixForTime[city1_][city2_] =
//        adjMatrixForTime[city2_][city1_] = getTime(atoi(distance));

        adjMatrixForTime[city1_][city2_] =
        adjMatrixForTime[city2_][city1_] = getTime(atoi(distance), atoi(nrOfCars));
    }
}

void getCitiesConnectedTo(City city, int& size, City*& cities) {
    for (int i = 1; i <= nrOfCities; i++) {
        if (adjMatrixForDistance[(int)city][i] != 0) {
            cities[size++] = (City)i;
        }
    }
}

using ituple = tuple<int, int, double, int, int>;

void runBfsFrom(City src, ituple parentOf[]) {
    bool visited[DIM];
    for (bool& i : visited) {
        i = false;
    }
    queue<ituple> q;

    visited[(int)src] = true;
    q.push(make_tuple(0, (int)src, 0, 0, 0));
    parentOf[(int)src] = make_tuple(-1, 0, 0, 0, 0);

    while(!q.empty()) {
        auto [distToParent, city, timeToParent, nrOfCarsToParent, nrOfCitiesToParent] = q.front();
        q.pop();
        int size = 0;
        City* cities = new City[DIM];
        getCitiesConnectedTo((City)city, size, cities);
        for (int i = 0; i < size; i++) {
            if (!visited[(int)cities[i]]) {
                visited[(int)cities[i]] = true;
                q.push(make_tuple(
                        distToParent + adjMatrixForDistance[(int)city][(int)cities[i]],
                        (int)cities[i],
                        timeToParent + adjMatrixForTime[(int)city][(int)cities[i]],
                        nrOfCarsToParent + adjMatrixForNrOfCars[(int)city][(int)cities[i]],
                        nrOfCitiesToParent + 1));

                parentOf[(int)cities[i]] = make_tuple(
                        (int)city,
                        distToParent + adjMatrixForDistance[(int)city][(int)cities[i]],
                        timeToParent + adjMatrixForTime[(int)city][(int)cities[i]],
                        nrOfCarsToParent + adjMatrixForNrOfCars[(int)city][(int)cities[i]],
                        nrOfCitiesToParent + 1
                        );
            }
        }
        delete[] cities;
    }
}

void runDfsFrom(City src, ituple parentOf[]) {
    bool visited[DIM];
    for (bool& i : visited) {
        i = false;
    }
    stack<ituple> s;

    visited[(int)src] = true;
    s.push(make_tuple(0, (int)src, 0, 0, 0));
    parentOf[(int)src] = make_tuple(-1, 0, 0, 0, 0);

    while(!s.empty()) {
        auto [distToParent, city, timeToParent, nrOfCarsToParent, nrOfCitiesToParent] = s.top();
        s.pop();
        int size = 0;
        City* cities = new City[DIM];
        getCitiesConnectedTo((City)city, size, cities);
        for (int i = 0; i < size; i++) {
            if (!visited[(int)cities[i]]) {
                visited[(int)cities[i]] = true;
                s.push(make_tuple(
                        distToParent + adjMatrixForDistance[(int)city][(int)cities[i]],
                        (int)cities[i],
                        timeToParent + adjMatrixForTime[(int)city][(int)cities[i]],
                        nrOfCarsToParent + adjMatrixForNrOfCars[(int)city][(int)cities[i]],
                        nrOfCitiesToParent + 1
                        ));

                parentOf[(int)cities[i]] = make_tuple(
                        (int)city,
                        distToParent + adjMatrixForDistance[(int)city][(int)cities[i]],
                        timeToParent + adjMatrixForTime[(int)city][(int)cities[i]],
                        nrOfCarsToParent + adjMatrixForNrOfCars[(int)city][(int)cities[i]],
                        nrOfCitiesToParent + 1
                        );
            }
        }
        delete[] cities;
    }
}

void runDijkstraFrom(City src, ituple parentOf[]) {
    bool visited[DIM];
    for (bool& i : visited) {
        i = false;
    }
    priority_queue<ituple, vector<ituple>, greater<>> pq;

    visited[(int)src] = true;
    pq.push(make_tuple(0, (int)src, 0, 0, 0));
    parentOf[(int)src] = make_tuple(-1, 0, 0, 0, 0);

    while(!pq.empty()) {
        auto [distToParent, city, timeToParent, nrOfCarsToParent, nrOfCitiesToParent] = pq.top();
        pq.pop();
        int size = 0;
        City* cities = new City[DIM];
        getCitiesConnectedTo((City)city, size, cities);
        for (int i = 0; i < size; i++) {
            if (!visited[(int)cities[i]]
                || distToParent + adjMatrixForDistance[(int)city][(int)cities[i]]
                < get<0>(parentOf[(int)cities[i]])) {
                visited[(int)cities[i]] = true;
                pq.push(make_tuple(
                        distToParent + adjMatrixForDistance[(int)city][(int)cities[i]],
                        (int)cities[i],
                        timeToParent + adjMatrixForTime[(int)city][(int)cities[i]],
                        nrOfCarsToParent + adjMatrixForNrOfCars[(int)city][(int)cities[i]],
                        nrOfCitiesToParent + 1
                        ));

                parentOf[(int)cities[i]] = make_tuple(
                        (int)city,
                        distToParent + adjMatrixForDistance[(int)city][(int)cities[i]],
                        timeToParent + adjMatrixForTime[(int)city][(int)cities[i]],
                        nrOfCarsToParent + adjMatrixForNrOfCars[(int)city][(int)cities[i]],
                        nrOfCitiesToParent + 1
                        );
            }
        }
        delete[] cities;
    }
}

void recomputeChainFrom(City current, ituple parentOf[]) {
    auto[parent, ignore1, ignore2, ignore3, ignore4] = parentOf[(int)current];
    if (parent == -1) {
        cout << cityToStr(current) << "\n";
        return;
    }
    recomputeChainFrom((City)parent, parentOf);
    cout << cityToStr(current) << "\n";
}

int main() {
    initAdjMatrix((char*)"cities.txt");

//    int cnt = 0;
//    char src[DIM];
//
//    cout << "Enter the name of a city:\n";
//    cin >> src;
//
//    cout << "The cities connected to " << src << " are:\n";
//    City* cities = new City[DIM];
//    getCitiesConnectedTo(strToCity(src), cnt, cities);
//    for (int i = 0; i < cnt; i++) {
//        cout << cityToStr(cities[i]) << endl;
//    }
//    delete[] cities;

    ituple parentOfForBfs[DIM], parentOfForDfs[DIM], parentOfForDijkstra[DIM];
    char src[DIM], dest[DIM];

    cout << "Enter the name of the source city:\n";
    cin >> src;
    cout << "Enter the name of the destination city:\n";
    cin >> dest;

    runBfsFrom(strToCity(src), parentOfForBfs);
    runDfsFrom(strToCity(src), parentOfForDfs);
    runDijkstraFrom(strToCity(src), parentOfForDijkstra);

    cout << "The chain of cities between " << src << " and " << dest << " is:\n";

    cout << "\nUsing DFS:\n";
    recomputeChainFrom(strToCity(dest), parentOfForDfs);
    auto[ignoreDfs, distDfs, timeDfs, nrOfCarsDfs, nrOfCitiesDfs] = parentOfForDfs[(int)strToCity(dest)];
    cout << "\nDistance from " << src << " to " << dest << " is: "
         << distDfs << " km" << endl;
    cout << "Time from " << src << " to " << dest << " is: "
         << fixed << setprecision(1) << timeDfs << " hours" << endl;
    cout << "Number of cars from " << src << " to " << dest << " is: "
         << nrOfCarsDfs << " cars" << endl;
    cout << "Number of cities from " << src << " to " << dest << " is: "
         << nrOfCitiesDfs << " cities" << endl;

    cout << "\nUsing BFS:\n";
    recomputeChainFrom(strToCity(dest), parentOfForBfs);
    auto[ignoreBfs, distBfs, timeBfs, nrOfCarsBfs, nrOfCitiesBfs] = parentOfForBfs[(int)strToCity(dest)];
    cout << "\nDistance from " << src << " to " << dest << " is: "
         << distBfs << " km" << endl;
    cout << "Time from " << src << " to " << dest << " is: "
         << fixed << setprecision(1) << timeBfs << " hours" << endl;
    cout << "Number of cars from " << src << " to " << dest << " is: "
         << nrOfCarsBfs << " cars" << endl;
    cout << "Number of cities from " << src << " to " << dest << " is: "
         << nrOfCitiesBfs << " cities" << endl;

    cout << "\nUsing Dijkstra:\n";
    recomputeChainFrom(strToCity(dest), parentOfForDijkstra);
    auto[ignoreDijkstra, distDijkstra, timeDijkstra, nrOfCarsDijkstra, nrOfCitiesDijkstra] =
            parentOfForDijkstra[(int)strToCity(dest)];
    cout << "\nDistance from " << src << " to " << dest << " is: "
         << distDijkstra << " km" << endl;
    cout << "Time from " << src << " to " << dest << " is: "
         << fixed << setprecision(1) << timeDijkstra << " hours" << endl;
    cout << "Number of cars from " << src << " to " << dest << " is: "
         << nrOfCarsDijkstra << " cars" << endl;
    cout << "Number of cities from " << src << " to " << dest << " is: "
         << nrOfCitiesDijkstra << " cities" << endl;

    return 0;
}
