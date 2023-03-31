using namespace std;
using namespace Table;

namespace Players
{
    struct Player
    {
        protected: string game;

        protected: vector<Rows> data;

        public: string getGame()
        {
            return this->game;
        }

        public: void setGame(string game)
        {
            this->game = game;
        }

        public: vector<Rows> play(vector<Rows> data, string cordenates)
        {
            return data;
        }
    };
}