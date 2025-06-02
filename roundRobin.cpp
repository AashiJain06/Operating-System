#include <iostream>
using namespace std;
int main()
{
  int p[10], bt[10], tat[10], wt[10];
  int n, i, qt, count = 0, temp, sq = 0, rem_bt[10];
  float avgwt = 0, avgtat = 0;
  cout << "enter number of processes";
  cin >> n;
  for (i = 0; i < n; i++)
  {
    cout << "enter process Id";
    cin >> p[i];
    cout << "enter burst time";
    cin >> bt[i];
    rem_bt[i] = bt[i];
  }
  cout << "enter quantum time" << endl;
  cin >> qt;
  while (1)
  {
    for (i = 0, count = 0; i < n; i++)
    {
      temp = qt;
      if (rem_bt[i] == 0)
      {
        count++;
        continue;
      }
      if (rem_bt[i] > qt)
        rem_bt[i] -= qt;
      else if (rem_bt[i] >= 0)
      {
        temp = rem_bt[i];
        rem_bt[i] = 0;
      }
      sq += temp;
      tat[i] = sq;
    }
    if (count == n)
      break;
  }
  cout << "PID        Burst time       Waiting time     Turnaround Time" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << p[i] << "     " << bt[i] << "        " << wt[i] << "         " << tat[i] << "\n";
  }
  for (i = 0; i < n; i++)
  {
    wt[i] = tat[i] - bt[i];
    avgwt += wt[i];
    avgtat += tat[i];
  }
  avgwt /= n;
  avgtat /= n;
  cout << "Average Waiting time :" << avgwt << endl;
  cout << "Average TurnAround  time :" << avgtat << endl;
  return 0;
}