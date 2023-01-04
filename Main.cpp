#include "Main.h"

// This is the main function
int main(
        // This function takes two arguments as input:
        // - argc: the number of command-line arguments passed to the program
        // - argv: an array of strings containing the command-line arguments
        int argc, char* argv[]
) {

    if (argc <= 4) {
        cerr << "Error" << endl;
        return -1;
    }

    string serverClient = argv[1];
    if(serverClient == "server") {
        Server server;
        int succ = 0;
        succ = server.startServer("5555", "/home/omer/CLionProjects/Advanced-Programming-1-Project/iris_classified.csv");
    } else {
        Client client;
        string ip = "127.0.0.1";
        char test [ip.size()+1];
        strcpy(test,ip.c_str());
        client.createClient(test, "5555");
    }

    // This line initializes a variable to store the value of k
    int k = 0;
    // This try block attempts to convert the string representing k to an integer
    try {
        // This line attempts to convert the string at index 1 in the argv array to an integer, and assigns the result to the k variable
        k = stoi(argv[2]);
    }
        // This catch block is executed if the conversion of the string to an integer fails
    catch(exception e) {
        // This line prints an error message
        cerr << "Error" << endl;
        // This line returns 1 to indicate an error occurred
        return -1;
    }
    // This line initializes a variable to store the path to the CSV file
    string path = argv[3];
    // This line initializes a variable to store the distance algorithm to use
    string disType = argv[4];
    // This line creates a new Classification object
    Classification classification;
    // This infinite loop continuously prompts the user for a test case and performs classification
    while(true) {
        // This line calls the inputToClass function to classify the test case
        string result = classification.inputToClass(path, k, disType);
        cout << result << endl;
    }
}

