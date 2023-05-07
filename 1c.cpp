#include <cmath>
#include <iostream>

class CelestialBody {
public:
  double mass;    // in kg
  double radius;  // in m
  double density; // in kg/m^3
  double x, y, z; // Geocentric Coordinate System

  double getVolume() const { return 4.0 / 3.0 * M_PI * pow(radius, 3); }

  double getSurfaceArea() const { return 4.0 * M_PI * pow(radius, 2); }
};

class Star : public CelestialBody {
public:
  double luminosity;  // in watts
  double surfaceTemp; // in kelvin
  double getBrightness() const {
    return luminosity / (4.0 * M_PI * pow(getDistanceFromEarth(), 2));
  }

  double getDistanceFromEarth() const {
    // for simplicity, assuming Earth is at (0, 0, 0)
    return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  }

  double getOrbitalSpeed(double distance, double planetMass) const {
    // assuming circular orbit
    double gravitationalConstant = 6.67430e-11;
    double orbitalRadius = distance - radius;
    return sqrt(gravitationalConstant * (mass + planetMass) / orbitalRadius);
  }
};

class Planet : public CelestialBody {
public:
  double orbitalRadius; // in m
  int numMoons;

  double getOrbitalPeriod() const {
    double gravitationalConstant = 6.67430e-11;
    return 2.0 * M_PI *
           sqrt(pow(orbitalRadius, 3) / (gravitationalConstant * mass));
  }
};

int main() {
  Star sun;
  sun.mass = 1.989e30;             // kg
  sun.radius = 696340e3;           // m
  sun.density = 1410;              // kg/m^3
  sun.luminosity = 3.828e26;       // watts
  sun.surfaceTemp = 5778;          // kelvin
  sun.x = sun.y = sun.z = 8.63e11; // assume sun is at (, 0, 0)

  Planet earth;
  earth.mass = 5.9722e24;        // kg
  earth.radius = 6371e3;         // m
  earth.density = 5515;          // kg/m^3
  earth.orbitalRadius = 149.6e9; // m
  earth.numMoons = 1;

  double earthOrbitalSpeed =
      sun.getOrbitalSpeed(earth.orbitalRadius, earth.mass);
  std::cout << "Earth's orbital speed around the sun is " << earthOrbitalSpeed
            << " m/s" << std::endl;

  double earthOrbitalPeriod = earth.getOrbitalPeriod();
  std::cout << "Earth's orbital period around the sun is " << earthOrbitalPeriod
            << " seconds" << std::endl;

  double sunBrightness = sun.getBrightness();
  std::cout << "The brightness of the sun as seen from Earth is "
            << sunBrightness << " watts/m^2" << std::endl;

  return 0;
}
