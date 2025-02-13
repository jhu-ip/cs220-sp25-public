#include <stdio.h>
#include <stdlib.h>
#include "soccer.h"

void create_player (Player *p, bool goalie) {
  p->age = rand() % 18 + 18;
  p->jersey_num = goalie ? 1 : rand() % 30 + 2;
  p->goalkeeper = goalie ? 1 : 0;

  Date * date = malloc(sizeof(Date)); // malloc a date

  if (date == NULL) {
    printf("failed to malloc Date!\n");
    exit(1);
  }

  date->day = rand() % 30 + 1;
  date->month = rand() % 12 + 1;
  date->year = rand() % 8 + 2010;
  p->date = date; // make p->date point to the allocated date
 
  Stat * stat = malloc(sizeof(Stat)); // malloc a stat

  if (stat == NULL) {
    printf("failed to malloc Stat!\n");
    exit(1);
  }

  stat->num_of_goals = (p->goalkeeper)? 0 : rand() % 150 + 1;
  stat->num_of_assists = (p->goalkeeper)? 0 : rand() % 150 + 1;
  stat->pass_accuracy = (float)rand()/(float)(RAND_MAX/100);
  stat->min_played = rand() % 5000 + 500;
  stat->num_of_shots = (p->goalkeeper) ? 0 : rand() % 1000 + 50;
  stat->shot_accuracy = (p->goalkeeper) ? 0 : (float)rand()/(float)(RAND_MAX/100);

  p->stat = stat; // make p->stat point to the allocated stat  
}

void create_team(Player team[], int size) {
  for (int i = 0; i < size; i++) {
    create_player(&team[i], (i == 0) ? true : false);
  }
}

void print_team (Player team[], int size) {
  for (int i = 0; i < size; i++) { 

    printf("Player %d [age = %d, jersey# = %d, goalie = %d, signed date = %d-%d-%d]:\n", i, team[i].age, team[i].jersey_num, team[i].goalkeeper, team[i].date->day, team[i].date->month, team[i].date->year);
    
    printf("\tStat: goals = %d, assists = %d, pass accuracy = %0.1f, minutes played = %d, shots: %d, shot accuracy = %0.1f\n", team[i].stat->num_of_goals, team[i].stat->num_of_assists, team[i].stat->pass_accuracy, team[i].stat->min_played, team[i].stat->num_of_shots, team[i].stat->shot_accuracy);

  }
}
