using namespace std;
using namespace Table;
using namespace Players;

bool ends(Cordenates cordenate);

int game(vector<Rows> data, User player1, Boot player2, Cordenates cordenate, int turn)
{
    if(ends(cordenate) && turn > 1) return 0;

    Builder builder;

   system("clear");

    if(builder.finalGame(data)){
        cout << builder.finalFrame(data) << endl;
        return 0;
    }

    cout << builder.render(data) << endl;

    if(turn == 1) {

        cout << "Escolha com que vai jogar ( X ou O )" << endl;

        string usercordenates;

        getline(cin, usercordenates);

        if(!usercordenates.empty()){

            player1.setGame(usercordenates);

            if(usercordenates == "O" || usercordenates ==  "o")
                player2.setGame("X");

            if(usercordenates == "x" || usercordenates ==  "X")
                player2.setGame("O");
        }
    }

    string line, column;

    cout << "Digite as cordenadas necessárias para o jogo" << endl;

    cout << "- Coluna" << endl;
    cin >> column;

    cout << "- Linha" << endl;
    cin >> line;

    cordenate.setLine(line);

    cordenate.setColumn(column);

    vector<Rows> data_modified_by_player1 = player1.play(data, cordenate);

    vector<Rows> data_modified_by_player2 = player2.play(data_modified_by_player1);

    game(data_modified_by_player2, player1, player2, cordenate, turn + 1);

    return 0;
}

bool ends(Cordenates cordenate)
{
    return cordenate.getLine().empty() || cordenate.getColumn().empty();
}