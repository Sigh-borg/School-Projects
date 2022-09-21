/*  Author: Brian Ngeunjuntr
	Date: 6/26/22
	Class: CIS-2542
	File: Source08.cpp
	Descr:
		Demonstrates a function template and exception handling for the discriminant b^2 - 4ac of the quadratic formula.
*/

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T Discriminant(T a, T b, T c)
{
	T val = (b * b) - (4.0 * a * c);

	if (val >= 0)
	{
		return val;
	}
	else
		throw exception("Discriminant(a, b, c): Negative Discriminant Encountered");
}

int main()
{
	char choice;
	do
	{
		double a, b, c, discriminant;
		cout << "This is the discriminant b^2 - 4ac" << endl;
		cout << "Enter a value for a: ";
		cin >> a;
		cout << "Enter a value for b: ";
		cin >> b;
		cout << "Enter a value for c: ";
		cin >> c;

		try
		{
			// Put only code that can throw in a try block.
			discriminant = Discriminant(a, b, c);
			cout << "The Discriminant is " << fixed << setprecision(2) << discriminant << endl;
		}

		catch (const exception &e)
		{
			cout << e.what();
		}

		do
		{
			cout << "Repeat again? [Y/N]: ";
			cin >> choice;
			choice = toupper(choice);
		} while ((choice != 'Y') && (choice != 'N'));

	} while (choice == 'Y');


	return 0;
}