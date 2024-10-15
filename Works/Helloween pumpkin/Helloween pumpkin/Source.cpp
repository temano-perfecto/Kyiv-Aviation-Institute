#include <iostream>
#include <windows.h>
#include <thread>  


void setCursorPosition(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void clearObject(int x, int y)
{
    setCursorPosition(x, y);
    std::cout << " ";
}


void setColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void pumpkin(int x, int y)
{
    setCursorPosition(x, y);
    setColor(6); 
    std::cout << ".,'\n"
        "                                   .'`.'\n"
        "                                  .' .'\n"
        "                      _.ood0Pp._ ,'  `.~ .q?00doo._\n"
        "                  .od00Pd0000Pdb._. . _:db?000b?000bo.\n"
        "                .?000Pd0000PP?000PdbMb?000P??000b?0000b.\n"
        "              .d0000Pd0000P'  `?0Pd000b?0'  `?000b?0000b.\n"
        "             .d0000Pd0000?'     `?d000b?'     `?00b?0000b.\n"
        "             d00000Pd0000Pd0000Pd00000b?00000b?0000b?0000b\n"
        "             ?00000b?0000b?0000b?b    dd00000Pd0000Pd0000P\n"
        "             `?0000b?0000b?0000b?0b  dPd00000Pd0000Pd000P'\n"
        "              `?0000b?0000b?0000b?0bd0Pd0000Pd0000Pd000P'\n"
        "                `?000b?00bo.   `?P'  `?P'   .od0Pd000P'\n"
        "                  `~?00b?000bo._  .db.  _.od000Pd0P~'\n"
        "                      `~?0b?0b?000b?0Pd0Pd000PdP~'\n"
        "                          `~?0b?000b?PdPd000P~'\n";
    setColor(2); 
    std::cout << "                          `'    '\n";
    setColor(7);  
}


void animatePumpkin(int startX, int startY)
{
    int endY = startY - 5; 
    for (int i = 0; i < 5; ++i)
    {
        clearObject(startX, startY);  
        setCursorPosition(startX, startY - i); 
        pumpkin(startX, startY - i);  
        std::this_thread::sleep_for(std::chrono::milliseconds(300));  
    }

    for (int i = 4; i >= 0; --i)
    {
        clearObject(startX, endY + i);
        setCursorPosition(startX, endY + i); 
        pumpkin(startX, endY + i); 
        std::this_thread::sleep_for(std::chrono::milliseconds(300)); 
    }
}

int main()
{
    system("cls");  
    int x = 40, y = 12;
    while (true)
    {
        animatePumpkin(x, y);
    }
    return 0;
}




