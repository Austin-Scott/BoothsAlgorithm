#pragma once
#include <vector>
#include <string>

using namespace std;

class Table {
private:
	//Cell values of the table in Row major ordering
	vector<string> values;
	int numberOfColumns;
public:
	Table(int numberOfColumns);
	void addRow(vector<string> values);
	void clearTable();
	string getFormattedTable();
};