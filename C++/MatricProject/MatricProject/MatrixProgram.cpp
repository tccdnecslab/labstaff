// This program finds the determinant of a matrix
//  user input up to 10 x 10
//  random number gen -100 to 100


#include <iostream>
#include <cmath>
#include <iomanip>

void displayMatrix(int **, int);
int getDeterminantOfTwoByTwo(int **, int);
long int three(int **, int);
long long int four(int **, int);
long long int five(int **, int);
long long int six(int **, int);
long long int seven(int **, int);
long long int eight(int **, int);
long long int nine(int **, int);
long long int ten(int **, int);
int** createMatrix(int);
using namespace std;

int main()
{
	int **matrix = nullptr;
	int matrixSize = 0;
	char choice = 'Y';
	srand(time(0));
	do
	{
		cout << "Enter the size of the matirx, an integer 2 - 10 inclusive: ";
		cin >> matrixSize;

		matrix = createMatrix( matrixSize);

		for (int row = 0; row < matrixSize; row++)
		{
			for (int col = 0; col < matrixSize; col++)
			{
				int num = rand() % 201 - 100;
				matrix[row][col] = num;
			}

			//if (num == -100 || num == 100)
			//cout << num << endl;
		}
		displayMatrix(matrix, matrixSize);
		cout << endl << "determinant is: " ;

		switch (matrixSize)
		{
			case 2: cout << getDeterminantOfTwoByTwo(matrix, matrixSize);
				break;

			case 3:
				cout << three(matrix, matrixSize);
				break;
			
			case 4:
				cout << four(matrix, matrixSize);
				break;

			case 5:
				cout << five(matrix, matrixSize);
				break;

			case 6:
				cout << six(matrix, matrixSize);
				break;

			case 7:
				cout << seven(matrix, matrixSize);
				break;

			case 8:
				cout << eight(matrix, matrixSize);
				break;

			case 9:
				cout << nine(matrix, matrixSize);
				break;

			case 10:
				cout << ten(matrix, matrixSize);
				break;

		}
		
		delete[] matrix[0];
		delete[] matrix;

		cout << endl << endl << "Do you want to find the determinant of another matrix (Y or N)? ";
		cin >> choice;
		choice = toupper(choice);
		//cout << choice << endl;
		while (choice != 'Y' && choice != 'N')
		{
			cout << "error, you must enter Y or N only. ";
			cin >> choice;
			choice = toupper(choice);
			//cout << choice;
		}

	} while (choice == 'Y');
	return 0;
}

int ** createMatrix(int size)
{
	int ** matrixPtr = nullptr;
	matrixPtr = new int*[size];
	matrixPtr[0] = new int[size * size];
	for (int i = 1; i < size; i++)
		matrixPtr[i] = matrixPtr[i - 1] + size;

	return matrixPtr;

}

void displayMatrix(int **matrix, int size)
{
	for (int row = 0; row < size; row++)
	{
		for (int col = 0; col < size; col++)
		{

			cout << setw(5) << matrix[row][col] << " ";
			if (col + 1 == size)
				cout << endl;
		}

	}
}

int getDeterminantOfTwoByTwo(int **matrix, int size)
{
	int determinant = 0;
	determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	return determinant;
}

long int three(int **matrix, int size)
{
	long int determinant = 0;
	int ** tempMatrix = nullptr;
	tempMatrix = createMatrix(size - 1);
	for (int head = 0; head < size; head++)
	{

		int	tempHeadNum = matrix[0][head];
		int matrixRow = 0;
		int matrixCol = 0;
		for (matrixRow = 1; matrixRow < size; matrixRow++)
		{
			for (matrixCol = 0; matrixCol < size; matrixCol++)
			{

				if (head == 0 && matrixCol != head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && matrixCol < head)
				{
					tempMatrix[matrixRow - 1][matrixCol] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && head < size - 1 && matrixCol > head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}

			}

		}
		if (head == 1)
			determinant -= getDeterminantOfTwoByTwo(tempMatrix, size - 1) * tempHeadNum;
		else if (head == 0 || head % 2 == 0)
			determinant += getDeterminantOfTwoByTwo(tempMatrix, size - 1) * tempHeadNum;
		else 
			determinant -= getDeterminantOfTwoByTwo(tempMatrix, size - 1) * tempHeadNum;
		//cout << endl;
		//displayMatrix(tempMatrix, size-1);
	}
	
	delete tempMatrix[0];
	delete tempMatrix;
	return determinant;
}

long long int four(int **matrix, int size)
{
	long long int determinant = 0;
	int ** tempMatrix = nullptr;
	tempMatrix = createMatrix(size - 1);
	for (int head = 0; head < size; head++)
	{

		int	tempHeadNum = matrix[0][head];
		int matrixRow = 0;
		int matrixCol = 0;
		for (matrixRow = 1; matrixRow < size; matrixRow++)
		{
			for (matrixCol = 0; matrixCol < size; matrixCol++)
			{

				if (head == 0 && matrixCol != head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && matrixCol < head)
				{
					tempMatrix[matrixRow - 1][matrixCol] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && head < size - 1 && matrixCol > head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}

			}

		}
		if (head == 1)
			determinant -= three(tempMatrix, size - 1) * tempHeadNum;
		else if (head == 0 || head % 2 == 0)
			determinant += three(tempMatrix, size - 1) * tempHeadNum;
		else
			determinant -= three(tempMatrix, size - 1) * tempHeadNum;
		//cout << endl;
		//displayMatrix(tempMatrix, size - 1);
	}
	
	delete tempMatrix[0];
	delete tempMatrix;
	return determinant;


}

long long int five(int **matrix, int size)
{
	long long int determinant = 0;
	int ** tempMatrix = nullptr;
	tempMatrix = createMatrix(size - 1);
	for (int head = 0; head < size; head++)
	{

		int	tempHeadNum = matrix[0][head];
		int matrixRow = 0;
		int matrixCol = 0;
		for (matrixRow = 1; matrixRow < size; matrixRow++)
		{
			for (matrixCol = 0; matrixCol < size; matrixCol++)
			{

				if (head == 0 && matrixCol != head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && matrixCol < head)
				{
					tempMatrix[matrixRow - 1][matrixCol] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && head < size - 1 && matrixCol > head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}

			}

		}
		if (head == 1 )
			determinant -= four(tempMatrix, size - 1) * tempHeadNum;
		else if (head == 0 || head % 2 == 0)
			determinant += four(tempMatrix, size - 1) * tempHeadNum;
		else
			determinant -= four(tempMatrix, size - 1) * tempHeadNum;
		//cout << endl;
		//displayMatrix(tempMatrix, size - 1);
	}
	
	delete tempMatrix[0];
	delete tempMatrix;
	return determinant;


}

long long int six(int **matrix, int size)
{
	long long int determinant = 0;
	int ** tempMatrix = nullptr;
	tempMatrix = createMatrix(size - 1);
	for (int head = 0; head < size; head++)
	{

		int	tempHeadNum = matrix[0][head];
		int matrixRow = 0;
		int matrixCol = 0;
		for (matrixRow = 1; matrixRow < size; matrixRow++)
		{
			for (matrixCol = 0; matrixCol < size; matrixCol++)
			{

				if (head == 0 && matrixCol != head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && matrixCol < head)
				{
					tempMatrix[matrixRow - 1][matrixCol] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && head < size - 1 && matrixCol > head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}
			}

		}
		if (head == 1 )
			determinant -= five(tempMatrix, size - 1) * tempHeadNum;
		else if (head == 0 || head % 2 == 0)
			determinant += five(tempMatrix, size - 1) * tempHeadNum;
		else
			determinant -= five(tempMatrix, size - 1) * tempHeadNum;
		//cout << endl;
		//displayMatrix(tempMatrix, size - 1);
	}
	
	delete tempMatrix[0];
	delete tempMatrix;
	return determinant;

} // end six

long long int seven(int **matrix, int size)
{
	long long int determinant = 0;
	int ** tempMatrix = nullptr;
	tempMatrix = createMatrix(size - 1);
	for (int head = 0; head < size; head++)
	{

		int	tempHeadNum = matrix[0][head];
		int matrixRow = 0;
		int matrixCol = 0;
		for (matrixRow = 1; matrixRow < size; matrixRow++)
		{
			for (matrixCol = 0; matrixCol < size; matrixCol++)
			{

				if (head == 0 && matrixCol != head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && matrixCol < head)
				{
					tempMatrix[matrixRow - 1][matrixCol] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && head < size - 1 && matrixCol > head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}

			}

		}
		if (head == 1 || head % 2 != 0)
			determinant -= six(tempMatrix, size - 1) * tempHeadNum;
		else if (head == 0 || head % 2 == 0)
			determinant += six(tempMatrix, size - 1) * tempHeadNum;
		//cout << endl;
		//displayMatrix(tempMatrix, size - 1);
	}
	
	delete tempMatrix[0];
	delete tempMatrix;
	return determinant;


}// end 7

long long int eight(int **matrix, int size)
{
	long long int determinant = 0;
	int ** tempMatrix = nullptr;
	tempMatrix = createMatrix(size - 1);
	for (int head = 0; head < size; head++)
	{

		int	tempHeadNum = matrix[0][head];
		int matrixRow = 0;
		int matrixCol = 0;
		for (matrixRow = 1; matrixRow < size; matrixRow++)
		{
			for (matrixCol = 0; matrixCol < size; matrixCol++)
			{

				if (head == 0 && matrixCol != head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && matrixCol < head)
				{
					tempMatrix[matrixRow - 1][matrixCol] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && head < size - 1 && matrixCol > head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}

			}

		}
		if (head ==1)
			determinant -= seven(tempMatrix, size - 1) * tempHeadNum;
		else if( head == 0 || head % 2 == 0  )
			determinant += seven(tempMatrix, size - 1) * tempHeadNum;
		else
			determinant -= seven(tempMatrix, size - 1) * tempHeadNum;
		
		//cout << endl;
		//displayMatrix(tempMatrix, size - 1);
	}
	
	delete tempMatrix[0];
	delete tempMatrix;
	return determinant;


}// end 8

long long int nine(int **matrix, int size)
{
	long long int determinant = 0;
	int ** tempMatrix = nullptr;
	tempMatrix = createMatrix(size - 1);
	for (int head = 0; head < size; head++)
	{

		int	tempHeadNum = matrix[0][head];
		int matrixRow = 0;
		int matrixCol = 0;
		for (matrixRow = 1; matrixRow < size; matrixRow++)
		{
			for (matrixCol = 0; matrixCol < size; matrixCol++)
			{

				if (head == 0 && matrixCol != head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && matrixCol < head)
				{
					tempMatrix[matrixRow - 1][matrixCol] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && head < size - 1 && matrixCol > head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}

			}

		}
		if (head == 1)
			determinant -= eight(tempMatrix, size - 1) * tempHeadNum;
		else if (head == 0 || head % 2 == 0)
			determinant += eight(tempMatrix, size - 1) * tempHeadNum;
		else
			determinant -= eight(tempMatrix, size - 1) * tempHeadNum;
		//cout << endl;
		//displayMatrix(tempMatrix, size - 1);
	}
	
	delete tempMatrix[0];
	delete tempMatrix;
	return determinant;

}// end 9

 long long int ten(int **matrix, int size)
{
	 long long int determinant = 0;
	int ** tempMatrix = nullptr;
	tempMatrix = createMatrix(size - 1);
	for (int head = 0; head < size; head++)
	{

		int	tempHeadNum = matrix[0][head];
		int matrixRow = 0;
		int matrixCol = 0;
		for (matrixRow = 1; matrixRow < size; matrixRow++)
		{
			for (matrixCol = 0; matrixCol < size; matrixCol++)
			{

				if (head == 0 && matrixCol != head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && matrixCol < head)
				{
					tempMatrix[matrixRow - 1][matrixCol] = matrix[matrixRow][matrixCol];
				}
				else if (head > 0 && head < size - 1 && matrixCol > head)
				{
					tempMatrix[matrixRow - 1][matrixCol - 1] = matrix[matrixRow][matrixCol];
				}

			}

		}
		if (head == 1)
			determinant -= nine(tempMatrix, size - 1) * tempHeadNum;
		else if (head == 0 || head % 2 == 0)
			determinant += nine(tempMatrix, size - 1) * tempHeadNum;
		else
			determinant -= nine(tempMatrix, size - 1) * tempHeadNum;
		//cout << endl;
		//displayMatrix(tempMatrix, size - 1);
	}
	
	delete tempMatrix[0];
	delete tempMatrix;
	return determinant;

}