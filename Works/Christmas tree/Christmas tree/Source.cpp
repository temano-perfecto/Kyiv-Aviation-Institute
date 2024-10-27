#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <cstdlib>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

using namespace std;


string getColorCode(char c)

{
    switch (c) 
    
    {
    case '*': return "\033[32m";
    case '$': return "\033[33m";
    case '%': return "\033[31m";
    case '@': return "\033[34m"; 
    case '&': return "\033[35m";
    default: return "\033[37m"; 
    }
}


const vector<string> originalTree = {
    "       *       ",
    "      ***      ",
    "     $***$     ",
    "       *       ",
    "      *$*      ",
    "     **%%*     ",
    "    @***&**    ",
    "       *       ",
    "      ***      ",
    "     @@*@&     ",
    "    **$**&*    ",
    "   ***@$***%   ",
    "       *       ",
    "      @**      ",
    "     ****$     ",
    "    **&*@%*    ",
    "   &%*%**@*&   ",
    "  ***$**@*%**  ",
    "       *       ",
    "      **@      ",
    "     %*$@*     ",
    "    *&%%%$&    ",
    "   **@&*&*$*   ",
    "  ****&*&*&*&  ",
    " ***$$***@&**@ ",
    "       *       ",
    "       *       "
};


void printTree(const vector<string>& tree, bool lineByLine = true)

{
    for (const string& line : tree)
    
    {
        for (const char& c : line) 
        
        {
            if (c != ' ') 
            
            {
                cout << getColorCode(c) << c << "\033[0m";
            }
            else 
            
            {
                cout << " ";
            }
        }
        cout << endl;
        if (lineByLine)
        
        {
            this_thread::sleep_for(chrono::milliseconds(50)); 
        }
    }
}


void animateTree(int frames)

{
    vector<string> tree = originalTree;

    for (int i = 0; i < frames; ++i) 
    
    {
        system(CLEAR_COMMAND); 

       
        bool lineByLine = i < 10;
        printTree(tree, lineByLine);

        
        for (size_t row = 0; row < tree.size(); ++row) 
        
        {
            for (size_t col = 0; col < tree[row].size(); ++col)
            
            {
                if (tree[row][col] != ' ' && rand() % 5 == 0)
                
                {
                    tree[row][col] = (tree[row][col] == '*') ? originalTree[row][col] : '*';
                }
                else if (rand() % 10 == 0)
                
                { 
                    switch (tree[row][col])
                    
                    {
                    case '*': tree[row][col] = '@'; break;
                    case '@': tree[row][col] = '$'; break;
                    case '$': tree[row][col] = '%'; break;
                    case '%': tree[row][col] = '&'; break;
                    case '&': tree[row][col] = '*'; break;
                    }
                }
            }
        }

        this_thread::sleep_for(chrono::milliseconds(500)); 
    }
}

int main() 

{
    srand(static_cast<unsigned>(time(0))); 
    int frames = 50; 
    animateTree(frames);

    return 0;
}
