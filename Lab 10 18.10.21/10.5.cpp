#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

const unsigned MAX_N = 10000;

struct Peak
{
    char name[256];
    unsigned height;
};

void inp_peak(Peak* p)
{
    cout << "Name: ";
    cin >> p->name;
    do {
        cout << "Height: ";
        cin >> p->height;
    } while (p->height == 0);
}

void print_peak(Peak p)
{
    printf("Name: %s\nHeight: %u\n", p.name, p.height);
}

Peak* inp_peaks(unsigned n)
{
    if (n > MAX_N || n==0) return nullptr;

    Peak* arr = (Peak*)malloc(sizeof(Peak) * n);
    if (!arr) return arr;

    for (int i=0; i<n; i++)
    {
        printf("Peak %d:\n", i+1);
        inp_peak(&arr[i]);
    }
    return arr;
}

void print_peaks(Peak* arr, unsigned n)
{
    for (int i=0; i<n; i++)
    {
        print_peak(arr[i]);
    }
}

void delete_peaks(Peak* arr)
{
    free(arr);
}

char* max_height(Peak* arr, unsigned n)
{
    static char res[256] = "Something went wrong";
    if (n > MAX_N || n==0) return res;
    unsigned max_height = 0;
    for (int i=0; i<n; i++)
    {
        if (arr[i].height > max_height)
        {
            max_height = arr[i].height;
            strncpy(res, arr[i].name, 256);
        }
    }
    return res;
}

int search_name(char* name, Peak* arr, unsigned n)
{
    if (n > MAX_N || n==0) return -1;
    for (int i=0; i<n; i++)
    {
        if (!strcmp(arr[i].name, name))
        {
            printf("Height: %u", arr[i].height);
            return 0;
        }
    }
    cout << "No match found" << endl;
    return 0;
}

int main()
{

    unsigned n;
    cin >> n;
    Peak* arr = inp_peaks(n);
    cout << max_height(arr, n) << endl;
    char name[256];
    cout << "Name to search: ";
    cin >> name;
    search_name(name, arr, n);
    delete_peaks(arr);
}
