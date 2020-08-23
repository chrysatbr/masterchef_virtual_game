#ifndef VOTE_H_INCLUDED
#define VOTE_H_INCLUDED

// YOU HAVE TO FILL THIS CLASS.

#include <iostream>
#include <string>
using namespace std;

class Vote{

    string voted;
    string reason;

public:
    Vote(){voted = ""; reason = "";}
    Vote(string v, string r){voted = v; reason = r;}
    ~Vote(){cout << "Vote is destroyed. "<<voted << endl;}

    void setVoted(string v){voted = v;}
    void setReason(string r){reason = r;}

    string getVoted(){return voted;}
    string getReason(){return reason;}
    void status(){cout << "Voted: " << voted<< endl; cout << "Reason: " << reason << endl;}
};


#endif // VOTE_H_INCLUDED
