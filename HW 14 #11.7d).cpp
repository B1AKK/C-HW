#include <iostream>
#include <cstdio>

using namespace std;

double func(const char* filename)
{
    FILE* f = fopen(filename, "rb");

    double tmp, max = 0;
    while (!feof(f))
    {
        if (fread(&tmp, sizeof(tmp), 1, f) != 1) break;
        if (abs(tmp) > abs(max)) max = tmp;
    }

    fclose(f);
    return max;
}

void inp_file(const char* filename)
{
    FILE* f = fopen(filename, "wb");

    double tmp;
    cin >> tmp;
    while (tmp != 0) {

        fwrite(&tmp, sizeof(tmp), 1, f);
        cin >> tmp;
    }

    fclose(f);
}

int main()
{
    const char filename[32] = "nwakfnew";
    inp_file(filename);
    cout << func(filename) << endl;
}
