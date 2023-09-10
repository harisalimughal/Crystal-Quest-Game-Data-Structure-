/*

    DATA STRUCTURE;
    lab_project:
    CS_H;

    HARIS MUGHAL  :
    NOUMAN AHMAD  :
    ABDULLAH TAHIR:

    22i-0747;
    21i-0727;
    21i-0708;

*/



#pragma once

#include <iostream>
#include <stdlib.h>
#include"variable.h"
#include <time.h>

using namespace std;

int GameMap()
{
    // matrix ko initilize karnai kailiyai...;;;;;

    const int size = SIZE;
    char game_matriz[size][size];

    //initializer loopp....
    int ietr_i = 0;

    //loop_1...;;;;;
    while (ietr_i < 20)
    {
        int iter_j = 0;
        //loop_2...;;;;
        while (iter_j < 20)
        {

            game_matriz[ietr_i][iter_j] = 'C';

            //ieteration..;;;;;
            iter_j++;
        }

        //iteratoration..;;;;;;
        ietr_i++;
    }

    // crystal ko random location mein add karna...;;;;;
    srand(time(NULL));

    int gem_pos_x = rand() % size;
    int gem_pos_y = rand() % size;
    char game_crystal = '*';
    game_matriz[gem_pos_x][gem_pos_y] = game_crystal;

    // 25 rewards randomly alllocate..;;;;;;;
    char game_revvardz[3] = { 'J', 'P', 'W' };
    //looop_1;;;;
    int loop_x = 0;
    while (loop_x < 25)
    {
        int reward_pos_x = rand() % size;
        int reward_pos_y = rand() % size;

        char c = 'C';
        for (; game_matriz[reward_pos_x][reward_pos_y] != c; )
        {
            reward_pos_x = rand() % size;
            reward_pos_y = rand() % size;
        }


        game_matriz[reward_pos_x][reward_pos_y] = game_revvardz[rand() % 3];


        loop_x++;
    }

    // 15 death points to random location mein add krna..;;;;;

    int loop_y = 0;

    //loop_2;;;;
    while (loop_y < 15)
    {
        int death_x = rand() % size;
        int death_y = rand() % size;

        char c = 'C';
        for (; game_matriz[death_x][death_y] != c; )
        {

            death_x = rand() % size;
            death_y = rand() % size;

        }

        game_matriz[death_x][death_y] = '%';


        loop_y++;
    }

    // 50 obstacles ko randomly add krna...;;;;
    //looop_3..;;;
    int loop_z = 0;
    while (loop_z < 50)
    {
        int obstacle_x = rand() % size;
        int obstacle_y = rand() % size;

        char c = 'C';
        for (; game_matriz[obstacle_x][obstacle_y] != c;)
        {
            obstacle_x = rand() % size;
            obstacle_y = rand() % size;
        }

        //obstackle..;;;
        game_matriz[obstacle_x][obstacle_y] = '#';

        loop_z++;
    }

    // 20 monsters ko random location mein add krna.....;;;;;
    char game_monzterz[3] = { '&', '$', '@' };

    int loop_a = 0;
    //loop_4..;;;;;
    while (loop_a < 20)
    {
        int monzter_pos_x = rand() % size;
        int monzter_pos_y = rand() % size;

        char c = 'C';
        for (; game_matriz[monzter_pos_x][monzter_pos_y] != c; )
        {
            monzter_pos_x = rand() % size;
            monzter_pos_y = rand() % size;
        }



        game_matriz[monzter_pos_x][monzter_pos_y] = game_monzterz[rand() % 3];


        loop_a++;
    }

    // matrix ko print karnai kailiyai....;;;;;
    //looopp_5;;;;;
    int iter_a = 0;
    while (iter_a < 20)
    {
        int iter_j = 0;
        for (; iter_j < 20; )
        {

            cout << game_matriz[iter_a][iter_j]
                << " ";
            iter_j++;
        }
        cout << "" << endl;

        iter_a++;
    }


    /// <map>
    /// to print and display componenets in the map...;;;
    /// </map>
    /// <returns></returns>
    return 0;
}