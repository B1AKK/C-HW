#include <iostream>
#include "10.1.cpp"

using namespace std;

bool func(ChessField chf1, ChessField chf2)
{
    return (chf1.hor == chf2.hor) || (chf1.vert == chf2.vert) || (chf1.vert - chf2.vert == chf1.hor - chf2.hor);
}

int main()
{
    ChessField chf1, chf2;
    inp_field(&chf1); inp_field(&chf2);
    cout << func(chf1, chf2) << endl;
}
