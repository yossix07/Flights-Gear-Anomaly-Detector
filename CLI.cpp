/*
 * CLI.cpp
 *
 * Author: Yossi Maatook
 * Author: Osher Elhadad
 */
#include "CLI.h"

// constructor
CLI::CLI(DefaultIO* dio) {
    this->dio = dio;
    this->commands.push_back(new UploadTimeSeriesCommand(this->dio));
    this->commands.push_back(new ThresholdCommand(this->dio));
    this->commands.push_back(new DetectAnomaliesCommand(this->dio));
    this->commands.push_back(new DisplayAnomaliesCommand(this->dio));
    this->commands.push_back(new UploadAnomaliesAndAnalyzeCommand(this->dio));
    this->commands.push_back(new ExitCommand(this->dio));
}

// starts the interaction with the user
void CLI::start() {
    Info* sharedInfo = new Info();
    int userInput;
    do {
        this->dio->write("Welcome to the Anomaly Detection Server.\n");
        this->dio->write("Please choose an option:\n");
        int size = this->commands.size();

        // write every command description
        for (int i = 0; i < size; ++i) {
            this->dio->write(i + 1);
            this->dio->write("." + commands.at(i)->getDescription());
        }

        // get command number from user
        userInput = stoi(this->dio->read());
        if (userInput <= 6 && userInput >= 1) {

            // runs the chosen command
            this->commands.at(userInput - 1)->execute(sharedInfo);
        }
    } while (userInput != 6);
    delete sharedInfo;
}

// destructor
CLI::~CLI() {
    for (auto & command : this->commands) {
        delete command;
    }
}
