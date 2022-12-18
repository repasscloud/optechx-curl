#include <iostream>
#include <fstream>
#include <curl/curl.h>

#include "indicators.hpp"

// get filename from url (should only be used as a fallback)
std::string extract_file_name(const std::string& url)
{
    int i = url.size();
    for (; i >= 0; i--)
    {
        if (url[i] == '/')
        {
            break;
        }
    }

    return url.substr(i + 1, url.size() - 1);
}

bool download(const std::string& url, const std::string& file_path)
{
    const std::string file_name = extract_file_name(url);

    // hide cursor
    indicators::show_console_cursor(false);

    CURL* curl;
    FILE* fp;
    CURLcode res;
    curl = curl_easy_init();
    if (curl)
    {
        fp = fopen(file_path.c_str(), "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0);
        // Perform a file transfer synchronously.
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }

    // Show cursor
    indicators::show_console_cursor(true);

    if (res == CURLE_OK)
    {
        return true;
    }
    else
    {
        return false;
    }
}


// main
int main(int argc, char* argv[])
{
    // define variables for url and output file
    std::string url;
    std::string file_path;

    // convert arguments to defined variables
    if (argc == 2)
    {
        url = std::string{argv[1]};
        file_path = extract_file_name(url);
    }
    else if (argc == 3)
    {
        url = std::string{argv[1]};
        file_path = std::string{argv[2]};
    }
    else
    {
        throw std::invalid_argument{
            "Insufficient arguments. Please provide URL or "
            "URL and destination file path."};
    }

    // Check the number of arguments
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " URL Filename" << std::endl;
        return 1;
    }

    // execute download
    download(url, file_path);
}
