# include <iostream>
#include<string>
#include<sstream>

/* ������� �������� ��������� ������������� ���-�� ����� (��� ������ 1). ����� (�� ���-�� ���� ����) � �� ������, � �������� ��������� 
��������������� � main{}, �� ��� ����������� ��������� �� ��������, � �������� ������ ��������� ��������*/
short input_Validation(short quantity) { 
	while (quantity < 1 || quantity > 5) {
		std::cout << "Input error! Enter the quantity of numbers (from 1 to 5) -> ";
		std::cin >> quantity;
	}
	return quantity;
}

// ������� � ����������� �� ��������� ��� ������� ����� ����� (��� ������ 1)
double sum(double num_1, double num_2 = 0, double num_3 = 0, double num_4 = 0, double num_5 = 0 ) {
	return num_1 + num_2 + num_3 + num_4 + num_5;
}

// ������������ ������� ������� �������� ��������������� ���������� ����� (��� ������ 2)
inline double arithmetic_Mean(double num_1, double num_2, double num_3) {
	return (num_1 + num_2 + num_3) / 3;
}

// ��������� ��������� ���������� ������� ���� ������ T (��� ����� 2 � 4)
template <typename T>
void array_Filling(T arr[], const short length) {
	for (short i = 0; i < length; i++) { // ���� ����� ������������� ����� (���������� ������� �����)
		std::cout << "Enter the number N " << i + 1 << " -> ";
		std::cin >> arr[i];
	}
}

// ������������� ��������� ��� ������� ���������� ������������� �������� ��������� ����� (��� ������ 3)
void max_Element(double arr[], const short length) {
	double max = arr[0];
	for (short i = 1; i < length; i++)
		if (arr[i] > max)
			max = arr[i];
	std::cout << "\n\033[92mMaximum of " << length << " double elements is " << max << "\033[0m\n\n";
}
void max_Element(short arr[], const short length) {
	short max = arr[0];
	for (short i = 1; i < length; i++)
		if (arr[i] > max)
			max = arr[i];
	std::cout << "\n\033[92mMaximum of " << length << " short elements is " << max << "\033[0m\n\n";
}
void max_Element(int arr[], const short length) {
	int max = arr[0];
	for (short i = 1; i < length; i++)
		if (arr[i] > max)
			max = arr[i];
	std::cout << "\n\033[92mMaximum of " << length << " integer elements is " << max << "\033[0m\n\n";
}

template <typename T> // ��������� ��������� ��� ������ �������
void print_Array(T arr[], const short length) {
	std::cout << "\nSource array is: ";
	for (short i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b \n";
}

template <typename T> // ��������� ������� ��� ������ ������� �������� ����� � �������
T number_Simple(T arr[], const short length) {
	T number = 0; // ���������� ��� �������� ������� �������� �����
	for (short i = 0; i < length; i++) {
		if (number) // ���� ������ ������� ����� �������, �� ��������� ����
			break;
		int counter = 0;
		for (short j = 2; j <= arr[i]; j++) { // � 2 ������ ��� �� 1 ������� ����� �����
			if (arr[i] % j == 0 && arr[i]>0) // ���������, ��� ������� ����� ������ ���� �������������
				counter++;
			if (counter > 1) // ���� ����� ��������� ������ ������ (� �������� 2), �� ��������� ����
				break;
			if (arr[i] == j && arr[i] > 0)
				number = arr[i];
		}
	}
	return number;
}

template <typename T> // ��������� ��������� ��� ������ ������� �������� ����� � �������
void print_Simple_Number(T number) {
	if (number)
		std::cout << "\n\033[92mFirst simple number in array is " << number << "\033[0m\n\n";
	else
		std::cout << "\n\033[92mThere are no simple numbers in the array\033[0m\n\n";
}


int main() {

	// ������ 1. ����� ������� ���������� (�� 1 �� 5) �����
	short quantity; // ���������� ��� �������� ���-�� �����
	std::cout << "\033[91mTask 1. The sum of a different number (from 1 to 5) of numbers\033[0m\n\nEnter the quantity of numbers (from 1 to 5) -> ";
	std::cin >> quantity;
	if (quantity < 1 || quantity > 5) // �������� ��������� ������������� ���-�� �����
		quantity = input_Validation(quantity);
	double* array = new double[quantity]; // ��������� ������ ��� ������������ ������, ������ �������� = ���-�� �����, �������� �������������
	for (short i = 0; i < quantity; i++) { // ���� ����� ������������� ���������� ���-�� ����� (���������� ������������� �������)
		std::cout << "Enter the number N " << i + 1 << " -> ";
		std::cin >> array[i];
	}
	std::cout << "\n\033[92mThe sum of the entered numbers is ";
	switch (quantity) { // ����������� ��� ������ ���������� ���������� � ����������� �� ��������� ������������� ���-�� �����
	case 1:
		std::cout << sum(array[quantity-1]) << "\033[0m\n\n";
		break;
	case 2:
		std::cout << sum(array[quantity-2], array[quantity-1]) << "\033[0m\n\n";
		break;
	case 3:
		std::cout << sum(array[quantity - 3], array[quantity - 2], array[quantity-1]) << "\033[0m\n\n";
		break;
	case 4:
		std::cout << sum(array[quantity - 4], array[quantity - 3], array[quantity-2], array[quantity-1]) << "\033[0m\n\n";
		break;
	case 5:
		std::cout << sum(array[quantity - 5], array[quantity - 4], array[quantity - 3], array[quantity - 2], array[quantity-1]) << "\033[0m\n\n";
		break;
	}
	delete[] array; // ������ ������ �� ������������ �������

	// ������ 2. ������������ ������� ��� ���������� �������� ��������������� 3-�� �����
	std::cout << "\033[91mTask 2. Arithmetic mean of three numbers\033[0m\n\n";
	const short size = 3; // ������ ������� �����
	double arr[size]{}; // ��������� ������ �����
	array_Filling(arr, size); // ��������� ������ �������
	std::cout << "\n\033[092mThe arithmetic mean of three entered numbers is " << arithmetic_Mean(arr[0], arr[1], arr[2]) << "\033[0m\n\n";

	// ������ 3. ������������ �� ��� �����
	 
		// ������� ������� 1: ��������� ��������� ��� ������ ����� ������� ����� ������������� ��������
	std::cout << "\033[91mTask 3. Maximum of three numbers\033[0m\n\n";	
	bool key_Mistake = false; // ��������� � �������������� ���������� ��� �������� ���� ������
	std::string data_Type{}; // ��������� ��������� ���������� ��� �������� �������� ���� ������
	const short length = 3; // ��������� � �������������� ������ ������� ����� (3 �� ������� ������)	
	std::string arr_Text[length]{}; // ��������� ������ �����, � ������� ����� ���������� ��, ��� ������ ������������
	for (short i = 0; i < length; i++) { // ���� ���������� ������� �����
		if (key_Mistake) // ���� ��� ������ true (������������ ������ ��� ����� �����), ��
			break; // ��� ������ ������ ������� ����
		std::cout << "Enter the number N " << i + 1 << " -> ";
		std::cin >> arr_Text[i];
		short line_size = std::size(arr_Text[i]); // ��������� � �������������� ���������� ��� �������� ����� ������� ������������� ������ ��� ������������ ������������� � �����
		short counter_Point = 0; // ��������� ���������� ��� �������� �������� �������� �����
		for (short j = 0; j < line_size; j++) { // ���� �������� �������� ������������� �������� ������� ������
			char value = int(arr_Text[i][j]); // � ��������� ���������� ���������� ��� �� ASCII-������� �������� ������� ������� ������ 
			// ���� ������ �� �����, �� ����� (����� �������� �������), �� ������� ������ "�����" �� 
			if (value < 45 || value == 47 || value > 57 || (value == 45 && j != 0) || (value == 46 && j == 0)) { 
				key_Mistake = true;	// ����������� ��� ������, �.� �������� ������������� ������ ����� �� �����
				break; // ���������� ������ �����, �.�. ��� ������ � ���������� �������� �������� ������������� ��������
			}
			else
				if (value == 46) // ������� ���-�� ����� � ������� ������
					counter_Point++;
			if (counter_Point > 1) { // ���� �������� ����� � �������� ������������� ������ ����� 1 (�������� ������� ����� �� �����), �� 
				key_Mistake = true; // ����������� ��� ������
				break; // ���������� ������ �����, �.�. ��� ������ � ���������� �������� ��������
			}
		}
	}
	if (key_Mistake) // ���� �������� ������� �� �����
		std::cout << "\n\033[92mOne or more of the numbers entered are not a number!\033[0m\n\n"; // ����� ���������� � �������
	else { // ���� ������� ������� �����
		for (short i = 0; i < length; i++) { // ���� �������� ����� ������� �� ������������ ���� ������ double
			if (data_Type == "double") // ���� ����� ������ ����� ������ ������� �������� ������� ������������� ����� (�����), ��
				break; // ��� ������ � ���������� �������� (��� ��� �������� ������������� ������ ������� ����� ������ double)
			short line_size = std::size(arr_Text[i]); // ��������� � �������������� ���������� ��� �������� ����� ������� ������������� ������ ��� ������������ ������������� � �����
			for (short j = 1; j < line_size; j++) // ���� �������� ������� ������ ������� �� ������� ������������� ����� (�����)
				if (arr_Text[i][j] == 46) { // ���� � ������� ������ ������� ���� ����� (����� ������������), ��
					data_Type = "double"; // ���������� ������� ���� ������ �
					break; // ��������� ����
				}				
		}
		if (data_Type == "double") { // ����������� ��� ������������ ������� ������������� ���� ������
			double arr_Max[length]{}; // ��������� ������ ���� ������ double �� �������� data_Type
			for (short i = 0; i < length; i++) // ���� ������������ ������� ���� ������ double
				arr_Max[i] = stod(arr_Text[i]); // � ������� ������� ������� double ���������� ������� �������� �������� ������� string
			max_Element(arr_Max, length);
		}
		else { // ����������� ��� ������������ ������� ������������� ����� ������			
			for (short i = 0; i < length; i++) { // ���� �������� ������������ ������ ������� string ����������� ����� ������ integer � short
				long long number = stoll(arr_Text[i]); // ��������� ����������� ��������� ������������� ��������� ���������� � �������������� � ������� ��������� ������� string
				if (number > 2147483647 || number < -2147483648) { // ���� ������� ������� ������� string ������� �� �������� integer, ��
					std::cout << "\n\033[92One or more of the numbers entered are not a type \'integer\' or \'short\'!\033[0m\n\n"; // ������� ��������� � �������
					break; // ��� ������ ������ ������� ����
				}
				else
					if (number > 32767 || number < -32768) { // ���� ���� �� ���� ������� ������� string ������� �� ������� �������� ���� ������ short, ��
						data_Type = "integer"; // ������ ������� ���� ������
						break; // �������, ��� ��� �������� ������������� �������� - ��� integer, ��� ������ ������ ������� ����
					}
					else
						data_Type = "short"; 
			}
			if (data_Type == "short") { // ����������� ��� ������������ ������� ����� ���� ������ short
				short arr_Max[length]{}; // ��������� ������ ���� ������ short �� �������� data_Type
				for (short i = 0; i < length; i++)
					arr_Max[i] = stoi(arr_Text[i]); // � ������� ������� ������� short ���������� ������� �������� �������� ������� string
				max_Element(arr_Max, length);
			}
			else
				if (data_Type == "integer") {
					int arr_Max[length]{}; // ��������� ������ ���� ������ integer �� �������� data_Type
					for (short i = 0; i < length; i++)
						arr_Max[i] = stoi(arr_Text[i]); // � ������� ������� ������� integer ���������� ������� �������� �������� ������� string
					max_Element(arr_Max, length);
				}
		}
	}

		// ������� ������� 2: ������������ ��� ��������, ����� ��� ������ �� ����� �������
	/*char my_Choise; // ���������� ��� �������� ������ ���� ������ ������������
	std::cout << "\033[91mTask 3. Maximum of three numbers\033[0m\n\nSelect data type:\npress \'1\' to select \'integer\'\npress \'2\' to select \'short\'\npress any key to select \'double\'\nYour choice -> ";
	std::cin >> my_Choise;
	const short length = 3; // ��������� ��� �������� ������� �������
	if (my_Choise == '1') {
		int arr_Max[length]{}; // ��������� ������ ���� integer � ������������ � ������� ������������
		array_Filling(arr_Max, length); // ��������� ������ �������		
		max_Element(arr_Max, length); // ������� ������������ �� �������� �����
	}
	else 
		if (my_Choise == '2') {
			short arr_Max[length]{}; // ��������� ������ ���� short � ������������ � ������� ������������
			array_Filling(arr_Max, length); 
			max_Element(arr_Max, length);
		}
		else {
			double arr_Max[length]{}; // ��������� ������ ���� double � ������������ � ������� ������������
			array_Filling(arr_Max, length); 
			max_Element(arr_Max, length);
		}*/	

	// ������ 4. ����� ������� �������� ����� � �������
	std::cout << "\033[91mTask 4. First simple number in array\033[0m\n\nSelect data type:\npress \'1\' to select \'short\'\npress \'2\' to select \'unsigned short\'\npress \'3\' to select \'integer\'\npress \'4\' to select \'unsigned integer\'\npress \'5\' to select \'long\'\npress \'6\' to select \'unsigned long\'\npress \'7\' to select \'long long\'\npress \'8\' to select \'unsigned long long\'\npress any key to select \'unsigned char\'\nYour choice -> ";
	const short size_Array = 5; // ����� ������ �������
	char my_Choise_Array; // ���������� ��� �������� ������ ���� ������ 
	std::cin >> my_Choise_Array;
	if (my_Choise_Array == '1') {
		short array_Simple[size_Array]{}; // ��������� ������ ���� ������ short
		array_Filling(array_Simple, size_Array); // ��������� ������	
		print_Array(array_Simple, size_Array); // ������� ������ � �������
		print_Simple_Number(number_Simple(array_Simple, size_Array)); // ������� ��������� � �������		
	}
	else if (my_Choise_Array == '2') {
		unsigned short array_Simple[size_Array]{}; // ��������� ������ ���� ������ unsigned short
		array_Filling(array_Simple, size_Array); 	
		print_Array(array_Simple, size_Array); 
		print_Simple_Number(number_Simple(array_Simple, size_Array)); 		
	}
	else if (my_Choise_Array == '3') {
		int array_Simple[size_Array]{};// ��������� ������ ���� ������ insteger
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '4') {
		unsigned int array_Simple[size_Array]{};// ��������� ������ ���� ������ unsigned insteger
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '5') {
		long array_Simple[size_Array]{};// ��������� ������ ���� ������ long
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '6') {
		unsigned long array_Simple[size_Array]{};// ��������� ������ ���� ������ unsigned long
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '7') {
		long long array_Simple[size_Array]{};// ��������� ������ ���� ������ long long
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '8') {
		unsigned long long array_Simple[size_Array]{};// ��������� ������ ���� ������ unsigned insteger
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '9') {
		char array_Simple[size_Array]{};// ��������� ������ ���� ������ char
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else {
		unsigned char array_Simple[size_Array]{};// ��������� ������ ���� ������ char
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	
	return 0;
}