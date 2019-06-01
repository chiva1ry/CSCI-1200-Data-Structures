// =======================================================================
//
// IMPORTANT NOTE: You should edit this file
//
// =======================================================================

#include <iostream>
#include <iomanip>
#include <string>
#include <cassert>
#include <cmath>
#include <cstdlib>

#include "traincar.h"

// =======================================================================
// =======================================================================
//
//  HERE'S WHERE YOU SHOULD IMPLEMENT THE FUNCTIONS YOU PROTOTYPED IN
//  THE "traincar_prototypes.h" FILE.
//
// This helper function checks that the forward and backward pointers
// in a doubly-linked structure are correctly and consistently assigned.














// takes two new trainCar variables for the train and the car and adds the first car in the list to the beginning of the train and updates pointers accordingly
void AddCarFront(TrainCar *& train, TrainCar *& car) {
    if (car != NULL) {
    
        TrainCar* nxt = car->next;
        
        // If this is the first node, then we need to do things a bit differently
        if (train == NULL) {
            train = car;
            train->next = NULL;
            train->prev = NULL;
            
        } else {
            TrainCar* second = train;     // used to be the first car in the train, now it will be the second
            train = car;
            train->prev = NULL;
            train->next = second;
            
            if (second != NULL) {
                second->prev = train;
            }
        }
        
          // next car after the first one (which will be taken out)
        if (nxt != NULL) {
            nxt->prev = NULL;
            car = nxt;
            
        } else {car = NULL;}
    }
}


// takes two new trainCar variables for the train and the car and adds the first car in the list to the end of the train and updates pointers accordingly
void AddCarBack(TrainCar *& train, TrainCar *& car) {
    if (car != NULL) {
    
        // if this is the first car in the train, then same behavior as prepending the car
        if (train == NULL) {
            train = car;
            train->next = NULL;
            train->prev = NULL;
            
        } else {
            TrainCar* nxt = car->next;   // the car after the first car that will be taken out
            PushBack(train, car);
            
            if (nxt != NULL) {
                nxt->prev = NULL;
                car = nxt;
                
            } else {car = NULL;}
        }
    }
}


// takes two new trainCar variables for the train and the car and pushes a new car onto the back of the train
void PushBack(TrainCar *& train, TrainCar * car) {
    if (train == NULL) {
        train = car;
        train->next = NULL;
        train->prev = NULL;
        
    } else {
        TrainCar* last = train;
        while(last->next != NULL) {
            last = last->next;
        }
        
        last->next = car;
        last->next->next = NULL;
        last->next->prev = last;
    }
}


// takes, a trainCar, deletes all cars on the trainCar and deallocates all allocated memory
void DeleteAllCars(TrainCar *& train)
{
    if (train != NULL) {
        TrainCar* car = train;
        TrainCar* nxt = NULL;
        
        while(car != NULL) {
            nxt = car->next;
            delete car;
            car = nxt;
        }
    }
}


// takes in a trainCar and placeholder variables for the total weight, number of engines, number of freight cars, number of passenger cars, number of dining cars and number of sleeping cars and then calculates the values for the total weight, and number of each type of cars
void TotalWeightAndCountCars(const TrainCar * train, int & total_weight, int & num_engines, int & num_freight_cars, int & num_passenger_cars,
                             int &num_dining_cars, int & num_sleeping_cars) {
    total_weight = 0;
    num_engines = 0;
    num_freight_cars = 0;
    num_passenger_cars = 0;
    num_dining_cars = 0;
    num_sleeping_cars = 0;
    
    while(train != NULL) {
        total_weight += train->getWeight();
        if (train->isEngine()) {
            num_engines++;
        }
        else if (train->isFreightCar()) {
            num_freight_cars++;
        }
        else if (train->isPassengerCar()) {
            num_passenger_cars++;
        }
        else if (train->isDiningCar()) {
            num_dining_cars++;
        }
        else if (train->isSleepingCar()) {
            num_sleeping_cars++;
        }
        train = train->next;
    }
}


// takes a trainCar and calculates the speed of the given train on a 2% incline
float CalculateSpeed(const TrainCar * train)
{
    int horsepower = 0;
    int weight = 0;
    
    for(const TrainCar* car=train; car!=NULL; car=car->next) {
        if (car->isEngine()) {
            horsepower += 3000;
        }
        weight += car->getWeight();
    }
    return float(horsepower * 550 / 40) * 3600 / (5280 * weight);
}


// takes a trainCar and then calculates and returns the average distance to the dining car
float AverageDistanceToDiningCar(const TrainCar * train)
{
    int total_distance = 0;
    int num_passenger_cars = 0;
    int passenger_index = -1;
    
    int counter = 0;
    for(const TrainCar* a=train; a!=NULL; a=a->next) {
        // executes if this is a passenger car and calculates the distance to nearest dining car
        if (a->isPassengerCar()) {
            num_passenger_cars++;
            passenger_index = counter;
            int closest_distance = -1;
            int distance = 0;
            
            // iterates backwards to find dining car
            int back_counter = counter;
            for(const TrainCar* b=a; b!=train && b!=NULL && !b->isEngine(); b=b->prev) {
                if (b->isDiningCar()) {
                    distance = passenger_index - back_counter;
                    
                    if (closest_distance > distance || closest_distance == -1) {
                        closest_distance = distance;
                    }
                }
                back_counter--;
            }
            
            // iterates forward to find dining car
            int forward_counter = counter;
            for(const TrainCar* b=a; b!=train && b!=NULL && !b->isEngine(); b=b->next) {
                if (b->isDiningCar()) {
                    distance = forward_counter - passenger_index;
                    
                    if (closest_distance > distance || closest_distance == -1) {
                        closest_distance = distance;
                    }
                }
                forward_counter++;
            }
            
            // executes if the dining car is not found or blocked by an engine, then returns error code to signal that it is
            if (closest_distance <= 0) {
                return -1;
                
            // else, it adds it to the total distance
            } else {total_distance += closest_distance;}
        }
        counter++;
    }
    return (total_distance > 0 && num_passenger_cars > 0) ? (float)total_distance / num_passenger_cars : -1;
}


// takes a train and returns the closest distance between an engine and any sleeping car
int ClosestEngineToSleeperCar(const TrainCar * train) {
    int closest_distance = -1;
    int engine_location = -1;
    int sleeper_location = -1;
    
    int counter = 0;
    for(const TrainCar* car=train; car!=NULL; car=car->next) {
        if (car->isEngine()) {
            engine_location = counter;
            
        }
        else if (car->isSleepingCar()) {
            sleeper_location = counter;
        }
        
        if (engine_location >= 0 && sleeper_location >= 0 && engine_location != sleeper_location) {
            int distance = abs(engine_location - sleeper_location);
            if (distance < closest_distance || closest_distance == -1) {
                closest_distance = distance;
            }
        }
        counter++;
    }
    return closest_distance;
}


// returns a list of trains that carry all the freight on them after taking in the engines, freight cars, minimum speed of each train and the maximum number of cars each train can have
vector<TrainCar*> ShipFreight(TrainCar *& engines, TrainCar *& freight, float min_speed, int max_cars) {
    
    // returns an empty vector if any of the conditions are not possible
    if (engines == NULL || freight == NULL || min_speed <= 0 || max_cars <= 0) {
        return vector<TrainCar*> ();
    }
    
    // finds the weight each engine is able to carry
    float weight_per_engine = (3000 * 550) / (20 * 2);
    weight_per_engine *= 3600;
    weight_per_engine /= 5280;
    weight_per_engine /= min_speed;
    
    float total_weight = 0;
    for(const TrainCar* car=freight; car!=NULL; car=car->next)
        total_weight += car->getWeight();
    
    vector<TrainCar*> trains;
    // creates trains to hold the freight
    while(engines != NULL && freight != NULL) {
        
        TrainCar* current_train = NULL;
        float available_weight = (weight_per_engine - engines->getWeight());
        int current_length = 1;
        
        AddCarFront(current_train, engines);
        
        // adds the freight to the current train
        while(current_length < max_cars && freight != NULL) {
            
            // executes if the freight can be added to the train
            if (freight->getWeight() <= available_weight) {
                available_weight -= freight->getWeight();
                current_length++;
                AddCarBack(current_train, freight);
                
            } else {
                if (max_cars - current_length >= 2 && engines != NULL) {
                    current_length += 2;
                    available_weight += (weight_per_engine - freight->getWeight() - engines->getWeight());
                    AddCarFront(current_train, engines);
                    AddCarBack(current_train, freight);
                    
                // terminates loop and add this train
                } else {break;}
            }
        }
        
        // adds train to list of trains returned
        trains.push_back(current_train);
    }
    return trains;
}


// takes a train and seperates it into two equally (almost) sized trains that each hold an engine
void Separate(TrainCar *& train, TrainCar *& a, TrainCar *& b) {

    // finds the total number of cars in the train
    TrainCar* ptr;
    int train_length=0;
    for(ptr=train; ptr!=NULL; ptr=ptr->next) {
        train_length++;
    }
    
    
    // finds the middle value or the halfway point in the trainCar
    int midPoint = 0;
    if (train_length%2 == 0) {
        midPoint = train_length / 2;
        
    } else {
        midPoint = (train_length - 1) / 2;
    }
    
    int count=0;
    
    TrainCar* mid;              // keeps track of trainCar values in the midpoint
    TrainCar* temp_engine;      // stores the temporary value for an engine
    bool correct = false;    // flag to break outer loop, when the arranged order is correct
    
    // checking if the first half of the train has any engines and returning true if it does
    ptr = train;
    for(int i=0; i<midPoint; i++) {
        if (ptr != NULL && ptr->isEngine()) {
            count++;
        }
        ptr = ptr->next;
    }
    
    // assigning point for the middle car
    ptr = ptr->prev;
    mid = ptr;
    
    // function if only the second half of the train has engines
    if (count == 0) {
        
        ptr = ptr->next;
        if (ptr->isEngine() && ptr->next->isEngine()) {
            TrainCar* nxt = train->next;
            TrainCar* prev = train;
            count = 0;
            while(nxt != NULL) {
                count++;
                // executes when the midpoint of the trainCar is reached
                if (count >= midPoint + 1) {
                    // making the trainCar a
                    a = train;
                    prev->next = NULL;
                    
                    // making the trainCar b
                    b = nxt;
                    b->prev = NULL;
                    
                    // deleting the initial train and returning
                    train = NULL;
                    return;
                }
                // iterates to the next point on the trainCar
                prev = nxt;
                nxt = nxt->next;
            }
        }
        ptr = mid;
        
        // iterates starting from the middle of the train
        for(int i=0; i<midPoint-1; i++) {
            
            // function if an engine is found in the second half
            if (ptr->isEngine()) {
                temp_engine = ptr;
                
                // returns 1 position before the middle point
                while(ptr->next!=mid) {
                    ptr= ptr->prev;
                }
                
                // Unlink the engine
                temp_engine->prev->next = temp_engine->next;
                temp_engine->next->prev = temp_engine->prev;
                
                // Linking the engine in its new position
                temp_engine->next = ptr->next;
                ptr->next->prev = temp_engine;
                ptr->next = temp_engine;
                temp_engine->prev = ptr;
                
                // breaking out of both loop because the order is now correct
                correct = true;
                break;
            }
            // checks if the order is correct and breaks the outer loop if it is
            if (correct) {
                break;
            }
            // Otherwise keeps iterating to find the engine
            ptr = ptr->next;
        }
    
    // executes when the first half has atleast one engine
    }
    // function if the first half has both engines
    else if (count == 2) {
        ptr = mid;
        // iterates starting from the midpoint
        for(int i=0; i<midPoint-1; i++) {
            // locates the engine car in the first half
            if (ptr->isEngine()) {
                temp_engine = ptr;
                
                // moves the pointer to the middle of the train
                while(ptr!=mid) {
                    ptr= ptr->next;
                }
                
                // executes if the engine is not in the middle of the train
                if (temp_engine != mid) {
                    
                    // Unlink the engine
                    temp_engine->prev->next = temp_engine->next;
                    temp_engine->next->prev = temp_engine->prev;
                    
                    // Linking the engine in its new position
                    temp_engine->next = ptr->next;
                    ptr->next->prev = temp_engine;
                    ptr->next = temp_engine;
                    temp_engine->prev = ptr;
                        
                    // adjusting the mid if it has changed
                    ptr = train;
                    // moving ptr to mid
                    for(int j=0; j<midPoint-1; j++) {
                        ptr = ptr->next;
                    }
                    // adjusting the mid if it is not the same as ptr
                    if (ptr != mid) {
                        mid = ptr;
                        ptr->prev->next = ptr->next;
                        ptr->next->prev = ptr->prev;
                        ptr->next = ptr->next->next;
                        ptr->prev = ptr->next->prev;
                        ptr->prev->next = ptr;
                        ptr->next->prev = ptr;
                        mid = ptr->prev;
                    }
                    
                // executes if the engine is in the middle of the train
                } else {
                    temp_engine->next->prev = temp_engine->prev;
                    temp_engine->prev->next = temp_engine->next;
                    temp_engine->prev = ptr->next;
                    temp_engine->next = temp_engine->next->next;
                    temp_engine->prev->next->prev = temp_engine;
                    temp_engine->prev->next = temp_engine;
                    mid = temp_engine->prev;
                }
                correct = true;
            }
            // checks if the order is correct and breaks the outer loop if it is
            if (correct) {
                break;
            }
            // Otherwise keeps iterating backwards to find the engine
            ptr = ptr->prev;
        }
    }
    
    

    TrainCar* nxt = train->next;
    TrainCar* prev = train;
    count = 0;
    while(nxt != NULL) {
        count++;
        // executes when the midpoint of the trainCar is reached
        if (count >= midPoint) {
            // making the trainCar a
            a = train;
            prev->next = NULL;
            
            // making the trainCar b
            b = nxt;
            b->prev = NULL;
            
            // deleting the initial train and returning
            train = NULL;
            return;
        }
        // iterates to the next point on the trainCar
        prev = nxt;
        nxt = nxt->next;
    }

}
