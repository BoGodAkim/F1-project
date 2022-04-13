#include <bits/stdc++.h>
#include "classes.hpp"
//#include "classes.cpp"
using namespace std;

Date::Date(int day, int month, int year)
{
    this->day = day;
    this->month = month;
    this->year = year;
}

Date::Date(string date)
{
    this->day = stoi(date.substr(8, 2));
    this->month = stoi(date.substr(5, 2));
    this->year = stoi(date.substr(0, 4));
}

Date::Date(const Date &date)
{
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
}

Date &Date::operator=(const Date &date)
{
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
    return *this;
}

void Date::display()
{
    if (this->day < 10)
        cout << "0";
    cout << this->day << ".";
    if (this->month < 10)
        cout << "0";
    cout << this->month << "." << this->year << endl;
}

Formula::Formula()
{
    std::ifstream constructorsData("data/constructors.csv");
    string line;
    getline(constructorsData, line);
    while (getline(constructorsData, line))
    {
        line.erase(remove(line.begin(), line.end(), '"'), line.end());
        istringstream iss(line);
        int ID;
        string ID_string;
        getline(iss, ID_string, ',');
        ID = stoi(ID_string);
        if (ID + 1 > constructors.size())
        {
            constructors.resize(ID + 1);
        }
        this->constructors[ID] = Constructor(iss);
    }
    constructorsData.close();

    std::ifstream circuitsData("data/circuits.csv");
    getline(circuitsData, line);
    while (getline(circuitsData, line))
    {
        line.erase(remove(line.begin(), line.end(), '"'), line.end());
        istringstream iss(line);
        int ID;
        string ID_string;
        getline(iss, ID_string, ',');
        ID = stoi(ID_string);
        if (ID + 1 > circuits.size())
        {
            circuits.resize(ID + 1);
        }
        this->circuits[ID] = Circuit(iss);
    }
    circuitsData.close();

    std::ifstream driversData("data/drivers.csv");
    getline(driversData, line);
    while (getline(driversData, line))
    {
        line.erase(remove(line.begin(), line.end(), '"'), line.end());
        istringstream iss(line);
        int ID;
        string ID_string;
        getline(iss, ID_string, ',');
        ID = stoi(ID_string);
        if (ID + 1 > drivers.size())
        {
            drivers.resize(ID + 1);
        }
        this->drivers[ID] = Driver(iss);
    }
    driversData.close();
}

void Formula::display()
{
    cout << endl
         << "Constructors:" << endl
         <<endl;
    for (int i = 1; i < constructors.size(); i++)
    {
        constructors[i].display();
    }
    cout << endl
         << "Circuits:" << endl
         <<endl;
    for (int i = 1; i < circuits.size(); i++)
    {
        circuits[i].display();
    }
    cout << endl
         << "Drivers:" << endl
         <<endl;
    for (int i = 1; i < drivers.size(); i++)
    {
        drivers[i].display();
    }
}

Driver::Driver(std::string indefier, int number, std::string code, std::string forname, std::string surname, Date dateOfBirth, std::string nationality, std::string url)
{
    this->identifier = indefier;
    this->number = number;
    this->code = code;
    this->forname = forname;
    this->surname = surname;
    this->dateOfBirth = dateOfBirth;
    this->nationality = nationality;
    this->url = url;
}

Driver::Driver(std::string line)
{
    istringstream iss(line);
    string number;
    getline(iss, this->identifier, ',');
    getline(iss, number, ',');
    if(number == "\\N")
        this->number = -1;
    else
        this->number = stoi(number);
    getline(iss, this->code, ',');
    getline(iss, this->forname, ',');
    getline(iss, this->surname, ',');
    getline(iss, number, ',');
    this->dateOfBirth = Date(number);
    getline(iss, this->nationality, ',');
    getline(iss, url, ',');
}

Driver::Driver(std::istringstream &iss)
{
    string number;
    getline(iss, this->identifier, ',');
    getline(iss, number, ',');
    if (number == "\\N")
        this->number = -1;
    else
        this->number = stoi(number);
    getline(iss, this->code, ',');
    getline(iss, this->forname, ',');
    getline(iss, this->surname, ',');
    getline(iss, number, ',');
    this->dateOfBirth = Date(number);
    getline(iss, this->nationality, ',');
    getline(iss, url, ',');
}

Driver &Driver::operator=(const Driver &driver)
{
    this->identifier = driver.identifier;
    this->number = driver.number;
    this->code = driver.code;
    this->forname = driver.forname;
    this->surname = driver.surname;
    this->dateOfBirth = driver.dateOfBirth;
    this->nationality = driver.nationality;
    this->url = driver.url;
    return *this;
}

void Driver::display()
{
    cout << "Identifier:" << this->identifier << endl
         << "Number:" << this->number << endl
         << "Code:" << this->code << endl
         << "Forname:" << this->forname << endl
         << "Surname:" << this->surname << endl
         << "Date of birth:";
    this->dateOfBirth.display();
    cout << "Nationality:" << this->nationality << endl
         << "URL:" << this->url << endl
         << endl;
}

Constructor::Constructor(std::string identifier, std::string name, std::string nationality, std::string url)
{
    this->identifier = identifier;
    this->name = name;
    this->nationality = nationality;
    this->url = url;
}

Constructor::Constructor(std::string line)
{
    istringstream iss(line);
    getline(iss, this->identifier, ',');
    getline(iss, this->name, ',');
    getline(iss, this->nationality, ',');
    getline(iss, this->url, ',');
}

Constructor::Constructor(std::istringstream &iss)
{
    getline(iss, this->identifier, ',');
    getline(iss, this->name, ',');
    getline(iss, this->nationality, ',');
    getline(iss, this->url, ',');
}

Constructor &Constructor::operator=(const Constructor &constructor)
{
    this->identifier = constructor.identifier;
    this->name = constructor.name;
    this->nationality = constructor.nationality;
    this->url = constructor.url;
    return *this;
}

void Constructor::display()
{
    cout << "Identifier:" << this->identifier << endl
         << "Name:" << this->name << endl
         << "Nationality:" << this->nationality << endl
         << "URL:" << this->url << endl
         << endl;
}

Circuit::Circuit(std::string identifier, std::string name, std::string location, std::string country, float latitude, float longitude, int altitude, std::string url)
{
    this->identifier = identifier;
    this->name = name;
    this->location = location;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
    this->altitude = altitude;
    this->url = url;
}

Circuit::Circuit(std::string line)
{
    istringstream iss(line);
    string number;
    getline(iss, this->identifier, ',');
    getline(iss, this->name, ',');
    getline(iss, this->location, ',');
    getline(iss, this->country, ',');
    getline(iss, number, ',');
    this->latitude = stof(number);
    getline(iss, number, ',');
    this->longitude = stof(number);
    getline(iss, number, ',');
    if(number == "\\N")
        this->altitude = -1;
    else
        this->altitude = stoi(number);
    getline(iss, this->url, ',');
}

Circuit::Circuit(std::istringstream &iss)
{
    string number;
    getline(iss, this->identifier, ',');
    getline(iss, this->name, ',');
    getline(iss, this->location, ',');
    getline(iss, this->country, ',');
    getline(iss, number, ',');
    this->latitude = stof(number);
    getline(iss, number, ',');
    this->longitude = stof(number);
    getline(iss, number, ',');
    if (number == "\\N")
        this->altitude = -1;
    else
        this->altitude = stoi(number);
    getline(iss, this->url, ',');
}

Circuit &Circuit::operator=(const Circuit &circuit)
{
    this->identifier = circuit.identifier;
    this->name = circuit.name;
    this->location = circuit.location;
    this->country = circuit.country;
    this->latitude = circuit.latitude;
    this->longitude = circuit.longitude;
    this->altitude = circuit.altitude;
    this->url = circuit.url;
    return *this;
}

void Circuit::display()
{
    cout << "Identifier:" << this->identifier << endl
         << "Name:" << this->name << endl
         << "Location:" << this->location << endl
         << "Country:" << this->country << endl
         << "Latitude:" << this->latitude << endl
         << "Longitude:" << this->longitude << endl
         << "Altitude:" << this->altitude << endl
         << "URL:" << this->url << endl
         << endl;
}

void init_status()
{
    ifstream status_data("data/status.csv");
    string line;
    getline(status_data, line);
    while (getline(status_data, line))
    {
        line.erase(remove(line.begin(), line.end(), '"'), line.end());
        istringstream iss(line);
        int ID;
        string ID_string;
        string status_read;
        getline(iss, ID_string, ',');
        ID = stoi(ID_string);
        getline(iss, status_read, ',');
        if (ID + 1 > status.size())
        {
            status.resize(ID + 1);
        }
        status[ID] = status_read;
    }
    status_data.close();
}

int main()
{
    init_status();
    Formula formula1;
    formula1.display();
    return 0;
}