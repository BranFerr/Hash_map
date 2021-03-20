#include <iostream>
#include <fstream>
#include <map>
#include "OpenRecord.h"
using namespace std;

typedef map<string, OpenRecord> airportMap;

void doInputDataFromFile(airportMap& airplaneData)
{
    string filename = "air16.txt";
    ifstream infile(filename);
    OpenRecord r;
    int dataSize;

    if (!infile) {

        cout << "Unable to open file";
        exit(1);

    }//END IF

    //input.openFile(filename, File::openForRead, successful);

    if (infile.is_open()) {

        // The first item in the data file is an integer
        // it represents how many records are in the data file.

        infile >> dataSize;
        for (int j = 0; j < dataSize; j++) {
            infile >> r.code;
            infile >> r.name;
            infile >> r.city;
            infile >> r.country;
            infile >> r.latitudeDeg;
            infile >> r.latitudeMin;
            infile >> r.latitudeSec;
            infile >> r.latitudeDir;
            infile >> r.longitudeDeg;
            infile >> r.longitudeMin;
            infile >> r.longitudeSec;
            infile >> r.longitudeDir;
            infile >> r.altitude;

            airplaneData[r.code] = r;
        } // END FOR
        infile.close();

    } //END IF
} // doInputDataFromFile FUNCTION------------------------------------------------------------------------------------------------------------------------

void addRecord(OpenRecord& r) {

    cout << "input record data in following order: " << endl;
    cout << "(code, name, city, country, latitudeDegrees, latitudeMinutes, latitudeSeconds, ";
    cout << "latitudeDirection, longitudeDegrees, longitudeMinutes, longitudeSeconds, ";
    cout << "longitudeDirection, altitude)" << endl;
    cin>>r.code;
    cin>>r.name;
    cin>>r.city;
    cin>>r.country;
    cin>>r.latitudeDeg;
    cin>>r.latitudeMin;
    cin>>r.latitudeSec;
    cin>>r.latitudeDir;
    cin>>r.longitudeDeg;
    cin>>r.longitudeMin;
    cin>>r.longitudeSec;
    cin>>r.longitudeDir;
    cin>>r.altitude;

} // addRecord FUNCTION------------------------------------------------------------------------------------------------------------------------

void outputMap(airportMap map) {

    cout << "{" << endl;
    for (airportMap::iterator it = map.begin(); it != map.end(); ++it)
        cout << "(" << it->first << "," << it->second << ")" << endl;

    cout << "}" << endl;

}// outputMap FUNCTION------------------------------------------------------------------------------------------------------------------------

void mapSize(airportMap map) {

    cout << "Number of records in map: " << map.size() << endl;

}// mapSize FUNCTION------------------------------------------------------------------------------------------------------------------------

void recordCheck(string key, airportMap map) {

    if (map.count(key) > 0)
        cout << key << " has a record" << endl;
    else
        cout << key << " does not exist in current map" << endl;

}//recordCheck FUNCTION------------------------------------------------------------------------------------------------------------------------

void removeKey(string key, airportMap& map) {

    if (map.count(key) > 0)
        map.erase(key);
    else
        cout << key << " does not exist in current map" << endl;

}// removeKey FUNCTION------------------------------------------------------------------------------------------------------------------------

void recordSwap(string targetKey, OpenRecord newRec, airportMap& map) {

    if (map.count(targetKey) > 0) {
        removeKey(targetKey, map);
        map[newRec.code] = newRec;
    }//END IF

}// recordSwap FUNCTION------------------------------------------------------------------------------------------------------------------------

int main() {

    airportMap m1;
    OpenRecord rec;

    doInputDataFromFile(m1); // putting data into map and keys into sequence
    outputMap(m1); // outputing map (i)
    mapSize(m1); // oupting size (ii)
    recordCheck("YWG", m1); // checking for record/key existence (iii)
    recordCheck("CMB", m1); // checking for record/key existence (iv)
    removeKey("HND", m1); // removing record with key in map (v)
    mapSize(m1); // oupting size (vi)
    outputMap(m1); // outputing map after the remove (vii)
    addRecord(rec); // adding in record
    recordSwap("CFS", rec, m1); // swapping records (viii)
    outputMap(m1); // outputing map (ix)
    mapSize(m1); // oupting size (x)

    return 0;

}//END MAIN