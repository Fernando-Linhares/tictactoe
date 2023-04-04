using namespace std;

namespace Table
{
    class Builder
    {
        public:
            string render(vector<Rows> data)
            {
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
        
        public: string finalFrame(vector<Rows> data)
            {
                string playerWinner = winner(data);

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
                        if(cel.getContent() == playerWinner){

                            format += "\033[1;32m" + cel.getContent() + "\033[0m";

                            format += " | ";

                            continue;
                        }

                        format += cel.getContent() + " | ";
                    }

                    format += "\n";
                    format += "        --------------------\n";

                    cordenate++;
                }
                
                format += "Fim de jogo\n";
                format += "Vencedor " +  playerWinner + "\n";

                return format;
            }

            bool finalGame(vector<Rows> data)
            {
                return diagonal(data) || horizontal(data) || vertical(data);
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

            bool horizontal(vector<Rows> data)
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

        public: bool equals(vector<Rows> data, vector<vector<int>> rules)
            {
                string defaultValue = data[rules[0][0]].getCells()[rules[0][1]].getContent();

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

        public: string winner(vector<Rows> data)
            {
               if(horizontal(data)) {
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

                    if(selected(data, horizonalRules[0])){
                        if(equals(data, horizonalRules[0])) {

                           int line =  horizonalRules[0][0][0];

                           int row = horizonalRules[0][0][1];

                           return data[row].getCells()[line].getContent();
                        }
                    }

                    if(selected(data, horizonalRules[1])){

                        if(equals(data, horizonalRules[1])) {

                            int line =  horizonalRules[1][0][0];
                            
                            int row = horizonalRules[1][0][1];
                            
                            return data[row].getCells()[line].getContent();
                        }
                    }
                    

                    if(selected(data, horizonalRules[2])){

                        if(equals(data, horizonalRules[2])) {

                            int line =  horizonalRules[2][0][0];

                            int row = horizonalRules[2][0][1];

                            return data[row].getCells()[line].getContent();
                        }
                    }
               }

               if(vertical(data)) {

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

                    if(selected(data, verticalRules[0])){

                        if(equals(data, verticalRules[0])) {

                           int line =  verticalRules[0][0][0];

                           int row = verticalRules[0][0][1];

                           return data[row].getCells()[line].getContent();
                        }
                    }

                    if(selected(data, verticalRules[1])){

                        if(equals(data, verticalRules[1])) {

                            int line =  verticalRules[1][0][0];
                            
                            int row = verticalRules[1][0][1];
                            
                            return data[row].getCells()[line].getContent();
                        }
                    }
                    

                    if(selected(data, verticalRules[2])){

                        if(equals(data, verticalRules[2])) {

                            int line =  verticalRules[2][0][0];

                            int row = verticalRules[2][0][1];

                            return data[row].getCells()[line].getContent();
                        }
                    }
               }

               if(diagonal(data)){
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
                
                    if(selected(data, diagonalRules[0])){

                        if(equals(data, diagonalRules[0])) {

                           int line =  diagonalRules[0][0][0];

                           int row = diagonalRules[0][0][1];

                           return data[row].getCells()[line].getContent();
                        }
                    }

                    if(selected(data, diagonalRules[1])){

                        if(equals(data, diagonalRules[1])) {

                            int line =  diagonalRules[1][0][0];
                            
                            int row = diagonalRules[1][0][1];
                            
                            return data[row].getCells()[line].getContent();
                        }
                    }
               }

               return "";
            }
    };
}