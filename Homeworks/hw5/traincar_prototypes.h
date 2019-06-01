// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//                 This file is #include'd from traincar.h and main.cpp
//
// =======================================================================
//
// There are a number of additional functions used in main.cpp that
// you need to declare and implement.  Study main.cpp and the provided
// output to determine the arguments, return type, and overall
// behavior.
//
// Add all required additional function prototypes here
// (you may also add your own helper function prototypes here too)
//
// Implement these functions in "traincar.cpp"
//




#include <vector>
using namespace std;

// takes two new trainCar variables for the train and the car and adds the first car in the list to the beginning of the train and updates pointers accordingly
void AddCarFront(TrainCar *& train, TrainCar *& car);
// takes two new trainCar variables for the train and the car and adds the first car in the list to the end of the train and updates pointers accordingly
void AddCarBack(TrainCar *& train, TrainCar *& car);


// takes two new trainCar variables for the train and the car and pushes a new car onto the back of the train
void PushBack(TrainCar *& train, TrainCar * car);
// takes a trainCar and deletes all cars on the trainCar and deallocates all allocated memory
void DeleteAllCars(TrainCar *& train);


// takes in a trainCar and placeholder variables for the total weight, number of engines, number of freight cars, number of passenger cars, number of dining cars and number of sleeping cars and then calculates the values for the total weight, and number of each type of cars
void TotalWeightAndCountCars(const TrainCar * train, int & total_weight, int & num_engines, int & num_freight_cars, int & num_passenger_cars,
                             int & num_dining_cars, int & num_sleeping_cars);
// takes a trainCar and calculates the speed of the given train on a 2% incline
float CalculateSpeed(const TrainCar * train);
// takes a trainCar and then calculates and returns the average distance to the dining car
float AverageDistanceToDiningCar(const TrainCar * train);
// takes a train and returns the closest distance between an engine and any sleeping car
int ClosestEngineToSleeperCar(const TrainCar * train);


// returns a list of trains that carry all the freight on them after taking in the engines, freight cars, minimum speed of each train and the maximum number of cars each train can have
vector<TrainCar*> ShipFreight(TrainCar *& engines, TrainCar *& freight, float min_speed, int max_cars);


// takes a train and seperates it into two equally (almost) sized trains that each hold an engine
void Separate(TrainCar *& train, TrainCar *& a, TrainCar *& b);

