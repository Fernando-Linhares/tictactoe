using namespace std;

namespace Table
{
    class Cell
    {
        private: string content = "    ";

        public: bool selected = false;

        public: string getContent()
        {
            return this->content;
        }

        public: void setContent(string content)
        {
            this->content = content;
        }

        public: bool getSelected()
        {
            return this->selected;
        }

        public: void setSelected(bool selected)
        {
            this->selected = selected;
        }
    };
}