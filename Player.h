#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <ctime>
#include <string>
#include <cstdio>
#include <cstdlib>
//etoimh gia xrhsh. xwris kamia pros8hkh
using namespace std;

enum genderOption {male, female};

class Player{

    string name;
    genderOption gender;
    int age;
    string job;
	int wins;
	int votes;
    float technique;
    float fatigue;
    float popularity;
    bool candidate;
    bool immunity;

public:
    Player();
    Player(string n, genderOption g, int a);
    ~Player();

    string getName();
    genderOption getGender();
    int getAge();
    string getJob();
	int getWins();
	int getVotes();
    float getTechnique();
    float getFatigue();
    float getPopularity();
    bool getCandidate();
    bool getImmunity();

    void setName(string val);
    void setGender(genderOption val);
    void setJob(string val);
    void setAge(int val);
	void setWins(int val);
	void setVotes(int val);
    void setTechnique(float val);
    void setFatigue(float val);
    void setPopularity(float val);
    void setCandidate(bool val);
    void setImmunity(bool val);

    void work();
    void sleep();
    void socialize();
    void practice();
    void compete();

    void status();
};

