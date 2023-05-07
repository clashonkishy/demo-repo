#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the gravitational force between two point masses
vector<double> gravitationalForce(double m1, double m2, double x1, double y1,
                                  double z1, double x2, double y2, double z2) {
  const double G = 6.67430e-11; // gravitational constant
  double r = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) +
                  pow(z2 - z1, 2)); // distance between the two masses
  double f = G * m1 * m2 / (r * r); // gravitational force
  vector<double> force(3);          // vector to hold the gravitational force

  // Calculate the components of the gravitational force vector
  force[0] = f * (x2 - x1) / r;
  force[1] = f * (y2 - y1) / r;
  force[2] = f * (z2 - z1) / r;

  return force; // return the gravitational force vectṭor
}

int main() {
  // Define the parameters of two point masses
  double m1, m2, x1, x2, y1, y2, z1, z2;
  cout << "Enter m1: ";
  cin >> m1;
  cout << "Enter m2: ";
  cin >> m2;
  cout << "Enter x1: ";
  cin >> x1;
  cout << "Enter x2: ";
  cin >> x2;
  cout << "Enter y1: ";
  cin >> y1;
  cout << "Enter y2: ";
  cin >> y2;
  cout << "Enter z1: ";
  cin >> z1;
  cout << "Enter z2: ";
  cin >> z2;

  // Calculate the gravitational force between the two masses
  vector<double> force = gravitationalForce(m1, m2, x1, y1, z1, x2, y2, z2);
  if (isnan(force[0])){
    cout << "Both masses are at the same point.";
  }
  else {
  // Print the components of the gravitational force vector
  cout << "The gravitational force between the two masses is: " << endl;
  cout << "Fx = " << force[0] << " N" << endl;
  cout << "Fy = " << force[1] << " N" << endl;
  cout << "Fz = " << force[2] << " N" << endl;
  }
  return 0;
}
