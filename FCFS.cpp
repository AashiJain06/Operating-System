#include <iostream>
using namespace std;
int main()
{
  int p[10], bt[10], wt[10], tat[10];
  int n;
  float avgwt = 0, avgtat = 0;
  cout << "enter number of processes";
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cout << "enter process";
    cin >> p[i];
    cout << "enter burst time";
    cin >> bt[i];
  }
  wt[0] = 0;
  for (int i = 1; i < n; i++)
  {
    wt[i] = bt[i - 1] + wt[i - 1];
    avgwt += wt[i];
  }
  for (int i = 0; i < n; i++)
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