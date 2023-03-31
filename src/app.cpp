#include <string>
#include <iostream>
#include <vector>
#include "Table/Cell.h"
#include "Table/Rows.h"
#include "Table/Cordenates.h"
#include "Players/Player.h"
#include "Players/Boot.h"
#include "Players/User.h"
#include "Table/Builder.h"
#include "recursive_game.h"

using namespace std;
using namespace Table;

int game(vector<Rows> data, User player1, Boot player2, Cordenates input, int turn = 1);

int main()
{
    vector<Rows> data_rows;

    Rows row1;
    Rows row2;
    Rows row3;

    Cell c1r1;
    Cell c2r1;
    Cell c3r1;

    vector<Cell> vecrow1;
    vecrow1.push_back(c1r1);
    vecrow1.push_back(c2r1);
    vecrow1.push_back(c3r1);

    row1.setCells(vecrow1);

    Cell c1r2;
    Cell c2r2;
    Cell c3r2;

    vector<Cell> vecrow2;
    vecrow2.push_back(c1r2);
    vecrow2.push_back(c2r2);
    vecrow2.push_back(c3r2);

    row2.setCells(vecrow2);

    Cell c1r3;
    Cell c2r3;
    Cell c3r3;

    vector<Cell> vecrow3;
    vecrow3.push_back(c1r3);
    vecrow3.push_back(c2r3);
    vecrow3.push_back(c3r3);

    row3.setCells(vecrow3);

    data_rows.push_back(row1);
    data_rows.push_back(row2);
    data_rows.push_back(row3);

    User player1;

    Boot player2;

    Cordenates input;

    return game(data_rows, player1, player2, input);
}