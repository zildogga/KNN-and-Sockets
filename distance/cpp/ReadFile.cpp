//
// Created by Omer on 11/12/2022.
//

#include "distance/h/ReadFile.h"
vector<vector<string>> ReadFile::ReadCSVByPath(string path)
{
    vector<vector<string>> result;
    string line;
    ifstream file(path);

    // Check if the file was successfully opened
    if (file.is_open())
    {
        // Read the file line by line
        while (getline(file, line))
        {
            stringstream linestream(line);
            string data;
            vector<string> temp;
            // Read each comma-separated value from the line
            while (getline(linestream, data, ','))
            {
                temp.push_back(data);
                //cout << data << endl;
            }
            result.push_back(temp);
        }

        // Close the file
        file.close();
    }
    else
    {
        cout << "Failed to open the file." << endl;
    }

    return result;
}
