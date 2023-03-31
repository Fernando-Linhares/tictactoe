using namespace std;

namespace Table
{
    class Builder
    {
        public:
            string render(vector<Rows> data)
            {
                if(finalGame(data))
                    return finalFrame(data);

                return normalFrame(data);
            }

        private:
            string normalFrame(vector<Rows> data)
            {
                string format = "            A     B     C    \n";

                format += "        --------------------\n";

                int cordenate = 1;

                for(Rows row : data)
                {
                    format += "  ";
                    format  += to_string(cordenate);
                    format += " -  | ";

                    for(Cell cel : row.getCells())
                    {                
                        format += cel.getContent() + " | ";
                    }

                    format += "\n";
                    format += "        --------------------\n";

                    cordenate++;
                }

                return format;
            }
        
            string finalFrame(vector<Rows> data)
            {
                return "Fim de jogo";
            }

            bool finalGame(vector<Rows> data)
            {
                return diagonal(data) || horicontal(data) || vertical(data);
            }

            bool diagonal(vector<Rows> data)
            {
                vector<vector<vector<int>>> diagonalRules {
                    {
                        { 0, 0 },
                        { 1, 1 },
                        { 2, 2 },
                    },
                    {
                        { 0, 2 },
                        { 1, 1 },
                        { 2, 0 },
                    },
                };

                if(selected(data, diagonalRules[0]))
                    return equals(data, diagonalRules[0]);

                if(selected(data, diagonalRules[1]))
                    return equals(data, diagonalRules[1]);

                return false;
            }

            bool horicontal(vector<Rows> data)
            {
                vector<vector<vector<int>>> horizonalRules {
                    {
                        { 0, 0 },
                        { 0, 1 },
                        { 0, 2 },
                    },
                    {
                        { 1, 0 },
                        { 1, 1 },
                        { 1, 2 },
                    },
                    {
                        { 2, 0 },
                        { 2, 1 },
                        { 2, 2 },
                    },
                };

                if(selected(data, horizonalRules[0]))
                    return equals(data, horizonalRules[0]);

                if(selected(data, horizonalRules[1]))
                    return equals(data, horizonalRules[1]);
                

                if(selected(data, horizonalRules[2]))
                    return equals(data, horizonalRules[2]);

                return false;
            }

            bool vertical(vector<Rows> data)
            {
                vector<vector<vector<int>>> verticalRules {
                    {
                        { 0, 0 },
                        { 1, 0 },
                        { 2, 0 },
                    },
                    {
                        { 0, 1 },
                        { 1, 1 },
                        { 2, 1 },
                    },
                    {
                        { 0, 2 },
                        { 1, 2 },
                        { 2, 2 },
                    },
                };

                if(selected(data, verticalRules[0]))
                    return equals(data, verticalRules[0]);

                if(selected(data, verticalRules[1]))
                    return equals(data, verticalRules[1]);
                
                if(selected(data, verticalRules[2]))
                    return equals(data, verticalRules[2]);

                return false;
            }

            bool selected(vector<Rows> data, vector<vector<int>> rules)
            {
                bool val = false;

                for(vector<int> rule : rules){

                    if(!data[rule[0]].getCells()[rule[1]].getSelected()){
                        val = false;
                        break;
                    }
    
                    val = data[rule[0]].getCells()[rule[1]].getSelected();
                }

                return val;
            }

            bool equals(vector<Rows> data, vector<vector<int>> rules)
            {
                string defaultValue = data[rules[0][0]].getCells()[rules[0][1]].getContent();
                cout << defaultValue;
                bool val = false;

                for(vector<int> rule : rules){

                    if(!(data[rule[0]].getCells()[rule[1]].getContent() == defaultValue)){
                        val = false;
                        break;
                    }

                    val = data[rule[0]].getCells()[rule[1]].getContent() == defaultValue;
                }

                return val;
            }
    };
}