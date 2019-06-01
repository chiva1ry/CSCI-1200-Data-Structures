#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>
#define earthRadiusKm 6371.0
using namespace std;

//TODO: You must fill in all ?????? with the correct types.
typedef long long int ID_TYPE; //Type for user IDs
typedef pair<float, float> COORD_TYPE; //Type for a coordinate (latitude and longitude)
typedef map<ID_TYPE, vector<ID_TYPE> > ADJ_TYPE; //Adjacency Lists type
typedef map<ID_TYPE, COORD_TYPE> GEO_TYPE; //Positional "dictionary"

//Function forward declarations. DO NOT CHANGE these. 
double deg2rad(double deg);
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d);
void loadConnections(ADJ_TYPE& adj_lists, std::ifstream& loadfile);
void loadLocations(GEO_TYPE& locations, std::ifstream& loadfile);
void printAllUsersWithinDistance(const GEO_TYPE& locations, std::ofstream& outfile,
                                 const ID_TYPE& start_id, double max_distance);
void printDegreesHistogram(const ADJ_TYPE& adj_lists, std::ofstream& outfile);
void printDegreesOfAll(const ADJ_TYPE& adj_lists, std::ofstream& outfile);
void printFriendsWithDegree(const ADJ_TYPE& adj_lists, std::ofstream& outfile,
                            const ID_TYPE& start_id, unsigned int degree);
void printFriendsWithinDistance(const ADJ_TYPE& adj_lists, const GEO_TYPE& locations, 
                                std::ofstream& outfile, const ID_TYPE& start_id, 
                                double max_distance);
void printUsersWithinIDRange(std::ofstream& outfile, ADJ_TYPE::const_iterator begin, 
                             ADJ_TYPE::const_iterator end, 
                             ADJ_TYPE::const_iterator start_it, unsigned int offset);


// DO NOT CHANGE THIS FUNCTION
int main(int argc, char** argv){
    ADJ_TYPE adj_lists;
    GEO_TYPE locations;

    if(argc != 3){
        std::cout << "Correct usage is " << argv[0]
                  << " [commands file] [output file]" << std::endl;
        return -1;
    }

    std::ifstream commands(argv[1]);
    if(!commands){
        std::cerr << "Problem opening " << argv[1] << " for reading!" 
                  << std::endl;
        return -1;
    }

    std::ofstream outfile(argv[2]);
    if(!outfile){
        std::cerr << "Problem opening " << argv[2] << " for writing!" 
                  << std::endl;
        return -1;
    }

    std::string token; //Read the next command
    while(commands >> token){
        if(token == "load-connections"){
            std::string filename;
            commands >> filename;

            std::ifstream loadfile(filename.c_str());
            if(!loadfile){
                std::cerr << "Problem opening " << filename 
                          << " for reading connections." << std::endl;
                return -1;
            }

            loadConnections(adj_lists, loadfile);
        }
        else if(token == "load-locations"){
            std::string filename;
            commands >> filename;

            std::ifstream loadfile(filename.c_str());
            if(!loadfile){
                std::cerr << "Problem opening " << filename 
                          << " for reading locations." << std::endl;
                return -1;
            }

            loadLocations(locations, loadfile);
        }
        else if(token == "print-degrees"){
            printDegreesOfAll(adj_lists, outfile);
        }
        else if(token == "print-degree-histogram"){
            printDegreesHistogram(adj_lists, outfile);
        }
        else if(token == "all-users-within-distance"){
            ID_TYPE start_id;
            double max_distance; //In kilometers
            commands >> start_id >> max_distance;

            printAllUsersWithinDistance(locations, outfile, start_id,
                                        max_distance);
        }
        else if(token == "friends-within-distance"){
            ID_TYPE start_id;
            double max_distance; //In kilometers
            commands >> start_id >> max_distance;

            printFriendsWithinDistance(adj_lists, locations, outfile,
                                       start_id, max_distance);
        }
        else if(token == "friends-with-degree"){
            ID_TYPE start_id,degree;
            commands >> start_id >> degree;

            printFriendsWithDegree(adj_lists, outfile, start_id, degree);
        }
        else if(token == "nodes-within-ID-range"){
            ID_TYPE start_id,offset;
            commands >> start_id >> offset;

            printUsersWithinIDRange(outfile, adj_lists.begin(), adj_lists.end(),
                                    adj_lists.find(start_id), offset);
        }
        else{
            std::cerr << "Unknown token \"" << token << "\"" << std::endl;
            return -1;
        }
    }
    
    return 0;
}




// This function converts decimal degrees to radians
// From https://stackoverflow.com/a/10205532
// DO NOT CHANGE THIS FUNCTION
double deg2rad(double deg) {
  return (deg * M_PI / 180);
}

/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * Taken from https://stackoverflow.com/a/10205532
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 * DO NOT CHANGE THIS FUNCTION
 */
double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

//////////////////TODO: IMPLEMENT ALL FUNCTIONS BELOW THIS POINT////////////////////

/**
 * Loads a list of connections in the format "a b" meaning b is a friend of a
 * into the adjacency lists data structure. a and b are IDs.
 * @param adj_lists Adjacency lists structure
 * @param loadfile File to read from
 */
void loadConnections(ADJ_TYPE& adj_lists, std::ifstream& loadfile){
    
    // create a vector to temporarily store values to be added to the adjacency lists and temporary values to store those values being read in from the input file
    vector<pair<ID_TYPE, ID_TYPE> > store;
    ID_TYPE token;
    ID_TYPE token2;
    
    // iterates through the connections list
    while(loadfile >> token) {
        loadfile >> token2;
        
        // storing pairs of all values from the inpit file with their matching values
        store.push_back(pair<ID_TYPE, ID_TYPE> (token, token2));
        
        // checks if the key is a unique key to add all unique keys to the adjacency list
        if (adj_lists.count(token) == 0) {
            
            // makes all keys associated initially with an empty value
            adj_lists[token];
        }
    }
    
    // iterates through the vector of values from the input list to add all the values to their associated keys
    for(int i = 0; i < store.size(); i++) {
        adj_lists[store[i].first].push_back(store[i].second);
    }
    
}

/**
 * Loads a list of locations in the format "id latitude longitude"
 * @param locations Location lookup table
 * @param loadfile File to read from
 */
void loadLocations(GEO_TYPE& locations, std::ifstream& loadfile){

    // creates temporary values to store both the values read in from the input file as well as a pair variable to help store the coordinates to be stored
    COORD_TYPE store;
    ID_TYPE token;
    
    // iterates through the loactions list and temporary stores variables for the key and the coordinates for that key
    while(loadfile >> token) {
        loadfile >> store.first;
        loadfile >> store.second;
        // creates a nes location on the map for each key and its associated values
        locations[token] = store;
    }
    
}

/**
 * Prints all users within a certain distance of a particular user.
 * Sorted from shortest distance to user to longest distance to user.
 * Rounds down to the next lowest km if the difference is a decimal
 * @param locations Location lookup table
 * @param outfile File to write output to
 * @param start_id User we are using as our "origin" (i.e. 0 distance)
 * @param max_distance Maximum distance from start_id that a printed user can be
 */
void printAllUsersWithinDistance(const GEO_TYPE& locations, std::ofstream& outfile,
                                 const ID_TYPE& start_id, double max_distance){
    
    // checks if there is a location in the locations list with the entered ID and ends the function if there is not
    if (locations.count(start_id) == 0) {
        outfile << "User ID " << start_id << " does not have a recorded location." << endl;
        return;
    }

    // creates a temporary vector variable to store the distances from each ID number if they are closer then the maximum allowed distance
    vector<pair<int, ID_TYPE>> store;
    
    // iterates through the map of locations
    for (GEO_TYPE::const_iterator it=locations.begin(); it!=locations.end(); it++) {
        
        // calculates the distance from the value at the start ID
        int distance = distanceEarth(it->second.first, it->second.second, locations.at(start_id).first, locations.at(start_id).second);
        
        // adds the distance and its ID to the temporary vector if they are within the maximum distance
        if(it->first != start_id && distance < max_distance) {
            store.push_back(pair<int, ID_TYPE> (distance, it->first));
        }
    }
    
    // sorts the vector in order of ascending distance
    sort(store.begin(), store.end());
    
    // checks if there are any IDs within the entered distance and if there are none, returns an output
    if(store.size() > 0) {
        
        // prints heading
        outfile << "User IDs within " << max_distance << " km of user " << start_id << ':' << endl;
        // prints first value in the vector
        outfile << ' ' << store[0].first << " km: " << store[0].second << flush;
        // iterates through the vector and prints the remaining values
        for(int i = 1; i < store.size(); i++) {
            
            // checks if the distance of one ID is the same as the one before and adds a new line if it is different
            if(store[i].first == store[i - 1].first) {
                outfile << ' ' << store[i].second << flush;
            } else {
                outfile << endl << ' ' << store[i].first << " km: " << store[i].second << flush;
            }
        }
    } else {
        outfile << "There are no users within " << max_distance << " km of user " << start_id << flush;
    }
    
    outfile << endl;
    
}

/**
 * Prints a sorted list of degrees (smallest to largest) along with how many users
 * have that degree. Only prints for degree >=1.
 * @param adj_lists Adjacency lists structure
 * @param outfile File to write output to
 */
void printDegreesHistogram(const ADJ_TYPE& adj_lists, std::ofstream& outfile){

    // prints heading
    outfile << "Histogram for " << adj_lists.size() << " users:" << endl;
    
    // creates a temporary map of the number of degrees of different vkeys in the adjacency list and the number of times these different degrees take place
    map<int, int> degrees;
    
    // iterates through the adjacency list
    for (ADJ_TYPE::const_iterator it=adj_lists.begin(); it!=adj_lists.end(); it++) {
        
        // checks if this degree already exists in the map and adds it to the map if it does not or increases the vlaue associated with the degree if it does
        if (degrees.count((int)it->second.size()) > 0) {
            degrees[(int)it->second.size()]++;
        } else {
            degrees[(int)it->second.size()] = 1;
        }
    }
    
    // iterates through the map of degrees and prints out each of them with the number of times they appear
    for (map<int,int>::const_iterator it=degrees.begin(); it!=degrees.end(); it++) {
        outfile << " Degree " << it->first << ": " << it->second << endl;
    }
    
}

/**
 * Prints a sorted list of user IDs (smallest to largest) along with the degree for
 * each user. Only prints for degree >=1.
 * @param adj_lists Adjacency lists structure
 * @param outfile File to write output to
 */
void printDegreesOfAll(const ADJ_TYPE& adj_lists, std::ofstream& outfile){

    // prints heading
    outfile << "Degrees for " << adj_lists.size() << " users:" << endl;
    
    // iterates through the adjacency list and prints the degree of each value
    for (ADJ_TYPE::const_iterator it=adj_lists.begin(); it!=adj_lists.end(); it++) {
        outfile << ' ' << it->first << ": Degree " << it->second.size() << endl;
    }
    
}

/**
 * Prints all friends of a particular user who have a particular degree.
 * Sorted by user ID (from smallest to largest).
 * @param adj_lists Adjacency lists structure
 * @param outfile File to write output to
 * @param start_id User whose friends we are looking at
 * @param degree The degree of friends we want to print. Will be >=1.
 */
void printFriendsWithDegree(const ADJ_TYPE& adj_lists, std::ofstream& outfile,
                            const ID_TYPE& start_id, unsigned int degree){

    // checks if there is an ID in the adjacency list with the entered ID and ends the function if there is not
    if (adj_lists.count(start_id) == 0) {
        outfile << "There is no user with friends and ID " << start_id << endl;
        return;
    }
    
    // creates a vector of ID type to temporarily store the values of those IDs that have the same degrees values
    vector<ID_TYPE> store;
    
    // iterates through all the friends of the entered ID
    int forcount = (int)adj_lists.at(start_id).size();
    for(int i = 0; i < forcount; i++) {
        
        // moves on to the next value in the friends list if the value at this point is not one of the keys in the adjacency list
        if (adj_lists.count(adj_lists.at(start_id)[i]) == 0) {
            continue;
        }
        
        // checks if the degree value of this friend and the intended degree value are equal and adds the ID to the temporary vector if they are
        if (adj_lists.at(adj_lists.at(start_id)[i]).size() == degree) {
            store.push_back(adj_lists.at(start_id)[i]);
        }
    }
    
    // prints header
    outfile << "User " << start_id << " has " << store.size() << " friend(s) with degree " << degree << flush;
    // checks if there are any IDs with the same degree
    if(store.size() > 0) {
        outfile << ':' << flush;
        // iterates through the temporary vector to print out all those values that have the same degree
        for(int i = 0; i < store.size(); i++) {
            outfile << ' ' << store[i] << flush;
        }
    }
    
    outfile << endl;
    
}

/**
 * Prints friends of a particular user within a certain distance of that user.
 * Sorted from shortest distance to user to longest distance to user.
 * @param adj_lists Adjacency lists structure
 * @param locations Location lookup table
 * @param outfile File to write output to
 * @param start_id User we are using as our "origin" (i.e. 0 distance)
 * @param max_distance Maximum distance from start_id that a printed user can be
 */
void printFriendsWithinDistance(const ADJ_TYPE& adj_lists, const GEO_TYPE& locations, 
                                std::ofstream& outfile, const ID_TYPE& start_id, 
                                double max_distance){
    
    // checks if there is an ID in the adjacency list with the entered ID and ends the function if there is not
    if (adj_lists.count(start_id) == 0) {
        outfile << "There is no user with friends and ID " << start_id << endl;
        return;
    }
    
    // checks if there is the ID is in the locations list and ends the function if it is not
    if (locations.count(start_id) == 0) {
        outfile << "User ID " << start_id << " does not have a recorded location." << endl;
        return;
    }

    // creates a temporary vector variable to store the distances from each ID number if they are closer then the maximum allowed distance
    vector<pair<float, ID_TYPE>> store;
    
    // iterates through all the friends of the entered ID
    int forcount = (int)adj_lists.at(start_id).size();
    for(int i = 0; i < forcount; i++) {
        
        // moves on to the next value in the friends list if the value at this point does not have a stored location
        if (locations.count(adj_lists.at(start_id)[i]) == 0) {
            continue;
        }
        
        // calculates the distance from the value at the start ID
        float distance = distanceEarth(locations.at(adj_lists.at(start_id)[i]).first, locations.at(adj_lists.at(start_id)[i]).second, locations.at(start_id).first, locations.at(start_id).second);
        
        // adds the distance and its ID to the temporary vector if they are within the maximum distance
        if(distance < max_distance) {
            store.push_back(pair<float, ID_TYPE> (distance, adj_lists.at(start_id)[i]));
        }
    }
    
    // sorts the vector in order of ascending distance
    sort(store.begin(), store.end());
    
    // checks if there are any IDs within the entered distance and if there are none, returns an output
    if(store.size() > 0) {
        
        // prints heading
        outfile << "Friends within " << max_distance << " km of user " << start_id << ':' << endl;
        // prints first value in the vector
        outfile << ' ' << store[0].first << " km: " << store[0].second << flush;
        // iterates through the vector and prints the remaining values
        for(int i = 1; i < store.size(); i++) {
            
            // checks if this degree already exists in the map and adds it to the map if it does not or increases the vlaue associated with the degree if it does
            if(store[i].first == store[i - 1].first) {
                outfile << ' ' << store[i].second << flush;
            } else {
                outfile << endl << ' ' << store[i].first << " km: " << store[i].second << flush;
            }
        }
    } else {
        outfile << "There are no friends within " << max_distance << " km of user " << start_id << flush;
    }
    
    outfile << endl;
    
}

/**
 * Prints users with an ID that is "close" to a particular user's ID.
 * Sorted from smallest to largest user ID.
 * Only prints for degree >=1.
 *
 * If there are M IDs that should be printed this function should only use
 * ADJ_TYPE::const_iterator::operator++ / ADJ_TYPE::const_iterator::operator-- O(M) times
 *
 * @param outfile File to write output to
 * @param begin The .begin() iterator for the adjacency lists structure
 * @param end The .end() iterator for the adjacency lists structure
 * @param start_it Iterator for user we are using as our baseline (i.e. 0 diifference)
 *        It is possible that the start_it was not found in the data.
 * @param offset Maximum absolute difference from start_id that a printed user's
 *               ID can have
 */
void printUsersWithinIDRange(std::ofstream& outfile, ADJ_TYPE::const_iterator begin, 
                             ADJ_TYPE::const_iterator end, 
                             ADJ_TYPE::const_iterator start_it, unsigned int offset){

    // creates a boolean to check if the entered ID actually exists
    bool id_present = false;
    // creates a vector of ID type to temporarily store the values of those IDs that have the IDs within the range
    vector<ID_TYPE> store;
    
    // iterates through the values in the adjacency list
    for (ADJ_TYPE::const_iterator it=begin; it!=end; it++) {
        
        // checks if the value is equal to the entered value and changes the boolean to true it it is
        if(start_it->first == it->first) {
            id_present = true;
        }
        
        // checks if the value of the ID is within the range entered into the function
        if(start_it->first != it->first && start_it->first + offset >= it->first && start_it->first - offset <= it->first) {
            store.push_back(it->first);
        }
    }
    
    // checks if the ID exists has values within the range
    if(id_present && store.size() > 0) {
        
        // prints heading
        outfile << "Users with an ID within +/-" << offset << " of " << start_it->first << ":" << flush;
        // iterates through the IDs in the range and prints them out
        for(int i = 0; i < store.size(); i++) {
            outfile << ' ' << store[i] << flush;
        }
    // checks if the ID exists and returns a different statement if it does not
    } else if(id_present) {
        outfile << "There are no users with an ID within +/-" << offset << " of " << start_it->first << flush;
    } else {
        outfile << "There is no user with the requested ID" << flush;
    }
    
    outfile << endl;
    
}
