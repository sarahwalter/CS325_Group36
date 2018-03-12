#include "City.hpp"
#include "Route.hpp"
#include <iostream>
#include <vector>
#include <string> 
#include <fstream>
#include <cstdlib>
using std::cout; 
using std::endl; 
using std::ifstream; 
using std::getline; 

int main() {

	ifstream myfile("example.txt");
	int a, b, c; 
	vector<City*> cities; 

	while (myfile >> a >> b >> c)  {
		City *p = new City(a, b, c);
		cities.push_back(p); 
	}

	myfile.close();

	for (int i = 0; i < cities.size() - 1; i++) {
		cities[i]->addEdge(cities[i + 1]);
		cities[i + 1]->addEdge(cities[i]); 
	}

	Route route(cities); 
	int total = route.calculateDistance(); 
	cout << total << endl; 


	system("pause");
	return 0; 
}