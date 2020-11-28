#include <iostream>
#include <bits/stdc++.h>
#include <dirent.h>
#include <vector>
#include <string>

using namespace std;

bool comp(string a, string b)
{
    return a < b;
}

bool reverseComp(string a, string b)
{
    return a > b;
}

vector<string> alphabaticalSorting(vector<string> a, bool reverse = false)
{
    int size = a.size();
    if (reverse)
        sort(a.begin(), a.end(), reverseComp); // reverse
    else
        sort(a.begin(), a.end(), comp); // noraml
    return a;
}

int main()
{
    vector<string> folders;
    vector<string> files;
    string bridge;
    const char *PATH = "/home/ghandour/Desktop/"; // path here
    DIR *dir = opendir(PATH);
    struct dirent *entry = readdir(dir);
    while (entry != NULL)
    {
        if (entry->d_type == DT_DIR)
        {
            // cout << "Folders: " << entry->d_name << endl; // test
            bridge = entry->d_name;
            transform(bridge.begin(), bridge.end(), bridge.begin(), ::tolower); // to make the string unsenstive
            folders.push_back(bridge);
        }
        if (entry->d_type == DT_REG)
        {
            // cout << "Files : " << entry->d_name << endl; // test
            bridge = entry->d_name;
            transform(bridge.begin(), bridge.end(), bridge.begin(), ::tolower); // to make the string unsenstive
            files.push_back(bridge);
        }
        entry = readdir(dir);
    }
    closedir(dir);
    folders = alphabaticalSorting(folders);   // sorting
    files = alphabaticalSorting(files, true); // sorting
    for (string x : folders)                  // printing
    {
        cout << "Folders: " << x << endl;
    }
    for (string x : files) // printing
    {
        cout << "Files: " << x << endl;
    }
    return 0;
}