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






//libraries/header files...;;;
#include <iostream>
#include <iomanip> 

#include"variable.h"
using namespace std;



//to display path after algorith has been applied to them....;;;;
void path_display(int path_finder_array[][SIZE], int start_x_origin, int final_x_end)
{

    if ((path_finder_array[start_x_origin][final_x_end] == -1))
    {
        //statement no path....;;;;
        cout << "No_Path_Exists"
            << "\n";//next line;;;;

    }

    else if ((path_finder_array[start_x_origin][final_x_end] == start_x_origin))
    {

        //statement to display path....;;;;

        cout << start_x_origin//starting point for path..;;;
            << " -> ";

    }

    else
    {

        //recursively implementation of the function that display path...;;;;;;
        path_display(path_finder_array, start_x_origin, path_finder_array[start_x_origin][final_x_end]);


        //statement to display path....;;;;
        cout << path_finder_array[start_x_origin][final_x_end]//displaying the nodes needed to travel the path...;;;;
            << " -> ";

    }



    //end point or final destination movie(lmao).....;;;;
    cout << final_x_end
        << "\n";//next line..;;;;

}

//================================================FloyeD algorithm======================================================


//algorithm of floed(mayweather(lmao))..to find short path...for crystal.....;;;;;;;; 
void algo_floyed_sh0rt(int gamez_grafph[][SIZE], int start_x_origin, int final_x_end, int gem_pos_x, int gem_pos_y)
{
    int displacement[SIZE][SIZE];
    int path_finder_array[SIZE][SIZE];
    int gem_xy_pos = -1;
    int bc = 0;
    int stdp = 0;
    //displacement or path ko initilize krtay huai...;;;;;

    int iter_i = 0;
    while (iter_i < SIZE)
    {
        int iter_j = 0;
        while (SIZE > iter_j)
        {
            displacement[iter_i][iter_j] = gamez_grafph[iter_i][iter_j];


            if (gamez_grafph[iter_i][iter_j] != INF)
            {
                path_finder_array[iter_i][iter_j] = iter_i;
            }

            else if (iter_j == iter_i)
            {
                path_finder_array[iter_i][iter_j] = 0;
            }

            else
            {
                path_finder_array[iter_i][iter_j] = -1;
            }

            //pata karnai kailiyai kai gem ya crystal position y pai mujood hai kai nhee...;;;;;

            if (gamez_grafph[iter_i][iter_j] != INF && iter_j == gamez_grafph[gem_pos_x][gem_pos_y])
            {
                gem_xy_pos = iter_j;
            }



            //iteratoration...;;;;
            iter_j++;
        }

        //iteratoration...;;;;
        iter_i++;
    }

    int count_k = 0;

    // displacement or path matrices ko update krna..;;
    while (count_k < SIZE)
    {
        int count_i = 0;
        for (; count_i < SIZE; )
        {
            int count_j = 0;
            while (count_j < SIZE)
            {
                if (displacement[count_k][count_j] != INF && displacement[count_i][count_k] != INF && displacement[count_i][count_j] > (displacement[count_i][count_k] + displacement[count_k][count_j]))
                {
                    int tempx = (displacement[count_i][count_k] + displacement[count_k][count_j]);
                    displacement[count_i][count_j] = tempx;
                    path_finder_array[count_i][count_j] = path_finder_array[count_k][count_j];
                }

                //iterator..;;;
                count_j++;
            }


            count_i++;
        }


        count_k++;
    }



    if (displacement[start_x_origin][final_x_end] == INF)
    {
        cout << "There is no path between the source and destination vertices.\n";
    }
    else if (displacement[start_x_origin][final_x_end] != INF)
    {
        path_display(path_finder_array, start_x_origin, final_x_end);


    }

    // crystal kee location ko print karnai kailiyai...;;;;;
    if (gem_xy_pos == -1)
    {
        cout << "Unable to locate the Crystal.\n";
    }
    else if (gem_xy_pos != -1)
    {
        cout << "The crystal is located at vertex "
            << gem_xy_pos //gem/crystal kee position....;;;;
            << "" << "." << endl;;
    }


    /*cout << endl;
    cout << "----------------------"<<endl;
    cout << "Printing the shortest paths " << endl << endl;

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {

            cout << j << endl;
        }
    }

    */




}

//=====================================================Dijisaktra======================================================

//algorithm of disjikstra..to find short path...for crystal.....;;;;;;;; 
pair<int, int*> algo_dijiksatra_short(int map_2dmatrix[][SIZE], int origin_x, int gem_pos_x, int gem_pos_y)
{
    //initializer...;;;;;
    static int displacement[SIZE];
    bool already_viz[SIZE];     ///wowo elements jinko hum visist karchukai hon...;;

    // pichlai node jokai chotai path mein thai from start to node i..;;;
    int prev[SIZE];

    int iter_i = 0;
    while (iter_i < SIZE)
    {
        displacement[iter_i] = INT_MAX;
        already_viz[iter_i] = false;
        prev[iter_i] = -1;

        iter_i++;
    }

    displacement[origin_x] = 0;

    int count = 0;
    while (count < SIZE - 1)
    {
        int utah = -1;
        int i = 0;
        for (; i < SIZE;)
        {
            if (!already_viz[i] && (displacement[utah] > displacement[i] || utah == -1))
            {
                utah = i;
            }


            i++;
        }
        already_viz[utah] = true;

        int iter_vrtex = 0;
        while (iter_vrtex < SIZE)
        {
            if (map_2dmatrix[utah][iter_vrtex] && displacement[utah] != INT_MAX && displacement[utah] + map_2dmatrix[utah][iter_vrtex] < displacement[iter_vrtex])
            {

                displacement[iter_vrtex] = displacement[utah] + map_2dmatrix[utah][iter_vrtex];
                prev[iter_vrtex] = utah;

            }

            iter_vrtex++;
        }

        count++;
    }


    //shuru sai crystal take path ko banana...;;;;;;
    //dynamic array......;;;;;
    int* game_path = new int[SIZE];
    int diiplacement_size = 0;
    int pk = SIZE;
    int present = gem_pos_x * pk + gem_pos_y;
    for (; present != origin_x; )
    {

        game_path[diiplacement_size++] = present;
        present = prev[present];

    }




    game_path[diiplacement_size++] = origin_x;






    reverse(game_path, game_path + diiplacement_size);

    return make_pair(diiplacement_size, game_path);

}