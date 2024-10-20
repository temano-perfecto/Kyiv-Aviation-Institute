#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h> // ��� ���������� ������ � Windows

// ������� ��� �������� ��������
void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

// ������� ��� ������ ������ � ���������
void printWithDelay(const char* str, int delayTime = 50) {
    while (*str) {
        std::cout << *str++;
        std::cout.flush(); // ���������� ������ � �������
        delay(delayTime);
    }
    std::cout << std::endl;
}

// ������� ��� ��������� ����� ������ � ������� (��� Windows)
void setConsoleColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ������� ��� ������� �������
void clearConsole() {
    system("cls");
}

// ������� ��� �������� ������
void animateJump(const char* art[], int artSize, int jumpHeight = 3, int delayTime = 200) {
    for (int i = 0; i < jumpHeight; ++i) {
        clearConsole();
        // ������� �������, ����� "�������" �����
        for (int j = 0; j < jumpHeight - i; ++j) {
            std::cout << std::endl;
        }
        // ������� ������� �����
        for (int j = 0; j < artSize; ++j) {
            std::cout << art[j] << std::endl;
        }
        delay(delayTime);
    }

    for (int i = jumpHeight; i > 0; --i) {
        clearConsole();
        for (int j = 0; j < jumpHeight - i; ++j) {
            std::cout << std::endl;
        }
        for (int j = 0; j < artSize; ++j) {
            std::cout << art[j] << std::endl;
        }
        delay(delayTime);
    }
}


char art[23][70] = {
    "                                  \\\\\\",
    "                                  |||",
    "                         oooo$$$$$$$$$$$$oooo",
    "                      oo$$$$$$$$$$$$$$$$$$$$$$$$o",
    "                   oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o",
    "                 o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o",
    "               o$$$$$$          $$$$$$$          $$$$$$o",
    "              o$$$$$$$$        $$$$$$$$$        $$$$$$$$$o",
    "             $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$",
    "           $$$$$$$$$$$$$$    $$$$$$ $$$$$$    $$$$$$$$$$$$$$",
    "          o$$$$$$$$$$$$$$$ $$$$$$$   $$$$$$$ $$$$$$$$$$$$$$$",
    "          o$$$$$$$$$$$$$$$$$$$$$$     $$$$$$$$$$$$$$$$$$$$$$$",
    "          $$$$$$$$$$$$$$$$$$$$$$       $$$$$$$$$$$$$$$$$$$$$$",
    "          $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\" \"$\"$$",
    "          $$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   o$$",
    "           $$$$    $$$$  \"\"$$$$$$$$$$$$$$$$$\"\"  $$$$   o$$$",
    "            \"$\"$$o         $$$$  $$$$$   $$$          o$$$",
    "               $$$$o   .     \"\"  \"\"\"\"\"   \"\"       .  $$$\"",
    "                \"$\"$$o $$$oo                   oo$$o$$$",
    "                  \"$\"$$$$$$$$    o$$$$   $$$$   $$$$$\"\"",
    "                     \"\"$$$$$$ooo$$$$$ooo$$$$$$$$$\"\"",
    "                        \"\"$$$$$$$$$$$$$$$$$$$$",
    "                                \"\"\"$$$$\"\"\""
};

int artSize = sizeof(art) / sizeof(art[0]);
void GlowingAnimation()
{
    char ReplacementCharacter = '*';
    int StartX = 22, StartY = 7, EndX = 58, EndY = 21;
    /*for (int b = 0; b < artSize; b++)
    {
        for (int g = 0; g < artSize; g++)
        {
            if (b >= StartX && b <= EndX && g >= StartY && g <= EndY)
            {
                if (art[b][g] == ' ')
                {
                    art[b][g] = ReplacementCharacter;
                }
            }

        }
    }*/
    const int rows = 70, cols = 23;

    bool check[cols][rows] =
    {
    "                                  \\\\\\",
    "                                  |||",
    "                         oooo$$$$$$$$$$$$oooo",
    "                      oo$$$$$$$$$$$$$$$$$$$$$$$$o",
    "                   oo$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o",
    "                 o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$o",
    "               o$$$$$$          $$$$$$$          $$$$$$o",
    "              o$$$$$$$$        $$$$$$$$$        $$$$$$$$$o",
    "             $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$",
    "           $$$$$$$$$$$$$$    $$$$$$ $$$$$$    $$$$$$$$$$$$$$",
    "          o$$$$$$$$$$$$$$$ $$$$$$$   $$$$$$$ $$$$$$$$$$$$$$$",
    "          o$$$$$$$$$$$$$$$$$$$$$$     $$$$$$$$$$$$$$$$$$$$$$$",
    "          $$$$$$$$$$$$$$$$$$$$$$       $$$$$$$$$$$$$$$$$$$$$$",
    "          $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\" \"$\"$$",
    "          $$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   o$$",
    "           $$$$    $$$$  \"\"$$$$$$$$$$$$$$$$$\"\"  $$$$   o$$$",
    "            \"$\"$$o         $$$$  $$$$$   $$$          o$$$",
    "               $$$$o   .     \"\"  \"\"\"\"\"   \"\"       .  $$$\"",
    "                \"$\"$$o $$$oo                   oo$$o$$$",
    "                  \"$\"$$$$$$$$    o$$$$   $$$$   $$$$$\"\"",
    "                     \"\"$$$$$$ooo$$$$$ooo$$$$$$$$$\"\"",
    "                        \"\"$$$$$$$$$$$$$$$$$$$$",
    "                                \"\"\"$$$$\"\"\""
    };

    for (int b = 0; b < cols; b++)
    {
        for (int g = 0; g < rows; g++)
        {
            if (check[b][g])
            {
                if (art[b][g] == ' ')
                {
                    art[b][g] == ReplacementCharacter;
                }
            }
        }
    }
}

int main() {



    // ����� ������� � ���������
    for (int i = 0; i < artSize; ++i) {
        printWithDelay(art[i], 17);
    }

    // �������� ������ Ҹ��, � ��� ������ �����������, ��� �����
    //animateJump(art, artSize, 3, 200);

    // ��������� ����� ������ �� ��������� (������� + �������)
    setConsoleColor(6);  // 6 - ��� �����-��������� ����

    // ��������� ����� ����� ��� � ��������� ������
    clearConsole();
    GlowingAnimation();
    for (int i = 0; i < artSize; ++i) {
        std::cout << art[i] << std::endl;
    }


    // ���������� ���� ������� � �������� ���������
    setConsoleColor(7);  // 7 - ����������� ����� ����



    return 0;
}
