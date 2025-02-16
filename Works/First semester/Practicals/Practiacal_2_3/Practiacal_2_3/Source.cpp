#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>  

using namespace std;

void swap(int& a, int& b) 

{
    int temp = a;
    a = b;
    b = temp;
}


void bubbleSort(int arr[], int n, bool ascending = true)

{
    for (int i = 0; i < n - 1; i++)
    
    {
        for (int j = 0; j < n - i - 1; j++)
        
        {
            
            if (ascending)
            
            {
                if (arr[j] > arr[j + 1]) 
                
                {
                    
                    swap(arr[j], arr[j + 1]);
                }
            }
            else
            
            {
                if (arr[j] < arr[j + 1])
                
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}


void printArray(int arr[], int n)

{
    for (int i = 0; i < n; i++)
    
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printVector(vector<int> vec)

{
    for (int i = 0; i < vec.size(); i++)
    
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    int task;
    std::cout << "Enter the task (2-3) you want to run : ";
    std::cin >> task;

    if (task == 2)
    
    {
        srand(static_cast<unsigned>(time(0)));

        int n = 10;
        vector<int> arr1(n);
        for (int i = 0; i < n; i++) 
        
        {
            arr1[i] = rand() % 199 - 99;
        }


        printVector(arr1);

        vector<int> arr2;
        for (int i = 0; i < n; i++)
        
        {
            if (arr1[i] < 0) {
                arr2.push_back(arr1[i]);
            }
        }

        printVector(arr2);

        for (int i = 1; i < arr2.size(); i++)
        
        {
            int element = arr2[i];
            int j = i - 1;
            while (j >= 0 && (arr2[j] < element))
            
            {
                arr2[j + 1] = arr2[j];
                j--;
            }
            arr2[j + 1] = element;
        }

        printVector(arr2);
    }
    else if (task == 3) 
    
    {
        srand(static_cast<unsigned>(time(0)));  

        int m = 10;
        int n = 10; 

        vector<vector<int>> A(m); 

        
        for (int i = 0; i < m; ++i)
        
        {
            A[i].resize(n);
            for (int j = 0; j < n; ++j) 
            
            {
                A[i][j] = rand() % 199 - 99; 
            }
        }

        cout << "Generated sequences:\n";
        for (int i = 0; i < m; ++i)
        
        {
            cout << "Sequence " << setw(2) << i + 1 << ": ";
            for (int value : A[i])
            
            {
                cout << setw(3) << value << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < m; ++i)
        
        {
            bubbleSort(&A[i][0], n);; 
        }

        cout << "Sorted sequences:\n";
        for (int i = 0; i < m; ++i)
        
        {
            cout << "Sequence " << setw(2) << i + 1 << ": ";
            for (int value : A[i])
            
            {
                cout << setw(3) << value << " ";
            }
            cout << endl;
        }
    }
    else
    
    {
        cout << "The task doesn`t exist, try 2-4";
    }
}
