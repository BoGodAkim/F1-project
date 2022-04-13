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

// Date &Date::operator=(const Date &date)
// {
//     this->day = date.day;
//     this->month = date.month;
//     this->year = date.year;
//     return *this;
// }

void Date::display()
{
    if (this->day < 10)
        cout << "0";
    cout << this->day << ".";
    if (this->month < 10)
        cout << "0";
    cout << this->month << "." << this->year << endl;
}

Time::Time(string time)
{
    this->hour = stoi(time.substr(0, 2));
    this->minute = stoi(time.substr(3, 2));
    this->second = stoi(time.substr(6, 2));
}

void Time::display()
{
    if (this->hour < 10)
        cout << "0";
    cout << this->hour << ":";
    if (this->minute < 10)
        cout << "0";
    cout << this->minute << ":";
    if (this->second < 10)
        cout << "0";
    cout << this->second << endl;
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
        if (ID + 1 > this->constructors.size())
        {
            this->constructors.resize(ID + 1);
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
        if (ID + 1 > this->circuits.size())
        {
            this->circuits.resize(ID + 1);
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
        if (ID + 1 > this->drivers.size())
        {
            this->drivers.resize(ID + 1);
        }
        this->drivers[ID] = Driver(iss);
    }
    driversData.close();

    std::ifstream seasonsData("data/seasons.csv");
    getline(seasonsData, line);
    while (getline(seasonsData, line))
    {
        line.erase(remove(line.begin(), line.end(), '"'), line.end());
        istringstream iss(line);
        int ID;
        string ID_string;
        getline(iss, ID_string, ',');
        ID = stoi(ID_string) - 1950;
        if (ID + 1 > this->seasons.size())
        {
            this->seasons.resize(ID + 1);
        }
        this->seasons[ID] = Season(iss);
    }
    seasonsData.close();

    std::ifstream racesData("data/races.csv");
    getline(racesData, line);
    vector<int> raceID_to_year_and_round;
    while (getline(racesData, line))
    {
        line.erase(remove(line.begin(), line.end(), '"'), line.end());
        istringstream iss(line);
        int year;
        int round;
        int raceID;
        int circuitID;
        string raceID_string;
        string year_string;
        string round_string;
        string circuit_ID_string;
        getline(iss, raceID_string, ',');
        raceID = stoi(raceID_string);
        getline(iss, year_string, ',');
        year = stoi(year_string);
        getline(iss, round_string, ',');
        round = stoi(round_string);
        getline(iss, circuit_ID_string, ',');
        circuitID = stoi(circuit_ID_string);
        this->seasons[year - 1950].addRace(iss, round, &circuits[circuitID]);
        if (raceID + 1 > raceID_to_year_and_round.size())
        {
            raceID_to_year_and_round.resize(raceID + 1);
        }
        raceID_to_year_and_round[raceID] = year * 100 + round;
    }
    racesData.close();

    std::ifstream qualifyingData("data/qualifying.csv");
    getline(qualifyingData, line);
    while (getline(qualifyingData, line))
    {
        line.erase(remove(line.begin(), line.end(), '"'), line.end());
        istringstream iss(line);
        int raceID;
        int driverID;
        int constructorID;
        string raceID_string;
        string driverID_string;
        string constructorID_string;
        getline(iss, raceID_string, ',');
        raceID = stoi(raceID_string);
        getline(iss, driverID_string, ',');
        driverID = stoi(driverID_string);
        getline(iss, constructorID_string, ',');
        constructorID = stoi(constructorID_string);
        this->seasons[raceID_to_year_and_round[raceID] / 100 - 1950].addQualifying(iss, raceID_to_year_and_round[raceID] % 10, &drivers[driverID], &constructors[constructorID]);
    }
}

void Formula::display()
{
    cout << endl
         << "Constructors:" << endl
         << endl;
    for (int i = 1; i < this->constructors.size(); i++)
    {
        this->constructors[i].display();
    }
    cout << endl
         << "Circuits:" << endl
         << endl;
    for (int i = 1; i < this->circuits.size(); i++)
    {
        this->circuits[i].display();
    }
    cout << endl
         << "Drivers:" << endl
         << endl;
    for (int i = 1; i < this->drivers.size(); i++)
    {
        this->drivers[i].display();
    }
    cout << endl
         << "Seasons:" << endl
         << endl;
    for (int i = 0; i < this->seasons.size(); i++)
    {
        this->seasons[i].display();
    }
}

Season::Season(std::istringstream &iss)
{
    getline(iss, this->url, ',');
}

void Season::display()
{
    cout << "URL: " << this->url << endl
         << endl;
    for (int i = 1; i < this->races.size(); i++)
    {
        cout << "Race:" << i << endl;
        races[i].display();
    }
}

void Season::addRace(std::istringstream &iss, int round, Circuit *circuit)
{
    if (round + 1 > this->races.size())
    {
        this->races.resize(round + 1);
    }
    races[round] = Race(iss, circuit);
}

void Season::addQualifying(std::istringstream &iss, int round, Driver *driver, Constructor *constructor)
{
    races[round].addQualifying(iss, driver, constructor);
}

Race::Race(std::istringstream &iss, Circuit *circuit)
{
    string number;
    getline(iss, this->name, ',');
    getline(iss, number, ',');
    this->grand_prix_date = Date(number);
    getline(iss, number, ',');
    if (number != "\\N")
        this->grand_prix_time = new Time(number);
    else
        this->grand_prix_time = nullptr;
    getline(iss, this->url, ',');
    this->circuit = circuit;
    getline(iss, number, ',');
    if (number != "\\N")
        this->practice1_date = new Date(number);
    else
        this->practice1_date = nullptr;
    getline(iss, number, ',');
    if (number != "\\N")
        this->practice1_time = new Time(number);
    else
        this->practice1_time = nullptr;
    getline(iss, number, ',');
    if (number != "\\N")
        this->practice2_date = new Date(number);
    else
        this->practice2_date = nullptr;
    getline(iss, number, ',');
    if (number != "\\N")
        this->practice2_time = new Time(number);
    else
        this->practice2_time = nullptr;
    getline(iss, number, ',');
    if (number != "\\N")
        this->practice3_date = new Date(number);
    else
        this->practice3_date = nullptr;
    getline(iss, number, ',');
    if (number != "\\N")
        this->practice3_time = new Time(number);
    else
        this->practice3_time = nullptr;
    getline(iss, number, ',');
    if (number != "\\N")
        this->qualifying_date = new Date(number);
    else
        this->qualifying_date = nullptr;
    getline(iss, number, ',');
    if (number != "\\N")
        this->qualifying_time = new Time(number);
    else
        this->qualifying_time = nullptr;
    getline(iss, number, ',');
    if (number != "\\N")
        this->sprint_date = new Date(number);
    else
        this->sprint_date = nullptr;
    getline(iss, number, ',');
    if (number != "\\N")
        this->sprint_time = new Time(number);
    else
        this->sprint_time = nullptr;
}

void Race::addQualifying(std::istringstream &iss, Driver *driver, Constructor *constructor)
{

}

void Race::display()
{
    cout << "Name:" << name << endl
         << "Circuit:" << circuit << endl
         << "Date:";
    grand_prix_date.display();
    cout << "Time:";
    if (grand_prix_time != nullptr)
        grand_prix_time->display();
    else
        cout << "N/A";
    cout << endl
         << "URL: " << url << endl;
    cout << "Practice 1:" << endl
         << "Date:";
    if (practice1_date != nullptr)
    {
        practice1_date->display();
    }
    else
    {
        cout << "N/A" << endl;
    }
    cout << "Time:";
    if (practice1_time != nullptr)
        practice1_time->display();
    else
        cout << "N/A" << endl;
    cout << "Practice 2:" << endl
         << "Date:";
    if (practice2_date != nullptr)
    {
        practice2_date->display();
    }
    else
    {
        cout << "N/A" << endl;
    }
    cout << "Time:";
    if (practice2_time != nullptr)
    {
        practice2_time->display();
    }
    else
    {
        cout << "N/A" << endl;
    }
    cout << "Practice 3:" << endl
         << "Date:";
    if (practice3_date != nullptr)
    {
        practice3_date->display();
    }
    else
    {
        cout << "N/A" << endl;
    }
    cout << "Time:";
    if (practice3_time != nullptr)
    {
        practice3_time->display();
    }
    else
    {
        cout << "N/A" << endl;
    }
    cout << "Qualifying:" << endl
         << "Date:";
    if (qualifying_date != nullptr)
    {
        qualifying_date->display();
    }
    else
    {
        cout << "N/A" << endl;
    }
    cout << "Time:";
    if (qualifying_time != nullptr)
    {
        qualifying_time->display();
    }
    else
    {
        cout << "N/A" << endl;
    }
    cout << "Sprint:" << endl
         << "Date:";
    if (sprint_date != nullptr)
    {
        cout << "Date:";
        sprint_date->display();
    }
    else
    {
        cout << "N/A" << endl;
    }
    cout << "Time:";
    if (sprint_time != nullptr)
    {
        sprint_time->display();
    }
    else
    {
        cout << "N/A" << endl;
    }
    cout << endl;
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

// Driver &Driver::operator=(const Driver &driver)
// {
//     this->identifier = driver.identifier;
//     this->number = driver.number;
//     this->code = driver.code;
//     this->forname = driver.forname;
//     this->surname = driver.surname;
//     this->dateOfBirth = driver.dateOfBirth;
//     this->nationality = driver.nationality;
//     this->url = driver.url;
//     return *this;
// }

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

// Constructor &Constructor::operator=(const Constructor &constructor)
// {
//     this->identifier = constructor.identifier;
//     this->name = constructor.name;
//     this->nationality = constructor.nationality;
//     this->url = constructor.url;
//     return *this;
// }

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
    if (number == "\\N")
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

// Circuit &Circuit::operator=(const Circuit &circuit)
// {
//     this->identifier = circuit.identifier;
//     this->name = circuit.name;
//     this->location = circuit.location;
//     this->country = circuit.country;
//     this->latitude = circuit.latitude;
//     this->longitude = circuit.longitude;
//     this->altitude = circuit.altitude;
//     this->url = circuit.url;
//     return *this;
// }

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