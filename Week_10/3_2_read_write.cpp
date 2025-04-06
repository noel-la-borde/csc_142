#include <cstdio>

// Reads a character from array at index, with bounds checking
char read_from(char* array, int index, int size) {
    if (index >= 0 && index < size) {
        return array[index];
    } else {
        printf("Read Error: Index %d out of bounds (size %d)\n", index, size);
        return '\0'; // Return null char on error
    }
}

// Writes a character to array at index, with bounds checking
void write_to(char* array, int index, char value, int size) {
    if (index >= 0 && index < size) {
        array[index] = value;
    } else {
        printf("Write Error: Index %d out of bounds (size %d)\n", index, size);
    }
}

int main() {
    char lower[] = "abc?e";             // size = 6 (including null terminator)
    char upper[] = "ABC?E";
    int size = sizeof(lower) / sizeof(lower[0]); // = 6

    char* upper_ptr = upper;            // Equivalent: &upper[0]

    write_to(lower, 3, 'd', size);      // Safe write
    write_to(upper_ptr, 3, 'D', size);  // Safe write

    char letter_d = read_from(lower, 3, size);
    char letter_D = read_from(upper_ptr, 3, size);

    printf("lower: %s\nupper: %s\n", lower, upper);
    printf("letter_d: %c\nletter_D: %c\n", letter_d, letter_D);

    // This would now print an error instead of corrupting memory
    write_to(lower, 7, 'g', size);      // Out-of-bounds write
}