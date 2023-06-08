#include <iostream>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

void koch(int depth, double length, double angle) {
  if (depth == 0) {
    // Draw a straight line segment
    double x1 = 0;
    double y1 = 0;
    double x2 = length * cos(angle);
    double y2 = length * sin(angle);
    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
  } else {
    // Recurse on the four smaller line segments
    koch(depth - 1, length / 3, angle);
    koch(depth - 1, length / 3, angle + PI / 3);
    koch(depth - 1, length / 3, angle - PI / 3);
    koch(depth - 1, length / 3, angle);
  }
}

int main() {
  int depth;
  cin >> depth;

  koch(depth, 1, 0);

  return 0;
}
