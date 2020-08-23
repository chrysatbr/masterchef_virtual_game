#ifndef IMMUNITYCOMPETITION_H_INCLUDED
#define IMMUNITYCOMPETITION_H_INCLUDED

#include "Competition.h"

class ImmunityCompetition : public Competition{

    ImmunityAward immunityAward;

public:
    ImmunityCompetition();
    ImmunityCompetition(int id, string name, ImmunityAward i) : Competition(id, name){
        immunityAward = i;
    }

    void setImmunityAward(ImmunityAward f){immunityAward = f;}

    ImmunityAward getImmunityAward(){return immunityAward;}

    void status(){
        Competition::status();
        cout << "Immunity Award: " << endl;
        immunityAward.status();
    }

    void compete(Team &team);

};

#endif // IMMUNITYCOMPETITION_H_INCLUDED
