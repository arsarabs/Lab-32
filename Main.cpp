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
int printDivider();
void seedRandom();
void intializeQueue(deque<Car>& tollQueue, int initalSize);
void simulateCycle(deque<Car>& tollQueue, int cycle);
void runSimulation();
void display(deque<Car>& toll_queue);


int main() {


	return 0;
}

int randomNumber() {
	return rand() % 100 + 1; // random num between 1-100
}
int printDivider() {
	cout << "=============================================" << endl;
}
void seedRandom() {
	srand(static_cast<unsigned int>(time(0)));
}
void intializeQueue(deque<Car>& tollQueue, int initalSize) {
	
}
void simulateCycle(deque<Car>& tollQueue, int cycle) {

}
void runSimulation() {

}
void display(deque<Car>& toll_queue) {

}