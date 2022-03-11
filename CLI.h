/*
 * CLI.h
 *
 * Author: Yossi Maatook
 * Author: Osher Elhadad
 */
#ifndef CLI_H_
#define CLI_H_

#include <cstring>
#include "commands.h"

using namespace std;

// Command line interface - used to start interaction with user
class CLI {
    DefaultIO* dio;
    vector<Command*> commands;
public:

    // constructor
    explicit CLI(DefaultIO* dio);

    // starts the interaction with the user
    void start();

    // destructor
    virtual ~CLI();
};

#endif /* CLI_H_ */
