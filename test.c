#include <stdio.h>
#include <stdlib.h>

// Function to export data to a file
void export_data(const char *filename, const char **data, size_t data_size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    for (size_t i = 0; i < data_size; i++) {
        fprintf(file, "%s\n", data[i]);
    }

    fclose(file);
    printf("Data exported to %s successfully.\n", filename);
}

int main() {
    // Example data
    const char *data[] = {
        "Line 1: Hello, World!",
        "Line 2: Export command in C",
        "Line 3: Writing to a file"
    };
    size_t data_size = sizeof(data) / sizeof(data[0]);

    // Export the data to a file named "output.txt"
    export_data("output.txt", data, data_size);

    return 0;
}
