#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <bits/stdc++.h>

//TODO: Think about standings

std::vector<std::string> status;

class Date
{
    int day;
    int month;
    int year;
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
    std::string time_q1;//NOTE: MAY BE Pointer to Time
    std::string time_q2;
    std::string time_q3;
};

class Leaderboard
{
    // NOTE: May be abstract class
    // TODO: Implement Leaderboard class
};

class PitStop //NOTE: Where save data (in lap) or make global  
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
    std::string time;
};

class DriverRaceData //NOTE: Maybe stor this data in class result 
{
    Driver *driver;
    Constructor *constructor;
    Qualifying qualifying;
    Result *sprint;
    Result *result;
    std::vector<Lap> laps;
};

class Race
{
    Circuit *circuit;
    int round; // NOTE: Need?
    std::string name;
    Date date;
    Time time;
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
    //NOTE: MAYBE Start grid
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
    std::string identifier;
    std::string name;
    std::string nationality;
    std::string url;
    //NOTE: Add informations about wins
};

class Circuit
{
    std::string identifier;
    std::string name;
    std::string location;
    std::string country;
    float latitude;
    float longitude;
    int altitude;
    std::string url;
};

class Driver
{
    std::string identifier;
    int number; // NOTE: Fix Null
    std::string code;
    std::string forname;
    std::string surname;
    Date dateOfDeath;
    std::string nationality;
    std::string url;
    //NOTE: Add informations about wins
};

class Formula
{
    std::vector<Season> seasons;
    std::vector<Constructor> constructors;
    std::vector<Circuit> circuits;
    std::vector<Driver> drivers;
    std::string url = "https://en.wikipedia.org/wiki/Formula_One";
};

#endif // CLASSES_HPP