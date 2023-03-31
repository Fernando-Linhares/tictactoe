using namespace std;
using namespace Table;

namespace Players
{
    class User: Player
    {
        private: string game  = "X";

        private: vector<Rows> data;

        public: string getGame()
        {
            return this->game;
        }

        public: void setGame(string game)
        {
            this->game = game;
        }

        public: vector<Rows> play(vector<Rows> data, Cordenates cordenates)
        {
            if ( cordenates.getLine() == "1" )
            {
                if ( cordenates.getColumn() == "A" )
                    data[0].updateCell(0, " "+ this->game +"  ");

                if ( cordenates.getColumn() == "B" )
                    data[0].updateCell(1, " "+ this->game +"  ");

                if ( cordenates.getColumn() == "C" )
                    data[0].updateCell(2, " "+ this->game +"  ");
            }

            if ( cordenates.getLine() == "2" )
            {
                if ( cordenates.getColumn() == "A" )
                    data[1].updateCell(0, " "+ this->game +"  ");

                if ( cordenates.getColumn() == "B" )
                    data[1].updateCell(1, " "+ this->game +"  ");

                if ( cordenates.getColumn() == "C" )
                    data[1].updateCell(2, " "+ this->game +"  ");
            }

            if ( cordenates.getLine() == "3" )
            {
                if ( cordenates.getColumn() == "A" )
                    data[2].updateCell(0, " "+ this->game +"  ");

                if ( cordenates.getColumn() == "B" )
                    data[2].updateCell(1, " "+ this->game +"  ");

                if ( cordenates.getColumn() == "C" )
                    data[2].updateCell(2, " "+ this->game +"  ");
            }

            return data;
        }
    };
}