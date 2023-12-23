class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_map<string, int> umap;
        umap["0#0"] = 1;
        int x = 0;
        int y = 0;
        for(auto c : path)
        {
            switch(c)
            {
                case 'N':
                {
                    y++;
                    break;
                }
                case 'S':  {
                y--;
                break;}

                    case 'E':
                {
                    x++;
                    break;
                }
                case 'W':  {
                x--;
                break;
            }
            }
            ++umap[to_string(x)+"#"+to_string(y)];
            if(umap[to_string(x)+"#"+to_string(y)]>1)
            {
                return true;
            }
        }

        return false;
    }
};