#include <iostream>
using namespace std;
int main()
{
    int blockSize[] = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};
    int m = sizeof(processSize) / sizeof(processSize[0]);
    int n = sizeof(blockSize) / sizeof(blockSize[0]);
    int allocation[m];
    for (int i = 0; i < m; i++)
    {
        allocation[i] = -1;
    }
    int idx = -1;
    for (int i = 0; i < m; i++)
    {
        idx = -1;
        for (int j = 0; j < n; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (idx == -1)
                {
                    idx = j;
                }
                else if (blockSize[idx] > blockSize[j])
                {
                    idx = j;
                }
            }
        }
        if (idx != -1)
        {
            allocation[i] = idx;
            blockSize[idx] -= processSize[i];
        }
    }
    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < m; i++)
    {
        cout << " " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}