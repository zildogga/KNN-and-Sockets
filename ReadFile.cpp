#include "ReadFile.h"
// This is a method of the ReadFile class
vector<vector<string>> ReadFile::ReadCSVByPath(
        // This method takes a single argument:
        // - path: a string containing the path to the CSV file to be read
        string path
)
{
    // This line initializes an empty 2D vector of strings to store the data from the CSV file
    vector<vector<string>> result;
    // This line initializes an empty string to store each line from the CSV file
    string line;
    // This line initializes a new ifstream object using the path to the CSV file
    ifstream file(path);

    // This if block is executed if the CSV file was successfully opened
    if (file.is_open())
    {
        // This infinite loop reads the CSV file line by line
        while (getline(file, line))
        {
            // This line initializes a new stringstream object using the current line from the CSV file
            stringstream linestream(line);
            // This line initializes an empty string to store each comma-separated value from the line
            string data;
            // This line initializes an empty vector of strings to store the values from the current line
            vector<string> temp;
            // This infinite loop reads each comma-separated value from the current line
            while (getline(linestream, data, ','))
            {
                // This line adds the current value to the vector of values for the current line
                temp.push_back(data);
                // This line is commented out and was used for debugging purposes
                // cout << data << endl;
            }
            // This line adds the vector of values for the current line to the 2D vector of all values from the CSV file
            result.push_back(temp);
        }

        // This line closes the CSV file
        file.close();
    }
    else
    {
        // This line is executed if the CSV file could not be opened, and prints an error message
        cout << "Failed to open the file." << endl;
        return result;
    }

    // This line returns the 2D vector of values from the CSV file
    return result;
}

vector<vector<string>> ReadFile::ReadCSVByList(list<string> list) {
    // This line initializes an empty 2D vector of strings to store the data from the CSV file
    vector<vector<string>> result;
    // This line initializes an empty string to store each line from the CSV file
    string line;
    // This if block is executed if the CSV file was successfully opened
    if (!list.empty())
    {
        // This infinite loop reads the CSV file line by line
        for (const auto &line : list)
        {
            // This line initializes a new stringstream object using the current line from the CSV file
            stringstream linestream(line);
            // This line initializes an empty string to store each comma-separated value from the line
            string data;
            // This line initializes an empty vector of strings to store the values from the current line
            vector<string> temp;
            // This infinite loop reads each comma-separated value from the current line
            while (getline(linestream, data, ','))
            {
                // This line adds the current value to the vector of values for the current line
                temp.push_back(data);
                // This line is commented out and was used for debugging purposes
                // cout << data << endl;
            }
            // This line adds the vector of values for the current line to the 2D vector of all values from the CSV file
            result.push_back(temp);
        }
    }
    else
    {
        // This line is executed if the CSV file could not be opened, and prints an error message
        cout << "Failed to open the file." << endl;
        return result;
    }

    // This line returns the 2D vector of values from the CSV file
    return result;
}
