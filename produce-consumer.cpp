#include <iostream>
using namespace std;
int wait(int x)
{
  if (x > 0)
    x--;
  return x;
}
int signal(int x)
{
  x++;
  return x;
}
int main()
{
  int a[3];
  int empty = 3;
  int full = 0;
  int mutex = 1;
  int x;
  while (1)
  {
    cout << "Empty:" << empty << "\n"
         << "Full :" << full << "\n";
    cout << "Enter your choice: 1. Produce  2.consume   3.Exit" << endl;
    cin >> x;
    if (x == 1)
    {
      if (empty != 0 && mutex == 1)
      {
        cout << "enter data" << endl;
        empty = wait(empty);
        mutex = wait(mutex);
        cin >> a[full];
        mutex = signal(mutex);
        full = signal(full);
      }
      else
        cout << "Buffer is full" << endl;
    }
    else if (x == 2)
    {
      if (full > 0 && mutex == 1)
      {
        full = wait(full);
        mutex = wait(mutex);
        cout << "Daat is " << a[full] << endl;
        mutex = signal(mutex);
        empty = signal(empty);
      }
      cout << "Buffer is empty" << endl;
    }
    else
      break;
  }
  return 0;
}