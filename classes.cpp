void init_status()
{
    ifstream status_data("data/status.csv");
    string line;
    getline(status_data, line);
    while (getline(status_data, line))
    {
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
}