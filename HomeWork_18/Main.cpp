# include <iostream>
#include<string>
#include<sstream>

/* Функция проверки введённого пользователем кол-ва чисел (для задачи 1). Проще (по кол-ву сток кода) её не делать, а проверку выполнить 
непосредственно в main{}, но для закрепления материала по функциям, я проверку сделал отдельной функцией*/
short input_Validation(short quantity) { 
	while (quantity < 1 || quantity > 5) {
		std::cout << "Input error! Enter the quantity of numbers (from 1 to 5) -> ";
		std::cin >> quantity;
	}
	return quantity;
}

// Функция с параметрами по умолчанию для расчёта суммы чисел (для задачи 1)
double sum(double num_1, double num_2 = 0, double num_3 = 0, double num_4 = 0, double num_5 = 0 ) {
	return num_1 + num_2 + num_3 + num_4 + num_5;
}

// Встраиваемая функция расчёта среднего арифметического переданных чисел (для задачи 2)
inline double arithmetic_Mean(double num_1, double num_2, double num_3) {
	return (num_1 + num_2 + num_3) / 3;
}

// Шаблонная процедура заполнения массива типа данных T (для задач 2 и 4)
template <typename T>
void array_Filling(T arr[], const short length) {
	for (short i = 0; i < length; i++) { // Цикл ввода пользователем чисел (заполнение массива чисел)
		std::cout << "Enter the number N " << i + 1 << " -> ";
		std::cin >> arr[i];
	}
}

// Перегруженная процедура для расчёта нахождения максимального значения введённого числа (для задачи 3)
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

template <typename T> // Шаблонная процедура для вывода массива
void print_Array(T arr[], const short length) {
	std::cout << "\nSource array is: ";
	for (short i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b \n";
}

template <typename T> // Шаблонная функция для поиска первого простого числа в массиве
T number_Simple(T arr[], const short length) {
	T number = 0; // Переменная для хранения первого простого числа
	for (short i = 0; i < length; i++) {
		if (number) // Если первое простое число найдено, то разрушаем цикл
			break;
		int counter = 0;
		for (short j = 2; j <= arr[i]; j++) { // с 2 потому что на 1 делится любое число
			if (arr[i] % j == 0 && arr[i]>0) // учитываем, что простое число должно быть положительным
				counter++;
			if (counter > 1) // Если число делителей больше одного (с единицей 2), то разрушаем цикл
				break;
			if (arr[i] == j && arr[i] > 0)
				number = arr[i];
		}
	}
	return number;
}

template <typename T> // Шаблонная процедура для вывода первого простого числа в массиве
void print_Simple_Number(T number) {
	if (number)
		std::cout << "\n\033[92mFirst simple number in array is " << number << "\033[0m\n\n";
	else
		std::cout << "\n\033[92mThere are no simple numbers in the array\033[0m\n\n";
}


int main() {

	// Задача 1. Сумма разного количества (от 1 до 5) чисел
	short quantity; // Переменная для хранения кол-ва чисел
	std::cout << "\033[91mTask 1. The sum of a different number (from 1 to 5) of numbers\033[0m\n\nEnter the quantity of numbers (from 1 to 5) -> ";
	std::cin >> quantity;
	if (quantity < 1 || quantity > 5) // Проверка введённого пользователем кол-ва чисел
		quantity = input_Validation(quantity);
	double* array = new double[quantity]; // Выделение памяти под динамический массив, размер которого = кол-ву чисел, введённых пользователем
	for (short i = 0; i < quantity; i++) { // Цикл ввода пользователем выбранного кол-ва чисел (заполнение динамического массива)
		std::cout << "Enter the number N " << i + 1 << " -> ";
		std::cin >> array[i];
	}
	std::cout << "\n\033[92mThe sum of the entered numbers is ";
	switch (quantity) { // Конструкция для вывода результата вычисления в зависимости от введённого пользователем кол-ва чисел
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
	delete[] array; // Чистим память от динамичесого массива

	// Задача 2. Встраиваемая функция для вычисления среднего арифметического 3-ёх чисел
	std::cout << "\033[91mTask 2. Arithmetic mean of three numbers\033[0m\n\n";
	const short size = 3; // Размер массива чисел
	double arr[size]{}; // Объявляем массив чисел
	array_Filling(arr, size); // Заполняем массив числами
	std::cout << "\n\033[092mThe arithmetic mean of three entered numbers is " << arithmetic_Mean(arr[0], arr[1], arr[2]) << "\033[0m\n\n";

	// Задача 3. Максимальное из трёх чисел
	 
		// Вариант решения 1: программа распознаёт тип данных после первого ввода пользователем символов
	std::cout << "\033[91mTask 3. Maximum of three numbers\033[0m\n\n";	
	bool key_Mistake = false; // Объявляем и инициализируем переменную для хранения кода ошибки
	std::string data_Type{}; // Объявляем строковую переменную для хранения признака типа данных
	const short length = 3; // Объявляем и инициализируем размер массива чисел (3 по условию задачи)	
	std::string arr_Text[length]{}; // Объявляем массив строк, в который будем записывать всё, что вводит пользователь
	for (short i = 0; i < length; i++) { // Цикл заполнения массива строк
		if (key_Mistake) // Если код ошибки true (пользователь ошибся при вводе числа), то
			break; // нет смысла дальше крутуть цикл
		std::cout << "Enter the number N " << i + 1 << " -> ";
		std::cin >> arr_Text[i];
		short line_size = std::size(arr_Text[i]); // Объявляем и инициализируем переменную для хранения длины введёной пользователем строки для последующего использования в цикле
		short counter_Point = 0; // Объявляем переменную для хранения счётчика символов точки
		for (short j = 0; j < line_size; j++) { // Цикл проверки введённых пользователем символов текущей строки
			char value = int(arr_Text[i][j]); // В локальную переменную записываем код по ASCII-таблице текущего символа текущей строки 
			// Если символ не цифра, не точка (кроме нулевого индекса), не нулевой символ "минус" то 
			if (value < 45 || value == 47 || value > 57 || (value == 45 && j != 0) || (value == 46 && j == 0)) { 
				key_Mistake = true;	// переключаем код ошибки, т.к введённая пользователем строка точно не число
				break; // прекращаем работу цикла, т.к. нет смысла в дальнейшей проверке ввежённых пользователем символов
			}
			else
				if (value == 46) // Считаем кол-во точек в введёной строке
					counter_Point++;
			if (counter_Point > 1) { // Если символов точки в введённой пользователем строке более 1 (введённые символы точно не число), то 
				key_Mistake = true; // переключаем код ошибки
				break; // прекращаем работу цикла, т.к. нет смысла в дальнейшей проверке символов
			}
		}
	}
	if (key_Mistake) // Если введённые символы не число
		std::cout << "\n\033[92mOne or more of the numbers entered are not a number!\033[0m\n\n"; // Вывод результата в консоль
	else { // Если введённы символы число
		for (short i = 0; i < length; i++) { // Цикл проверки строк массива на соответствие типу данных double
			if (data_Type == "double") // Если любой символ любой строки массива содержит признак вещественного числа (точку), то
				break; // нет смысла в дальнейшей проверке (все три введённых пользователем строки считаем типом данных double)
			short line_size = std::size(arr_Text[i]); // Объявляем и инициализируем переменную для хранения длины введёной пользователем строки для последующего использования в цикле
			for (short j = 1; j < line_size; j++) // Цикл проверки текущей строки массива на признак вещественного числа (точки)
				if (arr_Text[i][j] == 46) { // Если в текущей строке массива есть точка (число вещёственное), то
					data_Type = "double"; // записываем признак типа данных и
					break; // разрушаем цикл
				}				
		}
		if (data_Type == "double") { // Конструкция для формирования массива вещественного типа данных
			double arr_Max[length]{}; // Объявляем массив типа данных double по признаку data_Type
			for (short i = 0; i < length; i++) // Цикл формирования массива типа данных double
				arr_Max[i] = stod(arr_Text[i]); // В текущий элемент массива double записываем текущее значение элемента массива string
			max_Element(arr_Max, length);
		}
		else { // Конструкция для формирования массива целочисленных типов данных			
			for (short i = 0; i < length; i++) { // Цикл проверки соответствия данных массива string ддиапазонам типов данных integer и short
				long long number = stoll(arr_Text[i]); // Объявляем максимально возможную целочисленную локальную переменную и инициализируем её текущим элементом массива string
				if (number > 2147483647 || number < -2147483648) { // Если текущий элемент массива string выходит за диапазон integer, то
					std::cout << "\n\033[92One or more of the numbers entered are not a type \'integer\' or \'short\'!\033[0m\n\n"; // выводим результат в консоль
					break; // нет смысла дальше крутить цикл
				}
				else
					if (number > 32767 || number < -32768) { // Если хотя бы один элемент массива string выходит за пределы дипазона типа данных short, то
						data_Type = "integer"; // меняем признак типа данных
						break; // считаем, что все введённые пользователем значения - это integer, нет смысла дальше крутить цикл
					}
					else
						data_Type = "short"; 
			}
			if (data_Type == "short") { // Конструкция для формирования массива чисел типа данных short
				short arr_Max[length]{}; // Объявляем массив типа данных short по признаку data_Type
				for (short i = 0; i < length; i++)
					arr_Max[i] = stoi(arr_Text[i]); // В текущий элемент массива short записываем текущее значение элемента массива string
				max_Element(arr_Max, length);
			}
			else
				if (data_Type == "integer") {
					int arr_Max[length]{}; // Объявляем массив типа данных integer по признаку data_Type
					for (short i = 0; i < length; i++)
						arr_Max[i] = stoi(arr_Text[i]); // В текущий элемент массива integer записываем текущее значение элемента массива string
					max_Element(arr_Max, length);
				}
		}
	}

		// Вариант решения 2: пользователь сам выбирает, какой тип данных он будет вводить
	/*char my_Choise; // Переменная для хранения выбора типа данных пользователя
	std::cout << "\033[91mTask 3. Maximum of three numbers\033[0m\n\nSelect data type:\npress \'1\' to select \'integer\'\npress \'2\' to select \'short\'\npress any key to select \'double\'\nYour choice -> ";
	std::cin >> my_Choise;
	const short length = 3; // Константа для хранения размера массива
	if (my_Choise == '1') {
		int arr_Max[length]{}; // Объявляем массив типа integer в соответствии с выбором пользователя
		array_Filling(arr_Max, length); // Заполняем массив числами		
		max_Element(arr_Max, length); // Находим максимальное из введённых чисел
	}
	else 
		if (my_Choise == '2') {
			short arr_Max[length]{}; // Объявляем массив типа short в соответствии с выбором пользователя
			array_Filling(arr_Max, length); 
			max_Element(arr_Max, length);
		}
		else {
			double arr_Max[length]{}; // Объявляем массив типа double в соответствии с выбором пользователя
			array_Filling(arr_Max, length); 
			max_Element(arr_Max, length);
		}*/	

	// Задача 4. Поиск первого простого числа в массиве
	std::cout << "\033[91mTask 4. First simple number in array\033[0m\n\nSelect data type:\npress \'1\' to select \'short\'\npress \'2\' to select \'unsigned short\'\npress \'3\' to select \'integer\'\npress \'4\' to select \'unsigned integer\'\npress \'5\' to select \'long\'\npress \'6\' to select \'unsigned long\'\npress \'7\' to select \'long long\'\npress \'8\' to select \'unsigned long long\'\npress any key to select \'unsigned char\'\nYour choice -> ";
	const short size_Array = 5; // Задаём размер массива
	char my_Choise_Array; // Переменная для хранения выбора типа данных 
	std::cin >> my_Choise_Array;
	if (my_Choise_Array == '1') {
		short array_Simple[size_Array]{}; // Объявляем массив типа данных short
		array_Filling(array_Simple, size_Array); // Заполняем массив	
		print_Array(array_Simple, size_Array); // Выводим массив в консоль
		print_Simple_Number(number_Simple(array_Simple, size_Array)); // Выводим результат в консоль		
	}
	else if (my_Choise_Array == '2') {
		unsigned short array_Simple[size_Array]{}; // Объявляем массив типа данных unsigned short
		array_Filling(array_Simple, size_Array); 	
		print_Array(array_Simple, size_Array); 
		print_Simple_Number(number_Simple(array_Simple, size_Array)); 		
	}
	else if (my_Choise_Array == '3') {
		int array_Simple[size_Array]{};// Объявляем массив типа данных insteger
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '4') {
		unsigned int array_Simple[size_Array]{};// Объявляем массив типа данных unsigned insteger
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '5') {
		long array_Simple[size_Array]{};// Объявляем массив типа данных long
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '6') {
		unsigned long array_Simple[size_Array]{};// Объявляем массив типа данных unsigned long
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '7') {
		long long array_Simple[size_Array]{};// Объявляем массив типа данных long long
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '8') {
		unsigned long long array_Simple[size_Array]{};// Объявляем массив типа данных unsigned insteger
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else if (my_Choise_Array == '9') {
		char array_Simple[size_Array]{};// Объявляем массив типа данных char
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	else {
		unsigned char array_Simple[size_Array]{};// Объявляем массив типа данных char
		array_Filling(array_Simple, size_Array);
		print_Array(array_Simple, size_Array);
		print_Simple_Number(number_Simple(array_Simple, size_Array));
	}
	
	return 0;
}