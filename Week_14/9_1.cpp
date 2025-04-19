#include <iostream>
#include <algorithm> 


template <typename Fn, typename In, typename Out>
constexpr Out fold(Fn function, In* input, size_t length, Out initial) {
    for (size_t i = 0; i < length; ++i) {
        initial = function(initial, input[i]);
    }
    return initial;
}

int main() {
    int data[]{ 100, 200, 300, 400, 500 };
    size_t data_len = 5;

    
    auto sum = fold([](auto x, auto y) { return x + y; }, data, data_len, 0);
    std::cout << "Sum: " << sum << "\n";

    auto max_val = fold([](auto x, auto y) { return std::max(x, y); }, data, data_len, data[0]);
    std::cout << "Max: " << max_val << "\n";

    auto min_val = fold([](auto x, auto y) { return std::min(x, y); }, data, data_len, data[0]);
    std::cout << "Min: " << min_val << "\n";

    auto count_gt_200 = fold([](int count, int val) {
        return count + (val > 200 ? 1 : 0);
    }, data, data_len, 0);
    std::cout << "Count > 200: " << count_gt_200 << "\n";

    return 0;
}