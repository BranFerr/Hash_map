#include<string>
#include<iostream>
using namespace std;


class OpenRecord {
public:
    string code;
    string name;
    string city;
    string country;
    int latitudeDeg, latitudeMin, latitudeSec;
    string latitudeDir;
    int longitudeDeg, longitudeMin, longitudeSec;
    string longitudeDir;
    int altitude;

    OpenRecord() {}
    ~OpenRecord() {}

    void clear(void)
    {
        code = "";
        name = "";
        city = "";
        country = "";
        latitudeDeg = 0;
        latitudeMin = 0;
        latitudeSec = 0;
        latitudeDir = "";
        longitudeDeg = 0;
        longitudeMin = 0;
        longitudeSec = 0;
        longitudeDir = "";
        altitude = 0;

    } // clear FUNCTION------------------------------------------------------------------------------------------------------------------------

    OpenRecord& operator = (OpenRecord& rhs)
    {
        code = rhs.code;
        name = rhs.name;
        city = rhs.city;
        country = rhs.country;
        latitudeDeg = rhs.latitudeDeg;
        latitudeMin = rhs.latitudeMin;
        latitudeSec = rhs.latitudeSec;
        latitudeDir = rhs.latitudeDir;
        longitudeDeg = rhs.longitudeDeg;
        longitudeMin = rhs.longitudeMin;
        longitudeSec = rhs.longitudeSec;
        longitudeDir = rhs.longitudeDir;
        altitude = rhs.altitude;

        return *this;

    } // operator = FUNCTION------------------------------------------------------------------------------------------------------------------------

    void transferFrom(OpenRecord& source)
    {
        code = source.code;
        name = source.name;
        city = source.city;
        country = source.country;
        latitudeDeg = source.latitudeDeg;
        latitudeMin = source.latitudeMin;
        latitudeSec = source.latitudeSec;
        latitudeDir = source.latitudeDir;
        longitudeDeg = source.longitudeDeg;
        longitudeMin = source.longitudeMin;
        longitudeSec = source.longitudeSec;
        longitudeDir = source.longitudeDir;
        altitude = source.altitude;
        source.clear();

    } // transferFrom FUNCTION------------------------------------------------------------------------------------------------------------------------

    friend ostream& operator << (ostream& os, OpenRecord& r)
    {
        os << "(" << r.code << "," << r.name << "," << r.city << "," << r.country <<
            "," << r.latitudeDeg << "," << r.latitudeMin << "," << r.latitudeSec << "," << r.latitudeDir <<
            "," << r.longitudeDeg << "," << r.longitudeMin << "," << r.longitudeSec << "," << r.longitudeDir <<
            "," << r.altitude << ")";
        return os;
    } // operator << FUNCTION------------------------------------------------------------------------------------------------------------------------

};//END CLASS