#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

// Callback function for writing data to a file
size_t write_data(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        // Display help message if incorrect number of arguments
        printf("Usage: myprogram URL output_file_name output_path\n");
        return 0;
    }

    // Get URL, output file name, and output path from arguments
    char *url = argv[1];
    char *output_file_name = argv[2];
    char *output_path = argv[3];

    // Create full path for the output file
    char output_file_path[1024];
    snprintf(output_file_path, sizeof(output_file_path), "%s/%s", output_path, output_file_name);

    // Initialize CURL handle
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error: Failed to initialize CURL handle\n");
        return 1;
    }

    // Set URL to download
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Open output file
    FILE *output_file = fopen(output_file_path, "wb");
    if (!output_file) {
        fprintf(stderr, "Error: Failed to open output file\n");
        curl_easy_cleanup(curl);
        return 1;
    }

    // Set callback function for writing data to the output file
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,
