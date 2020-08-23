#ifndef VOTING_H_INCLUDED
#define VOTING_H_INCLUDED

// YOU HAVE TO FILL THIS CLASS.
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include "Vote.h"
#include "Team.h"

using namespace std;

class Voting{

    static std::vector<Vote> votes;
    static std::map<string,int> results;

public:

    static void depositOfVotes(Team &team);
    static void countingAndExportingResults();
    static void bestAndWorstVotingResults(Team &team);
    static void votingProcess(Team &team);

};

#endif // VOTING_H_INCLUDED
