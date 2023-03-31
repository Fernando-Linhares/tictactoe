using namespace std;

namespace Table
{
    class Rows
    {
        private: vector<Cell> cells;

        public: vector<Cell> getCells()
        {
            return this->cells;
        }

        public: void setCells(vector<Cell> cells)
        {
            this->cells = cells;
        }

        public: void updateCell(int index, string content)
        {
            if(!(index >= this->cells.size())){
                if(!this->cells[index].getSelected()){
                    this->cells[index].setContent(content);
                    this->cells[index].setSelected(true);
                }
            }
        }
    };
}