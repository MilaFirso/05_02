#include "journeyThroughThePyramid.h"

enum class MovementsOnThePyramid
{
	Up = 1, Left = 2, Right = 3, Exit = 0
};


int root(int* arr, const int arrSize)
{
	return arr[0];
}

int fromIndex(int* arr, const int arrSize, const int index)
{
	return arr[index];
}

int leftIndex(const int parentIndex)
{
	return (2 * parentIndex + 1);
}

int rightIndex(const int parentIndex)
{
	return (2 * parentIndex + 2);
}

int parentIndex(int childIndex)
{
	return ((childIndex - 1) / 2);
}

// Функция какой сейчас индекс?
void whereAmI(int* arr, const int arrSize, int* arrIndexOfStop, int* levelOfpyramid, int countLevelsOfPyramid, int chooseOfUser)
{
	//Движение вверх
	if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Up))
	{
		if (*arrIndexOfStop == 0)
		{
			std::cout << "\n Ошибка!У корневого элемента отсутствует родитель.\n";
			std::cout << "Вы находитесь здесь: Уровень: 0. Root.\t " << fromIndex(arr, arrSize, *arrIndexOfStop) << std::endl << std::endl;
			return;
		}
		else if (*arrIndexOfStop == 1)
		{
			*arrIndexOfStop -= 1;
			std::cout << "Вы находитесь здесь: Уровень: 0. Root.\t " << fromIndex(arr, arrSize, *arrIndexOfStop) << std::endl << std::endl;
			return;
		}
		else if (*arrIndexOfStop == 2)
		{
			*arrIndexOfStop -= 2;
			std::cout << "Вы находитесь здесь: Уровень: 0. Root.\t " << fromIndex(arr, arrSize, *arrIndexOfStop) << std::endl << std::endl;
			return;
		}
		else if (*arrIndexOfStop % 2 != 0)
		{
			int thisLevelOfpyramid = PyramidLevelNow(levelOfpyramid, countLevelsOfPyramid, *arrIndexOfStop);

			*arrIndexOfStop = parentIndex(*arrIndexOfStop);

			std::cout << "Вы находитесь здесь: Уровень: " << thisLevelOfpyramid - 1
				<< ". Left(" << arr[parentIndex(*arrIndexOfStop)] << ")"
				<< ".\t " << arr[*arrIndexOfStop] << std::endl << std::endl;
			return;
		}
		else
		{
			int thisLevelOfpyramid = PyramidLevelNow(levelOfpyramid, countLevelsOfPyramid, *arrIndexOfStop);

			*arrIndexOfStop = parentIndex(*arrIndexOfStop);

			std::cout << "Вы находитесь здесь: Уровень: " << thisLevelOfpyramid - 1
				<< ". Right(" << arr[parentIndex(*arrIndexOfStop)] << ")"
				<< ".\t " << arr[*arrIndexOfStop] << std::endl << std::endl;
			return;
		};
	};

	//Движение влево
	if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Left))
	{
		int thisLevelOfpyramid = PyramidLevelNow(levelOfpyramid, countLevelsOfPyramid, *arrIndexOfStop);

		if (leftIndex(*arrIndexOfStop) > arrSize - 1)
		{
			std::cout << "\nОшибка!Отсутствует левый потомок.\n";
			std::cout << "Вы находитесь здесь: Уровень: " << thisLevelOfpyramid - 1
				<< ". Left(" << arr[parentIndex(*arrIndexOfStop)] << ")"
				<< ".\t " << arr[*arrIndexOfStop] << std::endl << std::endl;
			return;
		}
		else
		{
			int thisLevelOfpyramid = PyramidLevelNow(levelOfpyramid, countLevelsOfPyramid, *arrIndexOfStop);

			*arrIndexOfStop = leftIndex(*arrIndexOfStop);

			std::cout << "Вы находитесь здесь: Уровень: " << thisLevelOfpyramid - 1
				<< ". Left(" << arr[parentIndex(*arrIndexOfStop)] << ")"
				<< ".\t " << arr[*arrIndexOfStop] << std::endl << std::endl;
			return;
		};
	};

	//Движение вправо
	if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Right))
	{
		int thisLevelOfpyramid = PyramidLevelNow(levelOfpyramid, countLevelsOfPyramid, *arrIndexOfStop);

		if (rightIndex(*arrIndexOfStop) > arrSize - 1)
		{
			std::cout << "\nОшибка!Отсутствует правый потомок.\n";
			std::cout << "Ошибка!Отсутствует правый потомок: " << thisLevelOfpyramid - 1
				<< ". Right(" << arr[parentIndex(*arrIndexOfStop)] << ")"
				<< ".\t " << arr[*arrIndexOfStop] << std::endl << std::endl;
			return;
		}
		else
		{
			*arrIndexOfStop = rightIndex(*arrIndexOfStop);

			std::cout << "Вы находитесь здесь: Уровень: " << thisLevelOfpyramid - 1
				<< ". Right(" << arr[parentIndex(*arrIndexOfStop)] << ")"
				<< ".\t " << arr[*arrIndexOfStop] << std::endl << std::endl;
			return;
		}
	};
};

void journeyThroughThePyramid(int* arr, const int arrSize, int* levelOfpyramid, int countLevelsOfPyramid)
{
	int arrIndexOfStop = 0;
	//int arrIndex = 0;
	std::cout << "Давайте путешествовать по пирамиде:\n";


	std::cout << "Вы находитесь здесь: Уровень: 0. Root.\t " << fromIndex(arr, arrSize, arrIndexOfStop) << std::endl << std::endl;

	bool exitFromTheJourney = false;
	int chooseOfUser = 0;

	do
	{
		std::cout << "Введите команду (1.Вверх, 2.Влево, 3.Вправо, 0.Выход):>";
		std::cin >> chooseOfUser;
		while (!std::cin.good() || chooseOfUser < 0 || chooseOfUser > 3)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Вы ввели неверную команду.\n";
			std::cout << "Введите верную команду (1.Вверх, 2.Влево, 3.Вправо, 0.Выход):>";
			std::cin >> chooseOfUser;
		}

		if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Up))
		{
			whereAmI(arr, arrSize, &arrIndexOfStop, levelOfpyramid, countLevelsOfPyramid, chooseOfUser);
		}
		else if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Left))
		{
			whereAmI(arr, arrSize, &arrIndexOfStop, levelOfpyramid, countLevelsOfPyramid, chooseOfUser);
		}
		else if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Right))
		{
			whereAmI(arr, arrSize, &arrIndexOfStop, levelOfpyramid, countLevelsOfPyramid, chooseOfUser);
		}
		else if (chooseOfUser == static_cast<int> (MovementsOnThePyramid::Exit))
		{
			std::cout << "\nДо новых встреч.\n";
			exitFromTheJourney = true;
		}

		else
		{
			std::cout << "Выход за пределы IF-ELSE в void journeyThroughThePyramid(int* arr, const int arrSize)\n";
		}

	} while (!exitFromTheJourney);
}