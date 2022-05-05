
#include "Header.h"
int main()
{
    srand(time(NULL));
    DoubleMatrix db;
    cout << "Double Matrix : \n";
    db.show_matrix();
    cout  << "Sum of elements: " << db.Sum() << "  Determinant: " << db.determinant() << "\n\n";
    TripleMatrix tp;
    cout << "Triple Matrix : \n";
    tp.show_matrix();
    cout << "Sum of elements: " << tp.Sum() << "  Determinant: " << tp.determinant() << "\n\n";
    cout << "The result of function is: " << result(db, tp);
}

