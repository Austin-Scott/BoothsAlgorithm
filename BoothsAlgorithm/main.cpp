#include "Table.h"
#include "toBinaryStrings.h"
#include "Product.h"
#include "inputNumber.h"

using namespace std;

int main() {

	//Creates a table with 4 columns
	Table table(4);

	char keepLooping = 'n';

	do {
		table.clearTable();

		//8-bit signed integers for the multiplicand and the multiplier
		int8_t multiplicand = 0;
		int8_t multiplier = 0;

		cout << "Please enter your 8-bit multiplicand: ";
		multiplicand = inputNumber();
		cout << "Please enter your 8-bit multiplier: ";
		multiplier = inputNumber();

		//Creates a 16-bit product initialized with the value of multiplier.
		//Afterwards, it adds an extra zero bit at the end.
		Product product(multiplier);

		table.addRow({ "Iteration", "Steps", "Multiplicand", "Product" });
		table.addRow({ "0", "Initialization", toBinaryString(multiplicand), toBinaryString(product) });

		for (int i = 0; i < 8; i++) {
			switch (product.getLastTwoBits()) {
			case 1:
				product.add(multiplicand);
				table.addRow({ to_string(i + 1), "Prod=Prod+Mcand", toBinaryString(multiplicand), toBinaryString(product) });
				break;
			case 2:
				product.add(-multiplicand);
				table.addRow({ to_string(i + 1), "Prod=Prod-Mcand", toBinaryString(multiplicand), toBinaryString(product) });
				break;
			default:
				table.addRow({ to_string(i + 1), "No op", toBinaryString(multiplicand), toBinaryString(product) });
			}

			product.arithmeticRightShift();
			table.addRow({ to_string(i + 1), "Product asr 1", toBinaryString(multiplicand), toBinaryString(product) });
		}

		cout << endl << table.getFormattedTable() << endl;
		cout << "Result:" << endl
			<< "\tDecimal: " << product.getValue() << endl
			<< "\tBinary: " << toBinaryString(product.getValue()) << endl << endl;

		cout << "Would you like to enter new values? (y/n) ";
		cin.clear();
		cin >> keepLooping;

	} while (keepLooping == 'y');
}