//Anthony Sarabia - Lab 28 

#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"
using namespace std;

const int QUEUE_SIZE = 2;
const int PAY_PROB = 55;
const int JOIN_PROB = 45;

int randomNumber();
void printDivider();
void seedRandom();
void intializeQueue(deque<Car>& tollQueue, int initalSize);
void simulateCycle(deque<Car>& tollQueue, int cycle);
void runSimulation();
void display(deque<Car>& toll_queue);


int main() { 
	//Seed
	seedRandom();

	//& run simulation (all i need for main)
	runSimulation();

	return 0;
}

int randomNumber() {
	return rand() % 100 + 1; // random num between 1-100
}
void printDivider() {
	cout << "=============================================" << endl;
}
void seedRandom() {
	srand(static_cast<unsigned int>(time(0)));
}
void intializeQueue(deque<Car>& tollQueue, int initalSize) {
	//Simple for loop to intialize the deque with a specificed number of randomly generated cars/
	for (int i = 0; i < initalSize; i++) {
		Car car;
		tollQueue.push_back(car);
	}
}
void simulateCycle(deque<Car>& tollQueue, int cycle) {
	cout << endl;
	cout << "Time: " << cycle << " Operation: " << endl;

	//generate random number here 
	int randNum = randomNumber();

	// 55% probability: Car pays and leaves
	if (randNum <= PAY_PROB && !tollQueue.empty()) {
		Car car = tollQueue.front();
		tollQueue.pop_front();
		cout << "Car Paid: ";
		car.print();
	}
	else if(randNum > PAY_PROB && randNum <= PAY_PROB + JOIN_PROB) {
		Car newCar;
		tollQueue.push_back(newCar);
		cout << "Joined Lane:";
		newCar.print();
	}

	// 45% probability: New car joins the queue

	//display here 
	cout << "Queue:" << endl;
	display(tollQueue);
}
void runSimulation() {
	deque<Car> toll_queue;
	int cycle = 0;
	
	// Initialize the queue with the initial number of cars
	cout << "Initial Queue:" << endl;
	intializeQueue(toll_queue, QUEUE_SIZE);

		//then display
		display(toll_queue);

	//and finally, run simulation cycles until the queue is empty
		while (!toll_queue.empty()) {
			cycle++;
			simulateCycle(toll_queue, cycle);
		}

		cout << "This simulation ran " << cycle << " cycles until the queue was empty; your results will vary." << endl;
}
void display(deque<Car>& toll_queue) {
	//use auto to display toll_queue
	for (auto& car : toll_queue) {
		car.print();
	}
}