#include <iostream>
#include <vector>
#include <algorithm>

struct Goblin {
    int health;
    int strength;

    Goblin(int h, int s) {
        health = h;
        strength = s;
    }

    /*
        overload for sorting in ascending order.

        Issue with this, we can now only sort via health
        and no other param(if present)
    */
    bool operator<(const Goblin& rhs) {
        return this->health < rhs.health;
    }
};

// We can define multiple comparators
struct GoblinComparator {
    bool operator()(const Goblin& a, const Goblin& b) const {
        if (a.health == b.health)
            return a.strength < b.strength;
        return a.health < b.health;
    }
};

int main() {

    /*
        Functors, also known as function objects,
        in C++ are instances of classes/struct that
        overload the function call operator operator().
        This overloading allows objects of these classes/structs
        to be invoked using the same syntax as a regular function,
        hence the term "function object."
    */

    std::vector<Goblin> goblins = {Goblin(2, 10), Goblin(200, 1), Goblin(30, 20)};

    std::sort(goblins.begin(), goblins.end());

    std::cout << "Goblins: " << std::endl;
    for (auto i : goblins) {
        std::cout << i.health << " ";
    }
    std::cout << std::endl;

    std::vector<Goblin> goblins2 = {Goblin(2, 10), Goblin(200, 1), Goblin(30, 20), Goblin(2, 20)};

    std::sort(goblins2.begin(), goblins2.end(), GoblinComparator());

    std::cout << std::endl << "Goblins2: " << std::endl;
    for (auto i : goblins2) {
        std::cout << i.health << " " << i.strength << std::endl;
    }

    return 0;
}