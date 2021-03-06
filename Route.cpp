#include "Route.hpp"
#include <math.h>
#include <limits>




Route::Route(vector<City*> c)
{
	this->cities = c; 
}

int Route::calculateDistance() {

	int total = 0; 
	
	City *current = this->cities[0];				//start at first city 
	queue<City*> Q; 
	Q.push(current); 

	while (Q.size() > 0) {
		current = Q.front();
		Q.pop();

		current->setColor("black");					//black means visited 
		route.push_back(current);					//keep track of route

		int d1, d2, sq1, sq2, sum, sqr, idx = 0; 
		int min = std::numeric_limits<int>::max();

		int x1, x2, y1, y2; 
		x1 = current->getX(); 
		y1 = current->getY(); 

		for (int i = 0; i < current->getNeighbors().size(); i++) {
			if (current->getNeighbors()[i]->getColor() == "white") {
				x2 = current->getNeighbors()[i]->getX();
				y2 = current->getNeighbors()[i]->getY();

				d1 = x1 - x2;							//calculate distance
				d2 = y1 - y2;
				sq1 = d1 * d1;
				sq2 = d2 * d2;
				sum = sq1 + sq2;
				sqr = sqrt(sum);

				if (i == 0) {
					min = sqr;
					idx = i;
				}
				else if (sqr < min) {
					min = sqr;
					idx = i;
				}

			}

		}

		if (min != std::numeric_limits<int>::max()) {
			total = total + min;
		}

		if (current->getNeighbors()[idx]->getColor() == "white") {
			Q.push(current->getNeighbors()[idx]);
		}

	}

	int lastStretch = goBackHome(current);					//turn path into cycle
	total = total + lastStretch; 
	
	return total; 
}

vector<City*> Route::getCities() {
	return this->cities; 
}

int Route::goBackHome(City* current) {
	int x1 = current->getX(); 
	int y1 = current->getY(); 
	int x2 = cities[0]->getX(); 
	int y2 = cities[0]->getY(); 

	int d1, d2, sq1, sq2, sum, sqr = 0;


	d1 = x1 - x2;
	d2 = y1 - y2;
	sq1 = d1 * d1;
	sq2 = d2 * d2;
	sum = sq1 + sq2;
	sqr = sqrt(sum);

	route.push_back(cities[0]); 
	cout << "From " << current->getId() << " to " << cities[0]->getId() << endl; 

	return sqr; 


}

void Route::printRoute() {
	for (int i = 0; i < route.size(); i++) {
		cout << i << ": " << route[i]->getId() << endl; 
	}

}
