#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // check correct number of args is provided
    if (argc != 3)
    {
        printf("USAGE:\n======\n\noptxcurl <url> <outputdir>");
        return 0;
    }

    CURL *curl;
    CURLcode res;
    char output_path[256];  // buffer for the output path, windows limit

    // concat dir and filename
    snprintf(output_path, sizeof(output_path), "%s/%s",
        argv[2], strrchr(argv[1], '/') + 1);

        curl = curl_easy_init();
        if(curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, argv[1]);

            // set output path
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, NULL);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fopen(output_path, "wb"));

            res = curl_easy_perform(curl);
            /* check for errors */

            curl_easy_cleanup(curl);
        }
    return 0;
}