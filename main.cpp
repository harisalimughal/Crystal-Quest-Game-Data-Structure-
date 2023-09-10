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








#include <iostream>
#include <stdio.h>
#include <SDL.h>         
#include <SDL_image.h>   //for imgage
#include <windows.h>
#include <cstdlib>  // for system()

#include "shortest distance.h"
#include "Span.h"
#include "Inventory.h"
#include "map.h"
#include"variable.h"

using namespace std;


//;;;;

int(*map())[SIZE]
{
    // Allocate memory for the adjacency matrix
    int(*game_matrx)[SIZE] = new int[SIZE][SIZE];
    // Initialize the adjacency matrix
    for (int iter_i = 0; iter_i < SIZE; iter_i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            game_matrx[iter_i][j] = 0;
        }
    }

    // Define the mapping from (i, j) coordinates to vertex number
    auto vertex = [=](int i, int j) { return i * SIZE + j; };

    // Add the crystal to a random location in the matrix
    srand(time(NULL));
    int crystal_pos_x = rand() % SIZE;
    int crystal_pos_y = rand() % SIZE;
    game_matrx[crystal_pos_x][crystal_pos_y] = 1;






    // Add 25 rewards to random locations in the matrix
    for (int iter_i = 0; iter_i < 25; iter_i++)
    {
        int reward_pos_x = rand() % SIZE;
        int reward_pos_y = rand() % SIZE;
        for (; game_matrx[reward_pos_x][reward_pos_y] != 0;)
        {
            reward_pos_x = rand() % SIZE;
            reward_pos_y = rand() % SIZE;
        }


        game_matrx[reward_pos_x][reward_pos_y] = 2;
    }

    // Add 10 goblins to random locations in the matrix
    for (int iter_i = 0; iter_i < 10; iter_i++)
    {
        int goblin_pos_x = rand() % SIZE;
        int goblin_pos_y = rand() % SIZE;
        for (; game_matrx[goblin_pos_x][goblin_pos_y] != 0;)
        {

            goblin_pos_x = rand() % SIZE;
            goblin_pos_y = rand() % SIZE;

        }


        game_matrx[goblin_pos_x][goblin_pos_y] = 2;
    }

    // Add 10 dragons to random locations in the matrix
    for (int iter_i = 0; iter_i < 10; iter_i++)
    {
        int goblin_pos_x = rand() % SIZE;
        int goblin_y = rand() % SIZE;
        for (; game_matrx[goblin_pos_x][goblin_y] != 0; )
        {
            goblin_pos_x = rand() % SIZE;
            goblin_y = rand() % SIZE;
        }



        game_matrx[goblin_pos_x][goblin_y] = 2;
    }

    // Add 10 werewolf to random locations in the matrix
    for (int iter_i = 0; iter_i < 10; iter_i++) {
        int werewolf_pos_x = rand() % SIZE;
        int werewolf_pos_y = rand() % SIZE;
        for (; game_matrx[werewolf_pos_x][werewolf_pos_y] != 0; )
        {
            werewolf_pos_x = rand() % SIZE;
            werewolf_pos_y = rand() % SIZE;
        }
        game_matrx[werewolf_pos_x][werewolf_pos_y] = 2;
    }

    // Add 10 potion to random locations in the matrix
    for (int iter_i = 0; iter_i < 10; iter_i++) {
        int potion_pos_x = rand() % SIZE;
        int potion_pos_y = rand() % SIZE;
        for (; game_matrx[potion_pos_x][potion_pos_y] != 0;)
        {
            potion_pos_x = rand() % SIZE;
            potion_pos_y = rand() % SIZE;
        }
        game_matrx[potion_pos_x][potion_pos_y] = 2;
    }



    // Add 15 death points to random locations in the matrix
    for (int ietr_i = 0; ietr_i < 15; ietr_i++)
    {
        int death_pos_x = rand() % SIZE;
        int death_pos_y = rand() % SIZE;
        for (; game_matrx[death_pos_x][death_pos_y] != 0;)
        {
            death_pos_x = rand() % SIZE;
            death_pos_y = rand() % SIZE;
        }


        game_matrx[death_pos_x][death_pos_y] = 3;
    }

    // Add the player to a random location in the matrix
    int player_pos_x = rand() % SIZE;
    int player_pos_y = rand() % SIZE;

    for (; game_matrx[player_pos_x][player_pos_y] != 0;)
    {


        player_pos_x = rand() % SIZE;
        player_pos_y = rand() % SIZE;

    }



    game_matrx[player_pos_x][player_pos_y] = 5;


    // Add 50 obstacles to random locations in the matrix
    for (int iter_i = 0; iter_i < 50; iter_i++)
    {
        int obstacle_pos_x = rand() % SIZE;
        int obstacle_pozi_y = rand() % SIZE;
        for (; game_matrx[obstacle_pos_x][obstacle_pozi_y] != 0; )
        {
            obstacle_pos_x = rand() % SIZE;
            obstacle_pozi_y = rand() % SIZE;
        }


        game_matrx[obstacle_pos_x][obstacle_pozi_y] = 4;


    }
    // obstacle kai qareeb walai edges 100..;;;
    // bakee edges ka weiht_1 hai..;;;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (game_matrx[i][j] == 4)
            {
                for (int ii = i - 1; ii <= i + 1; ii++)
                {
                    for (int jj = j - 1; jj <= j + 1; jj++)
                    {
                        if (ii >= 0 && ii < SIZE && jj >= 0 && jj < SIZE && !(ii == i && jj == j))
                        {
                            game_matrx[ii][jj] = 100;
                        }
                    }
                }
            }
        }
    }
    // Return the adjacency matrix
    return game_matrx;
}


void menue()
{

    cout << "1. Show map" << endl;
    cout << "2. Adjacdncy Matrix" << endl;
    cout << "3. Score Board" << endl;
    cout << "4. shortest path from default location(0,0) to crystal using Dijkstra Algortithm" << endl;
    cout << "5. shortest path from custom location to crystal using Dijkstra Algortithm" << endl;
    cout << "6. shortest path from custom location to crystal using Flyod Algortithm" << endl;
    cout << "7. shortest path from default location(0,0) to crystal using Flyod Algortithm" << endl;
    cout << "8. Minimum Spanning tree using Prim's Algorithm" << endl;
    cout << "9. Minimum Spanning tree using kruskal Algorithm" << endl;
    cout << "s. Final Score Board" << endl;
    cout << "e. Exit" << endl;
}

void haris_art()
{
    cout << "\t\t\t _________________________________________________________" << endl;
    cout << "\t\t\t|******** __    __****************************************|" << endl;
    cout << "\t\t\t| *******/ \\  /  \\****************************************|" << endl;
    cout << "\t\t\t|_______/    \\/    \\______________________________________|" << endl;
    cout << "\t\t\t|                                                         |" << endl;
    cout << "\t\t\t|  WELCOME TO The Quest for the crystal Kingdom           |" << endl;
    cout << "\t\t\t|_________________________________________________________|" << endl;
    cout << "\t\t\t|*********\\_/\\__/\\_/**************************************|  " << endl;
    cout << "\t\t\t|*********/      \\****************************************|" << endl;
    cout << "\t\t\t|********/        \\***************************************|" << endl;
    cout << "\t\t\t|_________________________________________________________|" << endl;
    cout << endl << endl;

}

int main(int argc, char* argv[]) {

    int(*game_matrix)[SIZE] = map();
    AVL_tree_Noded* root = nullptr;
    int origin = 0;

    int src = 0; // Starting node

    int i = 0;

    int source;
    int destination;
    int cryztal_poz_x = rand() % 20;
    int crystal_pos_y = rand() % 20;

    game_matrix[cryztal_poz_x][crystal_pos_y] = rand() % 20;

    pair<int, int*> result;

    //-----------------------------------------------------Code for Image -----------------------------------------
//;;;



        // variable declarations
    SDL_Window* window = NULL;
    SDL_Renderer* rendering_image = NULL;
    SDL_Texture* my_art_image = NULL;

    // Initialize SDL.
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return 1;
    }
    // create the window and renderer
    // note that the renderer is accelerated
    window = SDL_CreateWindow("WELCOME TO THE QUEST FOR CRYSTAL KINGDOM", 10, 78, WIDTH, HEIGHT, 0);
    rendering_image = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //image_path loading...;;;
    char path_image[] = "C:\\Users\\RM\\Pictures\\crystal.png";

    // load our image
    my_art_image = IMG_LoadTexture(rendering_image, path_image);
    if (!(my_art_image != nullptr))
    {
        cout << "Image Error: "
            << SDL_GetError()
            << endl;



        return 1;
    }


    int widt, heght; // texture width & height
    SDL_QueryTexture(my_art_image, NULL, NULL, &widt, &heght);


    SDL_Rect texr; texr.x = 0; texr.y = 0; texr.w = widt; texr.h = heght;

    unsigned int lastUpdateTime = 0;

    // main loop
    while (1)
    {

        // event handling
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                break;
            else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
                break;
        }

        // paint the image once every 30ms, i.e. 33 images per second
        if (lastUpdateTime + 30 < SDL_GetTicks()) {
            lastUpdateTime = SDL_GetTicks();

            // clear the screen
            SDL_RenderClear(rendering_image);
            // copy the texture to the rendering context
            SDL_RenderCopy(rendering_image, my_art_image, NULL, &texr);
            // flip the backbuffer
            // this means that everything that we prepared behind the screens is actually shown
            SDL_RenderPresent(rendering_image);
            bool played = PlaySound(TEXT("PubG_music.wav"), NULL, SND_SYNC);                         //for sound
            break;
        }
    }

    SDL_DestroyTexture(my_art_image);
    SDL_DestroyRenderer(rendering_image);
    SDL_DestroyWindow(window);

    //------------------------------------------MENU---------------------------------------------------------------------

    haris_art();


    char choice;

    do {

        menue();


        cout << "Enter your choice (1-11): ";
        cin >> choice;


        ///---------------------------------------------------------;;;
        switch (choice)
        {
        case '1':
            cout << "You chose Option 1." << endl;
            system("cls");
            GameMap();
            cout << "\n-----------------------------------------------------------------------------------" << endl;
            break;

            ///---------------------------------------------------------;;;
        case '2':
            system("cls");
            cout << "You chose Option 2." << endl;

            //Print the matrix
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    cout << setw(7) << game_matrix[i][j] << " ";
                }
                cout << endl << endl << endl;
            }
            cout << "\n-----------------------------------------------------------------------------------" << endl;
            break;

            ///---------------------------------------------------------;;;
        case '3':
            cout << "You chose Option 3." << endl;
            system("cls");
            cout << "\n---------------------------------------Scores of the Players using AVL Tree---------------------" << endl;
            std::srand(std::time(nullptr)); // seed the random number generator with the current time



            //first id is 100
            root = inzertion(root, 100, 2, 130, 1, 8);

            int id, score, enemy, reward;

            for (int i = 0; i < 3; i++)
            {
                id = std::rand() % 201; // generate random id between 0-200
                score = rand() % 201;
                enemy = rand() % 10;
                reward = rand() % 10;
                root = inzertion(root, id, 1, score, enemy, reward);
            }

            //cout << "Initial Scores:" << endl;
            display_in_order(root, enemy, reward);
            cout << "\n-----------------------------------------------------------------------------------" << endl;
            break;


            ///---------------------------------------------------------;;;
        case '4':
            system("cls");


            // Print the shortest distance from the start node to every other node
            cout << "Printing the shortest path form default location (0,0) to cyrstal {DIJKSTRA ALGO}" << endl;


            result = algo_dijiksatra_short(game_matrix, origin, cryztal_poz_x, crystal_pos_y);
            if (result.second == nullptr) {
                std::cout << "Crystal is not reachable from the starting point.\n";
            }
            else {
                std::cout << "Shortest path length: " << result.first << "\n";
                std::cout << "Shortest path: ";
                for (int i = 0; i < result.first - 1; i++) {
                    std::cout << result.second[i] << "->";
                }
                std::cout << result.second[result.first - 1] << "\n";
                delete[] result.second;
            }
            cout << "\n-----------------------------------------------------------------------------------" << endl;
            break;


            ///---------------------------------------------------------;;;
        case '5':
            system("cls");


            // Print the shortest distance from the start node to every other node
            cout << "Printing the shortest path form custom location to crystal {DIJKSTRA ALGO}" << endl;

            cout << "Enter source vertex" << endl;
            cin >> src;

            result = algo_dijiksatra_short(game_matrix, src, cryztal_poz_x, crystal_pos_y);
            if (result.second == nullptr) {
                std::cout << "Crystal is not reachable from the starting point.\n";
            }

            else
            {
                std::cout << "Shortest path length: " << result.first << "\n";
                std::cout << "Shortest path: ";
                for (int i = 0; i < result.first - 1; i++) {
                    std::cout << result.second[i] << "->";
                }
                std::cout << result.second[result.first - 1] << "\n";
                delete[] result.second;
            }
            cout << "\n-----------------------------------------------------------------------------------" << endl;
            break;


            ///---------------------------------------------------------;;;
        case '6':
            system("cls");
            cout << "\n--------------------------------Shortest path from custom location to crystal using Floyd Algo-----------------------" << endl;


            // Take input from user for source and destination vertices
            cout << "Enter source vertex: ";
            cin >> source;


            // Run Floyd Warshall Algorithm on the given graph
            algo_floyed_sh0rt(game_matrix, source, game_matrix[cryztal_poz_x][crystal_pos_y], cryztal_poz_x, crystal_pos_y);
            cout << "\n-----------------------------------------------------------------------------------" << endl;
            break;
            ///---------------------------------------------------------;;;
        case '7':
            system("cls");
            cout << "\n--------------------------------Shortest path from default location(0,0) to crystal using Floyd Algo---------------------" << endl;

            algo_floyed_sh0rt(game_matrix, 0, game_matrix[cryztal_poz_x][crystal_pos_y], cryztal_poz_x, crystal_pos_y);
            cout << "\n-----------------------------------------------------------------------------------" << endl;
            break;

            //-----------------------------------------------------;;;;
        case '8':
            system("cls");
            cout << "\n--------------------------------Minimum Spanning Tree using Prims Algo-------------------------------------------" << endl;
            primz_algo_MIN_Span_Tree(game_matrix);
            cout << "\n-----------------------------------------------------------------------------------" << endl;
            break;

            //----------------------------------------------------;;;
        case '9':
            system("cls");
            cout << "\n--------------------------------Minimum Spanning Tree using kruskal Algo-------------------------------------------" << endl;
            algo_kruzkal_Min_Span_Tree(game_matrix);
            cout << "\n-----------------------------------------------------------------------------------" << endl;
            break;

            //-----------------------------------------------------;;;;;
        case 's':
            system("cls");
            cout << "**********-FINAL SCORE BOARD OF THE GAME-**********" << endl;
            std::srand(std::time(nullptr)); // seed the random number generator with the current time



            //first id is 100
            root = inzertion(root, 100, 2, 130, 1, 8);

            for (int i = 0; i < 3; i++)
            {
                id = std::rand() % 201; // generate random id between 0-200
                score = rand() % 201;
                enemy = rand() % 10;
                reward = rand() % 10;
                root = inzertion(root, id, 1, score, enemy, reward);
            }
            displaying(root);
            cout << "\n-----------------------------------------------------------------------------------" << endl;
            break;

            //---------------------------------------------------------------------------------;;;
        case  'e':
            system("cls");
            cout << "Exiting program..." << endl;
            exit(0);
            break;

            //--------------------------------------------------------------------------------;;;;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 11." << endl;
        }


    } while (choice != 11);


    return 0;
}