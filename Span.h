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

//===========================================================


#pragma once



#include <iostream>
#include"variable.h"


#include <climits>

using namespace std;

//taken var;;

//chotay spanning tree mein jo vertex kee hai wo jo included nhee unko find karnai kailiyai hai...;;
int mineemum_spanning_Key_req(int span_key_vert[], bool min_span_tree_notinc[])
{

    //initialization of variables....;;
    int mineemum_val_cond = INT_MAX;
    int find_mineemum_ind = 0;
    int cond = 0;
    bool chck;

    /*

        while loop;;
    */

    ////initialization of variables for looopss....;;
    int vert_iter = 0;
    //bool cnd=v?N:false;
    while (vert_iter < N)
    {
        if (span_key_vert[vert_iter] < mineemum_val_cond && !min_span_tree_notinc[vert_iter])
        {

            mineemum_val_cond = span_key_vert[vert_iter];
            //sabsai chotee val ka index;;;
            find_mineemum_ind = vert_iter;


        }

        //iteration kailiyai variable....;;;
        vert_iter++;

    }

    //return value;;;
    return find_mineemum_ind;


}

//===========================================================================================================


//MST kee parent array ko use krkai print karnai kailiyai function..;;
void display_min_span_tree(int M_S_T_parent_arr[], int map_2dmatrix[N][N])
{
    //initializing...;;
    int x = 0;
    bool chck = false;

    char alpah = 'A';
    //state,mented...;;;
    std::cout << "Minimum_Spanning_Tree:";
    std::cout << "\n" << "";

    //variabl initializer...;;;
    int MST_iter_i = 1;

    while (N > MST_iter_i)
    {
        cout << char(M_S_T_parent_arr[MST_iter_i] + alpah) << ""
            << " - "
            << char(MST_iter_i + alpah) << "\t"//cout in chararcter kee form after conversion...;;;
            << "Weight:" << " "
            << int(map_2dmatrix[MST_iter_i][M_S_T_parent_arr[MST_iter_i]])//cout in int form after conversion...;;;
            << endl;



        //iterator for while loop...;;
        MST_iter_i++;


    }



}


//=================================================================================================


//find karna minimum spanning tree ko of undirected graph, prim's algorithm ko istimal karnai kailiyai function...;;;
void primz_algo_MIN_Span_Tree(int map_2dmatrix[N][N])
{

    //initializing...;;
    int x = 0;
    bool chck = false;

    //initializator...;;;
    // pehlay sai banai huai MST ko store knai kailiyai...;;;
    int M_S_T_parent_arr[N];
    // choteee weight edges ko store krnai kailiayai...;;;
    int span_key_vert[N];
    // MST mein jo minkey nhee store hui unkailiayia..;;;
    bool min_span_tree_notinc[N];




    //making key as max_int and span_tree_that is not included as false...;;;
    int iter_I = 0;

    while (N > iter_I)
    {
        span_key_vert[iter_I] = INT_MAX;

        min_span_tree_notinc[iter_I] = false;

        iter_I++;


    }



    //sabsai pehlai MST ko first vertex mein include krtay hain...;;;
    span_key_vert[0] = 0;
    M_S_T_parent_arr[0] = -1;





    // N(size ) for MST...;;;
    int cnt = 0;
    while ((N - 1) > cnt)
    {

        //min key ko pick karnaikailiai from setf of vert.. that are not in MST yet...;;;
        int utah = mineemum_spanning_Key_req(span_key_vert, min_span_tree_notinc);

        // MST set mein picked vertex daalna....;;;;
        min_span_tree_notinc[utah] = true;



        //key kee valuez of adjacenet vertice ko tabdeel krna of picked vertexesiz kai...;;;
        int vert_ind_i = 0;
        while (N > vert_ind_i)
        {
            if (!min_span_tree_notinc[vert_ind_i] && map_2dmatrix[utah][vert_ind_i] && map_2dmatrix[utah][vert_ind_i] < span_key_vert[vert_ind_i])
            {
                M_S_T_parent_arr[vert_ind_i] = utah;
                span_key_vert[vert_ind_i] = map_2dmatrix[utah][vert_ind_i];
            }

            ; vert_ind_i++;
        }


        //count iterator for loop..;;;
        cnt++;
    }

    // MST ko print/display krna parented array ko use krty huai...;;;
    display_min_span_tree(M_S_T_parent_arr, map_2dmatrix);
}



//==================================================================================================


//weighted graph kee minimum spanning tree ko dhundhna kruzkal's algorithm kai zariya...;;;
void algo_kruzkal_Min_Span_Tree(int map_2dmatrix[N][N])
{

    //initializing...;;
    int x = 0;
    bool chck = false;
    //iniatilizer...;;;
    // MST kee bnanai kailiyai arr;;;;
    int M_S_T_parent_arr[N];
    // rank pata karanai kailiyai har element kailiyai array....;;;;
    int ranked_of_elemnt[N];

    // rank or parented array kailiyai initializer... looopp;;;;;;;
    int iter_j = 0;
    while (N > iter_j)
    {
        M_S_T_parent_arr[iter_j] = iter_j;
        ranked_of_elemnt[iter_j] = 0;

        //iterator....;;;;;;
        iter_j++;
    }





    //non-decreasing order mein edges ko sort krna..;;;
    ///simplicity kailiyai bubble sorting....;;;
    int loop_iter_x = 0;

    while (N - 1 > loop_iter_x)
    {
        int j = 0;
        while ((N - loop_iter_x - 1) > j)
        {
            if (map_2dmatrix[j + 1][j] > map_2dmatrix[j][j + 1])
            {
                //swapted....;;;
                swap(map_2dmatrix[j][j + 1], map_2dmatrix[j + 1][j]);

            }


            j++;

        }



        loop_iter_x++;
    }

    int no_edge_cnt = 0;

    //statemented..;;;
    cout << "Minimum Spanning Tree:" << "\n";//........


    int loop_i = 0;
    while (N - 1 > no_edge_cnt && N > loop_i)
    {
        int loop_j = loop_i + 1;
        //fist nested loop...;;;;
        while (N - 1 > no_edge_cnt && N > loop_j)
        {
            if (map_2dmatrix[loop_i][loop_j] != 0)
            {
                int loop_x = loop_i;

                int loop_y = loop_j;

                //2nd nested loop
                // root find kailiyai tree kai using x nd y...;;;
                for (; M_S_T_parent_arr[loop_x] != loop_x;)
                {


                    loop_x = M_S_T_parent_arr[loop_x];



                }

                //3rd nested loop...;;;
                for (; M_S_T_parent_arr[loop_y] != loop_y;)
                {


                    loop_y = M_S_T_parent_arr[loop_y];


                }


                // roots agar same na ho then connect and increase count of edge...;;;
                char alpah = 'A';
                if (loop_x != loop_y)
                {
                    cout << char(loop_i + alpah)//cout in chararcter kee form after conversion...;;;
                        << " - " << char(loop_j + alpah)////cout in chararcter kee form after conversion...;;;
                        << "\t"
                        << "Weight: "
                        << int(map_2dmatrix[loop_i][loop_j])
                        << endl;

                    no_edge_cnt++;



                    if (ranked_of_elemnt[loop_y] < ranked_of_elemnt[loop_x])
                    {

                        M_S_T_parent_arr[loop_y] = loop_x;


                    }

                    else if (ranked_of_elemnt[loop_y] > ranked_of_elemnt[loop_x])
                    {

                        M_S_T_parent_arr[loop_x] = loop_y;

                    }


                    else
                    {
                        M_S_T_parent_arr[loop_y] = loop_x;
                        ranked_of_elemnt[loop_x]++;
                    }
                }
            }


            ; loop_j++;
        }

        loop_i++;
    }



    //endedddd......;;;;;






}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//________________________________________________________________________________________________________________________________