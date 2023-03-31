using namespace std;

namespace Players
{
    class Boot: Player
    {
        protected: string game  = "O";

        protected: vector<Rows> data;

        public: string getGame()
        {
            return this->game;
        }

        public: void setGame(string game)
        {
            this->game = game;
        }

        public: vector<Rows> play(vector<Rows> data)
        {
            return data;
        }
    };
}