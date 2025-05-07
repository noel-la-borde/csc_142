#include <cassert>
#include <iostream>

int main() {
    
    auto ok1 = narrow_cast<int>(123); 
    assert(ok1.has_value() && *ok1 == 123);

    auto ok2 = narrow_cast<int>(123.0); 
    assert(ok2.has_value() && *ok2 == 123);

    
    auto fail1 = narrow_cast<int>(123.456);
    assert(!fail1.has_value());

    
    auto fail2 = narrow_cast<unsigned>(-5);
    assert(!fail2.has_value());

    
    auto ok3 = narrow_cast<unsigned>(5);
    assert(ok3.has_value() && *ok3 == 5);

    std::cout << "All tests passed.\n";
    return 0;
}