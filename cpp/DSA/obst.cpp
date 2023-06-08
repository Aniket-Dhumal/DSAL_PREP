#include <iostream>
using namespace std;

class node {
public:
   int data;
   node *left_child, *right_child;
   friend class obst;
   
   node(int x) {
      data = x;
      left_child = NULL;
      right_child = NULL;
   }
};

class obst {
public:
   double w[10][10];
   double c[10][10];
   double r[10][10];
   double k;
   node *root;

   obst() {
      root = NULL;
   }

   void calculate_wt(double[], double[], int);
   node *create_tree(int i, int j);

   void displayTable() {
      cout << "----------------------------------------------------" << endl;
      for (int i = 0; i <= 3; i++) {
         cout << "W " << i << "," << i << "= " << w[i][i] << " | "
              << "C " << i << "," << i << "= " << c[i][i] << " | "
              << "R " << i << "," << i << "= " << r[i][i] << endl;
      }

      cout << endl << endl;

      for (int m = 1; m <= 3; m++) {
         for (int i = 0; i <= 3 - m; i++) {
            int j = i + m;
            cout << "W " << i << "," << j << "= " << w[i][j] << " | "
                 << "C " << i << "," << j << "= " << c[i][j] << " | "
                 << "R " << i << "," << j << "= " << r[i][j] << endl;
         }
      }

      cout << "----------------------------------------------------" << endl;
   }
};

void obst::calculate_wt(double *p, double *q, int n) {
   int k;

   for (int i = 0; i <= n; i++) {
      w[i][i] = q[i];
      r[i][i] = 0;
      c[i][i] = 0;

      w[i][i + 1] = q[i] + q[i + 1] + p[i + 1];
      r[i][i + 1] = i + 1;
      c[i][i + 1] = w[i][i + 1];
   }

   for (int m = 1; m <= n; m++) {
      for (int i = 0; i <= n - m; i++) {
         int min = 999;
         int j = i + m;

         w[i][j] = w[i][j - 1] + p[j] + q[j];

         for (int i1 = i + 1; i1 <= j; i1++) {
            int sum1 = c[i][i1 - 1] + c[i1][j];
            if (sum1 < min) {
               min = sum1;
               k = i1;
            }
         }

         c[i][j] = w[i][j] + c[i][k - 1] + c[k][j];
         r[i][j] = k;
      }
   }

   root = create_tree(0, n);
}

node *obst::create_tree(int i, int j) {
   node *t = NULL;
   if (i != j) {
      k = r[i][j];
      t = new node(k);
      t->left_child = create_tree(i, k - 1);
      t->right_child = create_tree(k, j);
      return t;
   }
   else {
      return NULL;
   }
}

int main() {
   obst tree;
   double p[3] = {0.4, 0.1, 0.2};
   double q[4] = {0.1, 0.04, 0.09, 0.07};

   int choice;
   while (true) {
      cout << "Menu:" << endl;
      cout << "1. Calculate Weight Table" << endl;
      cout << "2. Display Table" << endl;
      cout << "3. Exit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice) {
         case 1:
            tree.calculate_wt(p, q, 3);
            cout << "Weight table calculated." << endl;
            break;
         case 2:
            tree.displayTable();
            break;
         case 3:
            cout << "Exiting..." << endl;
            return 0;
         default:
            cout << "Invalid choice. Please try again." << endl;
      }
   }
   return 0;
}
