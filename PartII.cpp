#include "init.h"
#include "basicFunctions.h"
#include "searchFunctions.h"
#include "PartII.A.h"
#include "PartII.B.h"
#include <string.h>
#include <ostream>
using namespace std;

ifstream DataFile("Data(Edited).txt");
Row dataArray[NUMOFENTRIES];
Region regionArray[NUMOFREGIONS];
vector<Node> nodeVector(NUMOFREGIONS);

int main() {
	readFile(DataFile, dataArray);
	DataFile.close();
	
	// make region array
	makeRegionArray(regionArray, dataArray);
    calcTotalBirths(regionArray);
    calcTotalDeaths(regionArray);
	
	string inputTxt;
	cout << "Load data on Binary Search Tree or Hash table? [bst/hash]: ";
	cin >> inputTxt;
	if (inputTxt.compare("bst") == 0) {
		// Make node vector
		nodeVector = makeNodeVector(regionArray);
		cout << "Binary Search Tree key? [region/births]";
		cin >> inputTxt;
		if (inputTxt.compare("region") == 0) {
			// Make tree with regions
			makeTree(nodeVector, "region");
			while (PartIIA(regionArray, nodeVector) != 0) {}	
		} else if (inputTxt.compare("births") == 0) {
			// Make tree with births
			makeTree(nodeVector, "births");
			while (PartIIB(nodeVector) != 0) {}
		}
	} else if (inputTxt.compare("hash") == 0) {
		//PartII.C
	} else {
		cout << "Option '" << inputTxt << "' not found!" << endl;
	}

	return 0;
}