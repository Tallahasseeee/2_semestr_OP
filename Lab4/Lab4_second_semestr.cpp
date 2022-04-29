
#include "Header.h"

int main()
{
    srand(time(NULL));
    vector<int> coefs =  input_coefs();
    Polynom polynom1(coefs[0],coefs[1],coefs[2],coefs[3]);
    cout << "\nPolynom 1:\n";
    polynom1.show_polynom();

    int equal_coef;
    cout << "Enter 1 equal coef: ";
    cin >> equal_coef;
    Polynom polynom2(equal_coef);
    cout << "\nPolynom 2:\n";
    polynom2.show_polynom();

    Polynom polynom3;
    cout << "\nPolynom 3:\n";
    polynom3.show_polynom();

    Polynom polynom4 = polynom1 + polynom2;
    cout << "\nPolynom 4:\n";
    polynom4.show_polynom();

    Polynom polynom5 = polynom2 * polynom3;
    cout << "\nPolynom 5:\n";
    polynom5.show_polynom();

    int x;
    cout << "Enter x: ";
    cin >> x;
    cout << "Polynom 4 in point " << x << " equals: " << polynom4.find_result(x) << "\n";
    cout << "Polynom 5 in point " << x << " equals: " << polynom5.find_result(x);
}

