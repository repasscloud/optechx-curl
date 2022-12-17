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
    if (argc != 2) {
        // Display help message if incorrect number of arguments
        printf("Usage: optxcurl <URL> <output_file_name> <output_path>\n");
        return 0;
    }

    // Get URL, output file name, and output path from arguments
    char *url = argv[1];
    //char *output_file_name = argv[2];
    //char *output_path = argv[3];

    // Initialize CURL handle
    CURL *curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error: Failed to initialize CURL handle\n");
        return 1;
    }

    // Set URL to follow
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set maximum number of redirects to follow
    curl_easy_setopt(curl, CURLOPT_MAXREDIRS, 10);

    // Enable automatic redirection
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1);

    // Perform the request
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Error: Failed to follow URL: %s\n", curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        return 1;
    }

    // Get final URL
    char *final_url = NULL;
    curl_easy_getinfo(curl, CURLINFO_EFFECTIVE_URL, &final_url);
    printf("Final URL: %s\n", final_url);

    // Get HTTP status code of final URL
    long http_code = 0;
    curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
    printf("HTTP status code of final URL: %ld\n", http_code);

    // Clean up CURL handle
    curl_easy_cleanup(curl);

    return 0;
}