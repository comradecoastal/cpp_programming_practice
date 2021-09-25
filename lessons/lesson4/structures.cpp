#include <iostream>
#include <vector>

struct Point {
    double x, y, z;
};

struct Human {
    std::string get_name() {
        return name;
    }
private:
    std::string name = "Niki";
public:
    unsigned age = 12;
};

struct Vect {
    double x, y, z;
};

Vect operator * (Vect a, double lambda) {
    return {a.x * lambda, a.y * lambda, a.z * lambda};
}

Vect operator - (Vect a, Vect b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

std::ostream& operator<<(std::ostream& ostr, const std::vector<int>& nums) {
    ostr << '[';
    for(const auto& number: nums) {
        ostr << number << ' ';
    }
    ostr << ']';
    return ostr;
}

std::istream& operator>>(std::istream& in, std::vector<int> v) {
    for (auto& elem: v) {
        std::cin >> elem;
    }
    return in;
}

int main() {
    Vect a = {3, 0.5, 6};
    Vect b = {1, 3.3, 5.1};
    Vect c = a * 2;

    std::cout << c.x << " " << c.y << " " << c.z << '\n';

    c = a - b;

    std::cout << c.x << " " << c.y << " " << c.z << '\n';

    std::vector<int> balls = {1, 2, 3, 4, 5};
    std::cout << balls << std::endl;

}
