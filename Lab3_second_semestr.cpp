
#include "Header.h"

int main()
{
    int len;
    cout << "Enter the number of persons: ";
    cin >> len;
    cin.ignore();
    output(find_happy_dates(create_array(len),len));
}

