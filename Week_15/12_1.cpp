#include <optional>
#include <type_traits>

template <typename Target, typename Source>
std::optional<Target> narrow_cast(Source value) {
    Target result = static_cast<Target>(value);
    if (static_cast<Source>(result) != value || 
        (std::is_signed_v<Source> != std::is_signed_v<Target> && (value < 0) != (result < 0))) {
        return std::nullopt; 
    }
    return result;
}