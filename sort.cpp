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
        if (entry->d_type == DT_DIR) // filter folders
        {
            // cout << "Folders: " << entry->d_name << endl; // test
            bridge = entry->d_name;
            transform(bridge.begin(), bridge.end(), bridge.begin(), ::tolower); // to make the string insensitive
            folders.push_back(bridge);
        }
        if (entry->d_type == DT_REG) // filter files
        {
            // cout << "Files : " << entry->d_name << endl; // test
            bridge = entry->d_name;
            transform(bridge.begin(), bridge.end(), bridge.begin(), ::tolower); // to make the string insensitive
            files.push_back(bridge);
        }
        entry = readdir(dir);
    }
    closedir(dir);

    folders = alphabaticalSorting(folders);   // sorting (by defualt false)
    files = alphabaticalSorting(files, true); // sorting (adding true to make it reverse)
    int i = 1,
        j = 1;
    cout << endl;
    cout << "         FOLDERS         " << endl;
    cout << endl;
    for (string x : folders) // printing
    {
        cout << i << ". " << x << endl;
        i++;
    }
    cout << endl;
    cout << "         FILES         " << endl;
    cout << endl;
    for (string x : files) // printing
    {
        cout << j << ". " << x << endl;
        j++;
    }
    return 0;
}