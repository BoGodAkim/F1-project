#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <bits/stdc++.h>

// TODO: Think about standings

class Formula;
class Driver;
class Constructor;
class Circuit;
class Season;
class Race;
class DriverRaceData;
class Lap;
class PitStop;
class Qualifying;
class Result;
class Time;
class Date;

std::vector<std::string> status;

void init_status();

class Date
{
private:
    int day;
    int month;
    int year;

public:
    Date() = default;
    Date(int day, int month, int year);
    Date(std::string date);
    Date(const Date &date);
    Date &operator=(const Date &date);
    void display();
};

class Time
{
    int hour;
    int minute;
    int second;
};

class Result
{
    int number;
    int grid;
    int position;
    std::string positionText;
    int positionOrder;
    float points;
    int laps;
    Time time;
    int milliseconds;
    int fastestLap;
    int rank;
    Time fastestLapTime;
    float fastestLapSpeed;
    std::string *status;
};

class Qualifying
{
    int position;
    std::string *time_q1; // NOTE: MAY BE Pointer to Time
    std::string *time_q2;
    std::string *time_q3;
};

class Leaderboard
{
    // NOTE: May be abstract class
    // TODO: Implement Leaderboard class
};

class PitStop // NOTE: Where save data (in lap) or make global
{
    int stop;
    std::string time;
    std::string duration;
    int milliseconds;
};

class Lap
{
    int lap_number;
    int position;
    PitStop *pit_stop = nullptr;
    int milliseconds;
    Time time;
};

class DriverRaceData // NOTE: Maybe stor this data in class result не надо(Федя)
{
    Driver *driver;
    Constructor *constructor;
    Qualifying qualifying;
    Result *sprint;
    Result result;
    std::vector<Lap> laps;
    std::vector<PitStop> pit_stops;
};

class Race
{
    Circuit *circuit;
    int round; // NOTE: Need?
    std::string name;
    Date gp_date;
    Time gp_time; // NOTE:
    std::string url;
    Date practice1_date; // NOTE: MAY BE Pointer to Time and Date
    Date practice2_date;
    Date practice3_date;
    Time practice1_time;
    Time practice2_time;
    Time practice3_time;
    Date qualifying_date;
    Time qualifying_time;
    Date sprint_date;
    Time sprint_time;
    std::vector<DriverRaceData> data;
    Leaderboard driversLeaderboard;
    Leaderboard constructorsLeaderboard;
    Leaderboard seasonDriversLeaderboard;
    Leaderboard seasonConstructorsLeaderboard;
    // NOTE: MAYBE Start grid
};

class Season
{
    std::vector<Race> races;
    Leaderboard driversLeaderboard;
    Leaderboard constructorsLeaderboard;
    std::string url;
};

class Constructor
{
private:
    std::string identifier;
    std::string nationality;
    std::string url;
    std::string name;
    // NOTE: Add informations about wins
public:
    Constructor() = default;
    Constructor(std::string identifier, std::string name, std::string nationality, std::string url);
    Constructor(std::string line);
    Constructor(std::istringstream& iis);
    Constructor &operator=(const Constructor &constructor);
    void display();
};

class Circuit
{
private:
    std::string identifier;
    std::string name;
    std::string location;
    std::string country;
    float latitude;
    float longitude;
    int altitude;
    std::string url;

public:
    Circuit() = default;
    Circuit(std::string identifier, std::string name, std::string location, std::string country, float latitude, float longitude, int altitude, std::string url);
    Circuit(std::string line);
    Circuit(std::istringstream &iis);
    Circuit &operator=(const Circuit &circuit);
    void display();
};

class Driver
{
private:
    std::string identifier;
    int number; // NOTE: Fix Null
    std::string code;
    std::string forname;
    std::string surname;
    Date dateOfBirth;
    std::string nationality;
    std::string url;
    // NOTE: Add informations about wins
public:
    Driver() = default;
    Driver(std::string indefier, int number, std::string code, std::string forname, std::string surname, Date dateOfBirth, std::string nationality, std::string url);
    Driver(std::string line);
    Driver(std::istringstream &iss);
    Driver &operator=(const Driver &driver);
    void display();
};

class Formula
{
private:
    std::vector<Season> seasons;
    std::vector<Constructor> constructors;
    std::vector<Circuit> circuits;
    std::vector<Driver> drivers;
    std::string url = "https://en.wikipedia.org/wiki/Formula_One";

public:
    Formula();
    void display();
};

#endif // CLASSES_HPP