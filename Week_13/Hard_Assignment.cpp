#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;


constexpr double pi = 3.14159265358979323846;

double degrees_to_radians(double degrees) {
    return degrees * (pi / 180.0);
}

int main() {
    double x, y, z;
    double thrust, angle_deg, warp_factor;

    std::cout << "Enter initial coordinates (x, y, z): ";
    std::cin >> x >> y >> z;

    std::cout << "Enter thrust: ";
    std::cin >> thrust;

    std::cout << "Enter angle (in degrees): ";
    std::cin >> angle_deg;

    std::cout << "Enter warp factor: ";
    std::cin >> warp_factor;

    double angle_rad = degrees_to_radians(angle_deg);

    double new_x = (x + thrust * std::cos(angle_rad)) * warp_factor;
    double new_y = (y + thrust * std::sin(angle_rad)) * warp_factor;
    double new_z = z + (thrust / warp_factor);

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "\nNew coordinates after hyperspace jump:\n";
    std::cout << "X: " << new_x << "\n";
    std::cout << "Y: " << new_y << "\n";
    std::cout << "Z: " << new_z << "\n";

    return 0;
}

