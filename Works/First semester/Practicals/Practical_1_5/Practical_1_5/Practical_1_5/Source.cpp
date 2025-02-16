#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void initRandomizer() 

{
    
    srand(time(0));
}

int main() 

{
    int task;
    cout << "Enter the task (1-3) you want to run : ";
    cin >> task;


    if (task == 1)
    
    {
        initRandomizer();

        int n;
        cout << "Enter the length of the sequence: ";
        cin >> n;

        int* arr = new int[n];
        for (int i = 0; i < n; i++)
        
        {
            arr[i] = rand() % 100;
        }

        for (int i = 0; i < n; i++)
        
        {
            cout << arr[i] << " ";
        }
        
        cout << endl;

        int index = -1;

        int target;
        cout << "Enter the targeted number: ";
        cin >> target;

        for (int i = 0; i < n; i++)
        
        {
            if (arr[i] == target) 
            
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        
        {
            cout << "The index of " << target << " is " << index << endl;
        }
        else 
        
        {
            cout << "The number " << target << " isn`t located in array" << endl;
        }

        delete arr;
    }
    else if (task == 2)
    
    {

        initRandomizer();

        int n;
        cout << "Enter the length of the sequence: ";
        cin >> n;

        int* arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = (rand() % 100) - 50;
        }

        for (int i = 0; i < n; i++)
        
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        int min = 50;
        for (int i = 1; i < n; i++)
        
        {
            if (arr[i] < min && arr[i] >= 0) 
            
            {
                min = arr[i];
            }
        }

        cout << "The minimum value in the sequence is: " << min << endl;

        delete arr;

    }
    else if (task == 3)
    
    {

        initRandomizer();

        int n;
        cout << "Enter the length of the sequence: ";
        cin >> n;

        int* arr = new int[n];

        for (int i = 0; i < n; i++)
        
        {
            arr[i] = rand() % 100;
        }

        for (int i = 0; i < n; i++)
        
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        int min = arr[0];
        int indexMin = 0;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                indexMin = i;
            }
        }

        cout << "The minimum value in the sequence is: " << min << endl;
        cout << "The index of minimum value in the sequence is: " << indexMin << endl;

        int max = arr[0];
        int indexMax = 0;
        for (int i = 1; i < n; i++) 
        {
            if (arr[i] > max)
            {
                max = arr[i];
                indexMax = i;
            }
        }

        cout << "The maximum value in the sequence is: " << max << endl;
        cout << "The index of maximum value in the sequence is: " << indexMax << endl;

        int temp = arr[indexMin];
        arr[indexMin] = arr[indexMax];
        arr[indexMax] = temp;

        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;

        delete[] arr;
        arr = nullptr;
    }
    else
    {
        cout << "The task doesn`t exist. Try task 1-3.";
    }

}