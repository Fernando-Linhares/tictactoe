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
            return getCordenates(data);
        }

        public: vector<Rows> getCordenates(vector<Rows> data)
        {
            vector<vector<int>> stackPlays = getStackPlays();

            for(vector<int> play : stackPlays){
                if(!data[play[1]].getCells()[play[0]].getSelected()){
                    data[play[1]].updateCell(play[0], " "+ this->game +"  ");
                    break;
                }
            }

            return data;
        }

        private: vector<vector<int>> getStackPlays()
        {
            return vector<vector<int>> {
                { 0, 0 },
                { 1, 1 },
                { 2, 2 },
                { 0, 2 },
                { 1, 1 },
                { 2, 0 },
                { 0, 0 },
                { 0, 1 },
                { 0, 2 },
                { 1, 0 },
                { 1, 1 },
                { 1, 2 },
                { 2, 0 },
                { 2, 1 },
                { 2, 2 },
                { 0, 0 },
                { 1, 1 },
                { 2, 2 },
                { 0, 2 },
                { 1, 1 },
                { 2, 2 },
            };
        }
    };
}