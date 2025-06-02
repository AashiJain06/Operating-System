#include <iostream>
using namespace std;
int main()
{
  int p[10], bt[10], tat[10], wt[10];
  int n, i, j, temp;
  float avgwt = 0, avgtat = 0;
  cout << "enter number of processes";
  cin >> n;
  for (i = 0; i < n; i++)
  {
    cout << "enter process Id";
    cin >> p[i];
    cout << "enter burst time";
    cin >> bt[i];
  }
  for (i = 0; i < n; i++)
  {
    for (j = 0; j < (n - i - 1); j++)
    {
      if (bt[j] > bt[j + 1])
      {
        temp = bt[j + 1];
        bt[j + 1] = bt[j];
        bt[j] = temp;
        temp = p[j + 1];
        p[j + 1] = p[j];
        p[j] = temp;
      }
    }
  }
  cout << "the exicution order will be:";
  for (i = 0; i < n; i++)
  {
    cout << p[i] << " ";
  }
  cout << endl;
  wt[0] = 0;
  for (i = 1; i < n; i++)
  {
    wt[i] = bt[i - 1] + wt[i - 1];
    avgwt += wt[i];
  }
  for (i = 0; i < n; i++)
  {
    tat[i] = wt[i] + bt[i];
    avgtat += tat[i];
  }
  cout << "PID        Burst time       Waiting time     Turnaround Time";
  for (int i = 0; i < n; i++)
  {
    cout << p[i] << "     " << bt[i] << "        " << wt[i] << "         " << tat[i] << "\n";
  }

  avgwt /= n;
  avgtat /= n;
  cout << "Avrarge Waiting time :" << avgwt << endl;
  cout << "Avrarge TurnAround  time :" << avgtat << endl;
}
