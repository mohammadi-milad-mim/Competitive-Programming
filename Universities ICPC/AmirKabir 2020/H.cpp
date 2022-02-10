#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string name, mname, pos;
    int mscore = -(INT_MAX);
    int minutes_played, number_of_goals,number_of_assists,
    number_of_goals_conceded, number_of_saves, number_of_penalty_saves,
    number_of_penalty_misses, number_of_yellow_cards, number_of_red_cards,
    number_of_own_goals;
    while (cin>>name)
    {
        int score=0;
        cin>>pos;
        if (pos=="GKP")
        {
            cin>>minutes_played>>number_of_goals>>number_of_assists>>
            number_of_goals_conceded>>number_of_saves>>number_of_penalty_saves>>
            number_of_penalty_misses>>number_of_yellow_cards>>number_of_red_cards>>
            number_of_own_goals;

            if (minutes_played>=60) {score+=2;} else {score+=1;}
            score += (number_of_assists*3);
            score+= (number_of_penalty_misses*(-2));
            score += (number_of_yellow_cards*(-1));
            score += (number_of_red_cards*(-3));
            score+= (number_of_own_goals*(-2));

            score+=(number_of_goals*6);
            if (number_of_goals_conceded==0) {score+=4;} else { score-=number_of_goals_conceded/2;}
            score+= (number_of_saves/3);
            score+=(number_of_penalty_saves*5);
        }
        else if (pos =="DEF")
        {
            cin>>minutes_played>>number_of_goals>>number_of_assists>>
            number_of_goals_conceded>>number_of_penalty_misses>>number_of_yellow_cards>>
            number_of_red_cards>>number_of_own_goals;

            if (minutes_played>=60) {score+=2;} else {score+=1;}
            score += (number_of_assists*3);
            score+= (number_of_penalty_misses*(-2));
            score += (number_of_yellow_cards*(-1));
            score += (number_of_red_cards*(-3));
            score+= (number_of_own_goals*(-2));

            score+=(number_of_goals*6);
            if (number_of_goals_conceded==0) {score+=4;} else { score-=number_of_goals_conceded/2;}

        }
        else if (pos == "MID")
        {
            cin>>minutes_played>>number_of_goals>>number_of_assists>>
            number_of_goals_conceded>>number_of_penalty_misses>>number_of_yellow_cards>>
            number_of_red_cards>>number_of_own_goals;

            if (minutes_played>=60) {score+=2;} else {score+=1;}
            score += (number_of_assists*3);
            score+= (number_of_penalty_misses*(-2));
            score += (number_of_yellow_cards*(-1));
            score += (number_of_red_cards*(-3));
            score+= (number_of_own_goals*(-2));

            score+=(number_of_goals*5);
            if (number_of_goals_conceded==0) {score+=1;}
        }
        else if (pos == "FWD")
        {
            cin>>minutes_played>>number_of_goals>>number_of_assists>>
            number_of_penalty_misses>>number_of_yellow_cards>>
            number_of_red_cards>>number_of_own_goals;

            if (minutes_played>=60) {score+=2;} else {score+=1;}
            score += (number_of_assists*3);
            score+= (number_of_penalty_misses*(-2));
            score += (number_of_yellow_cards*(-1));
            score += (number_of_red_cards*(-3));
            score+= (number_of_own_goals*(-2));

            score+=(number_of_goals*4);
        }
        if (score>mscore)
        {
            mscore=score;
            mname=name;
        }
    }
    cout<<mname;
}