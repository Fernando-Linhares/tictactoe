using namespace std;
using namespace Table;
using namespace Players;

bool ends(Cordenates cordenate);

int game(vector<Rows> data, User player1, Boot player2, Cordenates cordenate, int turn)
{
    if(ends(cordenate) && turn > 1) return 0;

    Builder builder;

    // system("clear");

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

    vector<Rows> data_modified = player1.play(data, cordenate);

    //data = player2.play(data);

    game(data_modified, player1, player2, cordenate, turn + 1);

    return 0;
}

bool ends(Cordenates cordenate)
{
    return cordenate.getLine().empty() || cordenate.getColumn().empty();
}