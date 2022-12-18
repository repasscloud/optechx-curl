#include <iostream>
#include <fstream>
#include <curl/curl.h>

int main(int argc, char* argv[])
{
    // Check the number of arguments
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " URL Filename" << std::endl;
        return 1;
    }

    // Initialize the curl library
    curl_global_init(CURL_GLOBAL_ALL);

    // Create a curl handle
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Error: Failed to create curl handle." << std::endl;
        return 1;
    }

    // Set the URL to download
    curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

    // Open the output file
    std::ofstream outfile(argv[2], std::ios::binary);
    if (!outfile) {
        std::cerr << "Error: Failed to open output file." << std::endl;
        return 1;
    }

    // Set the write callback function
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](char* ptr, size_t size, size_t nmemb, void* userdata) -> size_t {
        std::ofstream& outfile = *static_cast<std::ofstream*>(userdata);
        outfile.write(ptr, size * nmemb);
        return size * nmemb;
    });

    // Set the user data for the write callback function
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outfile);

    // Perform the download
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
        return 1;
    }

    // Close the curl handle and the output file
    curl_easy_cleanup(curl);
    outfile.close();

    // Clean up the curl library
    curl_global_cleanup();

    return 0;
}
