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
#include"variable.h"
using namespace std;

//node ka structuring...;;;;;
struct AVL_tree_Noded
{

    int height;
    int enemy;
    int reward;

    int id;
    int count;
    int score;

    AVL_tree_Noded* forwarded;
    AVL_tree_Noded* backwarded;
};

//height ko find karnai ka noded...;;;;;
int AVL_Height(AVL_tree_Noded* temp_noded)
{
    if (temp_noded == nullptr)
    {

        return 0;

    }

    int subst = temp_noded->height;
    return subst;
}

// balacing factore node ka find karnai kailiyai function...;;;;
int AVL_stableity_balance(AVL_tree_Noded* temp_node)
{
    if (!(temp_node != nullptr))
    {

        return 0;

    }

    int xz = AVL_Height(temp_node->forwarded) - AVL_Height(temp_node->backwarded);
    return xz;
}

// rotation at right...;;;;;


AVL_tree_Noded* AVL_right_rotation(AVL_tree_Noded* temp_noded)
{


    AVL_tree_Noded* child_at_left = temp_noded->forwarded;
    AVL_tree_Noded* RighT_0f_LephT_ChilDed = child_at_left->backwarded;

    child_at_left->backwarded = temp_noded;
    temp_noded->forwarded = RighT_0f_LephT_ChilDed;
    int k = 1;
    temp_noded->height = max(AVL_Height(temp_noded->forwarded), AVL_Height(temp_noded->backwarded)) + k;
    child_at_left->height = max(AVL_Height(child_at_left->forwarded), AVL_Height(child_at_left->backwarded)) + k;

    //returning..;;;;;
    return child_at_left;
}

// lepht rotation of node in AVL tree....;;;;
AVL_tree_Noded* AVL_lepht_rotation(AVL_tree_Noded* temp_noded)
{
    AVL_tree_Noded* rightChild = temp_noded->backwarded;
    AVL_tree_Noded* leftOfRightChild = rightChild->forwarded;

    rightChild->forwarded = temp_noded;
    temp_noded->backwarded = leftOfRightChild;


    int k = 1;
    temp_noded->height = max(AVL_Height(temp_noded->forwarded), AVL_Height(temp_noded->backwarded)) + k;
    rightChild->height = max(AVL_Height(rightChild->forwarded), AVL_Height(rightChild->backwarded)) + k;

    //returning..;;;;
    return rightChild;
}

// Function to create a new node
AVL_tree_Noded* Node_creating(int identification, int numbering, int scorer, int dushman, int prize)
{
    AVL_tree_Noded* temp_noded = new AVL_tree_Noded();

    temp_noded->score = scorer;
    temp_noded->enemy = dushman;
    temp_noded->reward = prize;

    temp_noded->id = identification;
    temp_noded->count = numbering;

    temp_noded->height = 1;
    temp_noded->forwarded = nullptr;
    temp_noded->backwarded = nullptr;


    //returnation..;;;;;
    return temp_noded;
}

// Function to insert a node into the tree

AVL_tree_Noded* inzertion(AVL_tree_Noded* temperory_node, int identification, int numbering, int scorer, int opponent, int prize)
{


    if (!(temperory_node != nullptr))
    {
        return Node_creating(identification, numbering, scorer, opponent, prize);
    }


    if (temperory_node->id < identification)
    {
        ///recursively looping our way...;;;;;;
        temperory_node->backwarded = inzertion(temperory_node->backwarded, identification, numbering, scorer, opponent, prize);

    }

    else if (temperory_node->id > identification)
    {
        //recursively looping or way...;;;;
        temperory_node->forwarded = inzertion(temperory_node->forwarded, identification, numbering, scorer, opponent, prize);

    }


    else
    {
        temperory_node->count += numbering;
        temperory_node->score += scorer;
        return temperory_node;
    }


    int k = 1;
    temperory_node->height = max(AVL_Height(temperory_node->forwarded), AVL_Height(temperory_node->backwarded)) + k;

    int stabled = AVL_stableity_balance(temperory_node);

    // LLC..;;;;
    if (stabled > 1 &&  identification < temperory_node->forwarded->id  )
    {

        return AVL_right_rotation(temperory_node);

    }



    // RLC...;;;
    if (stabled < -1 &&  identification < temperory_node->backwarded->id  )
    {

        temperory_node->backwarded = AVL_right_rotation(temperory_node->backwarded);
        return AVL_lepht_rotation(temperory_node);


    }


    // LRC..;;;
    if ( stabled > 1 &&  identification > temperory_node->forwarded->id )
    {
        temperory_node->forwarded = AVL_lepht_rotation(temperory_node->forwarded);
        return AVL_right_rotation(temperory_node);
    }

    // RRC..;;;;
    if (stabled < -1 && identification > temperory_node->backwarded->id )
    {
        return AVL_lepht_rotation(temperory_node);
    }




    return temperory_node;
}

//get functioning...;;;
//minimum value find karnai kailiay...;;;
AVL_tree_Noded* MIN_VALUE_get(AVL_tree_Noded* new_subst_node)
{
    AVL_tree_Noded* present_ = new_subst_node;
    for (; present_->forwarded != nullptr; )
    {
        present_ = present_->forwarded;
    }

    //returning..;;;
    return present_;
}




//score ko print karnai kailiyai...;;;;
void display_in_order(AVL_tree_Noded* new_temper_node, int opponent, int prize)
{
    if (!(new_temper_node != nullptr))
    {
        return;
    }

    display_in_order(new_temper_node->forwarded, opponent, prize);

    cout << "\n" << "-----------Initial Scores of the ID: "
        << new_temper_node->id << "--------------------"
        << endl;

    cout << "ID: "
        << new_temper_node->id
        << ", Score: "
        << new_temper_node->score
        << endl;

    if (opponent == 0 || opponent == 9 || opponent == 7 || opponent == 10 || opponent == 2)
    {

        cout << "Great! you escaped from enemies";
        cout << endl;
        if (prize == 0 || prize == 9 || prize == 2 || prize == 10 || prize == 7)
        {
            cout << "no jewel or crystals were found" << endl;

        }


        if (prize == 1 || prize == 5 || prize == 7 || prize == 6 || prize == 4)
        {
            cout << "WOOW ! you found jewel" << endl;//congaratujulationz.........;;;;;;
            cout << "ID: "
                << new_temper_node->id
                << ", Score: "
                << new_temper_node->score + 10
                << endl;

            new_temper_node->score = new_temper_node->score + 10;



        }

    }


    else if (opponent == 1 || opponent == 5 || opponent == 3 || opponent == 8 || opponent == 6 || opponent == 4)
    {
        //omg...;;;;;;;; ......i am sqaureddd...;;;;;
        cout << "oh no!! you encountered an enemy" << endl;
        cout << "ID: "
            << new_temper_node->id
            << ", Score: "
            << new_temper_node->score - 10
            << endl;




        new_temper_node->score = new_temper_node->score - 10;

        if (prize == 1 || prize == 5 || prize == 3 || prize == 7 || prize == 6 || prize == 4)
        {
            cout << "WOOW ! you found jewel" << endl;
            cout << "ID: "
                << new_temper_node->id
                << ", Score: "
                << new_temper_node->score + 10
                << endl;


            new_temper_node->score = new_temper_node->score + 10;
        }
        if (prize == 0 || prize == 2 || prize == 9 || prize == 10 || prize == 7)
        {
            cout << "Well,You also didn't found any jewel" << endl;
        }



        display_in_order(new_temper_node->backwarded, opponent, prize);




    }



}


//======================================================================================================================
void displaying(AVL_tree_Noded* new_temp_noded)
{

    if (new_temp_noded == nullptr)
    {
        //exit....;;;;
        return;

    }

    //recursively...calling as loop....;;;;;
    displaying(new_temp_noded->forwarded);

    // cout << "\n------------Final Scores of the ID: " << node->id << "--------------------" << endl;
    cout << "ID: " << new_temp_noded->id << ", Score: " << new_temp_noded->score << endl;



    //recursively____calling..;;;;
    displaying(new_temp_noded->backwarded);
}