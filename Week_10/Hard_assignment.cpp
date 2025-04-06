#include <iostream>
#include <string>
using namespace std;

class MagicItem {
public:
    MagicItem(const std::string& name, const std::string& powerType, int charges)
        : name_{name}, powerType_{powerType}, charges_{charges} {
        std::cout << name_ << " (" << powerType_ << " power) created with " << charges_ << " charges!\n";
    }

    void use() {
        if (charges_ > 0) {
            charges_--;
            std::cout << name_ << " (" << powerType_ << " power) used! Charges left: " << charges_ << "\n";
        } else {
            std::cout << name_ << " (" << powerType_ << " power) has no charges left!\n";
        }
    }

private:
    std::string name_;
    std::string powerType_;
    int charges_;
};

int main() {
    MagicItem sunFlower{"The sun Master", "Sun", 3};
    sunFlower.use();

    MagicItem rose{"The queen of beauty", "Beauty", 2};
    rose.use();
    rose.use();
    rose.use();

    MagicItem grassy{"The green and peaceful land", "Land", 1};
    grassy.use();

    return 0;
}
