using namespace std;

namespace Table
{
    class Cordenates
    {
        private: string line;

        private: string column;

        public: string getLine()
        {
            return this->line;
        }

        public: void setLine(string line)
        {
            this->line = line;
        }

        public: string getColumn()
        {
            return this->column;
        }

        public: void setColumn(string column)
        {
            this->column = column;
        }
    };
}