#include "Voting.h"
#include "Team.h"
#include "Vote.h"
#include <time.h>

using namespace std;
//arxikopoihsh tou vector kai tou map antistoixa
std::vector<Vote> Voting ::votes;
std::map<string,int> Voting ::results;

 void Voting :: depositOfVotes(Team &team){
    //int counter=0;
    srand (time(NULL));
    Player *players = team.getPlayers();
    int randPosition1=0;
    cout << "\nNUMBER OF PLAYERS: " <<team.getNumberOfPlayers()<<"\n"<<endl;
    for(int i=0;i<11;i++){
        //counter=players[i].getVotes();
        while(players[i].getVotes()>0){
            randPosition1 = (rand() % 10)+0;
            cout << "\nI am player: " <<players[i].getName()<< " ID: "<< i<<" Votes "<< players[i].getVotes()<<endl;
            cout << "I choose player: " << randPosition1 << " immunity " << players[randPosition1].getImmunity() << " player name: "<< players[randPosition1].getName()<<endl;
            while(randPosition1 == i || players[randPosition1].getImmunity() == true || players[randPosition1].getName()==""){
                randPosition1 = (rand() % 10)+0;
                cout << "\nI am player: " <<players[i].getName()<< " ID: "<< i<<" Votes "<< players[i].getVotes()<<endl;
                cout << "I choose player: " << randPosition1 << " immunity " << players[randPosition1].getImmunity() << " player name: "<< players[randPosition1].getName()<<endl;
            }
            Voting::votes.push_back(Vote(players[randPosition1].getName(),"random strategy"));
            players[i].setVotes(players[i].getVotes()-1);
        }
        if(players[i].getName()!=""){
            players[i].setVotes(1);
        }

    }
    for(int i=0; i<Voting::votes.size();i++){
        votes[i].status();
    }
}


 void Voting :: countingAndExportingResults(){

    map<string,int>::iterator it;
    for(int i=0; i<Voting::votes.size();i++){
        it = Voting::results.find(Voting::votes[i].getVoted());
        if (it == Voting::results.end()){
            Voting::results.insert(pair<string,int>(Voting::votes[i].getVoted(),1));
        }
        else{
            it->second +=1;
        }

     }
     for (map<string,int>::iterator it=Voting::results.begin(); it!=Voting::results.end(); ++it){
        cout << it->first << "-" << it->second << endl;
     }
}


 void Voting :: bestAndWorstVotingResults(Team &team){
    int max=0,max2=0;
    Player *players = team.getPlayers();
    string firstNAme,secondName,lastNAme;
     for (map<string,int>::iterator it=Voting::results.begin(); it!=Voting::results.end(); ++it){
        if(it->second>max){
            max = it->second;
            firstNAme = it->first;
        }
    }
    for (map<string,int>::iterator it=Voting::results.begin(); it!=Voting::results.end(); ++it){
        if(it->second > max2 && it->second <= max && firstNAme != it->first){
            max2 = it->second;
            secondName = it->first;
        }
    }
    team.setCandidate(firstNAme);
    team.setCandidate(secondName);
    cout << "First Player: " << firstNAme << " vote = " << max << "\nSecond Player: " << secondName << " vote = " << max2 << endl;
    srand (time(NULL));
    int random = (rand() % 1)+0;
    cout << "random = " << random << "\n";

    for(int i=0;i<11;i++){
        if(random == 0){
            if(players[i].getName() == firstNAme){
                cout << "Name = " << firstNAme << " ID = " << i << endl;
                team.removePlayer(i);
            }

        }
        else{
            if(players[i].getName()== secondName){
                cout << "Name = " << secondName << " ID = " << i << endl;
               // team.removePlayer(i);
            }

        }
    }

}



 void  Voting :: votingProcess(Team &team){
    Voting::votes.clear();
    Voting::results.clear();
    Voting::depositOfVotes(team);
    Voting::countingAndExportingResults();
    Voting::bestAndWorstVotingResults(team);
}
// YOU HAVE TO FILL THIS CLASS.
