// Ex_2.5.2: Demonstrates the use of dynamic memory alocation
// for classes

#include "Point.hpp"

int main() {

	// Creating an array of Point pointers on the heap
	cout << "1. Creating an array of Point pointers with 3 elements on the heap" << endl;
	Point ** pointArray = new Point*[3];

	// Creating for each element in the array, a Point object on the heap
	cout << "2. Creating for each element in the array a point on the heap." << endl;
	for (int i = 0; i < 3; i++) {
		pointArray[i] = new Point(i, i + 1);
	}
	
	// Print the elements
	cout << "3. Printing the array elements" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "*pointArray[" << i << "]: " << (*pointArray[i]) << endl;
	}

	// Deleting the points
	cout << "4. Deleting each point in the array" << endl;
	for (int i = 0; i < 3; i++) {
		delete pointArray[i];
	}

	// Deleting the array
	cout << "5. Deleting the array" << endl;
	delete[] pointArray;

	// Memory Diagram
	cout << "\nMEMORY DIAGRAM: \n\n";
	cout << "===============       ===============================" << endl;
	cout << "|    STACK     |     |              HEAP             |" << endl;
	cout << "===============       ===============================" << endl << endl;
	cout << " =============        ============         ========== " << endl;
	cout << "| pointArray--|------|-> Point* -|--------|-> (0,1)  |" << endl;
	cout << " =============        ===========          ========== " << endl;
	cout << "                     |   Point* -|--------|-> (1,2)  |" << endl;
	cout << "                      ===========          ========== " << endl;
	cout << "                     |   Point* -|--------|-> (2,3)  |" << endl;
	cout << "                      ===========          ========== " << endl;

	// arrayPoint is a pointer to the head of the array of Points
	// each element in this array points to a Point object
	// Hence, when we delete the objects on the heap, we first need
	// to delete each of the pointers pointing to individual points
	// and then we delete the memory pointed to pointArray

	return 0;
}