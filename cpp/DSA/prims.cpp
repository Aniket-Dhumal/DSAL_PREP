#include <iostream>
using namespace std;

class Office {
public:
   int n;
   int graph[10][10];
   string office[10];

   void input() {
      cout << "Enter the Number of offices: ";
      cin >> n;
      for (int i = 0; i < n; i++) {
         cout << "Enter Name for Office " << i << ": ";
         cin >> office[i];
      }
      cout << "Enter the Cost to Connect Offices: " << endl;

      for (int i = 0; i < n; i++) {
         for (int j = i; j < n; j++) {
            if (i == j) {
               graph[i][j] = 0;
               continue;
            }
            cout << "Enter the cost to join office " << office[i] << " and " << office[j] << ": ";
            cin >> graph[i][j];
            graph[j][i] = graph[i][j];
         }
      }
   }

   void display() {
      cout << "\nOffice Graph:\n";
      for (int i = 0; i < n; i++) {
         cout << endl;
         for (int j = 0; j < n; j++) {
            cout << graph[i][j] << "\t";
         }
      }
      cout << endl;
   }

   void prims() {
      int minIndex, minCost = 0, cost = 0, visit[n], count = 1;
      for (int i = 0; i < n; i++) {
         visit[i] = 0;
      }
      visit[0] = 1;
      while (1) {
         minCost = 100000;
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
               if (visit[i] == 1 && visit[j] == 0 && graph[i][j] != 0 && graph[i][j] < minCost) {
                  minCost = graph[i][j];
                  minIndex = j;
               }
            }
         }
         visit[minIndex] = 1;
         cost = cost + minCost;
         count++;
         if (count == n) {
            break;
         }
      }
      cout << "Minimum Cost to connect all offices: " << cost << endl;
   }
};

int main() {
   Office office;
   int choice;
   bool exitLoop = false;

   while (!exitLoop) {
      cout << "\n---------- Menu ----------" << endl;
      cout << "1. Input office details" << endl;
      cout << "2. Display office graph" << endl;
      cout << "3. Find minimum cost to connect offices" << endl;
      cout << "4. Exit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice) {
         case 1:
            office.input();
            break;
         case 2:
            office.display();
            break;
         case 3:
            office.prims();
            break;
         case 4:
            exitLoop = true;
            break;
         default:
            cout << "Invalid choice! Please try again." << endl;
      }
   }

   return 0;
}
