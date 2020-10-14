#include <iostream>
#include <new>
#include <list>
using namespace std;

class ArrayMass
{
	int count;
	int* arr;
	static bool CheckArray(int a, list<int> mass) { //if true - in array, if false - not in array
		if (mass.empty())
		{
			return false;
		}
		for (int i : mass)
		{
			if (a == i)
			{
				return true;
			}
		}
		return false;
	}
public:
	ArrayMass();
	ArrayMass(int);
	ArrayMass(const ArrayMass&);
	int Count();
	void PushArray();
	void PushArrayProg(list<int>);
	static ArrayMass GetIntersection(ArrayMass arr1, ArrayMass arr2) {
		list<int> rez;
		for (int i = 0; i < arr1.Count(); i++)
		{
			if (CheckArray(arr1.arr[i], rez))
			{
				continue;
			}
			for (int j = 0; j < arr2.Count(); j++)
			{
				if (arr1.arr[i] == arr2.arr[j])
				{
					rez.push_back(arr1.arr[i]);
				}
			}
		}
		ArrayMass solut(rez.size());
		solut.PushArrayProg(rez);
		return solut;
	}
	static ArrayMass GetUnion(ArrayMass arr1, ArrayMass arr2) {
		list<int> rez;
		for (int i = 0; i < arr1.Count(); i++)
		{
			if (CheckArray(arr1.arr[i], rez))
			{
				continue;
			}
			rez.push_back(arr1.arr[i]);
		}
		for (int i = 0; i < arr2.Count(); i++)
		{
			if (CheckArray(arr2.arr[i], rez))
			{
				continue;
			}
			rez.push_back(arr2.arr[i]);
		}
		ArrayMass solut(rez.size());
		solut.PushArrayProg(rez);
		return solut;
	}
	void PrintArray();
	~ArrayMass();
};

ArrayMass::ArrayMass()
{
	count = 0;
	arr = new int(0);
	cout << "Массив создан" << endl;
}

ArrayMass::ArrayMass(int n1)
{
	count = n1;
	arr = new int(n1);
	cout << "Массив создан" << endl;
}

ArrayMass::ArrayMass(const ArrayMass& ob)
{
	count = ob.count;
	arr = new int[count];
	for (int i = 0; i < count; i++)
	{
		arr[i] = ob.arr[i];
	}
}

int ArrayMass::Count()
{
	return count;
}

void ArrayMass::PushArray()
{
	for (int i = 0; i < count; i++)
	{
		cout << "Введите " << (i + 1) << " элемент массива" << endl;
		cin >> arr[i];
		cout << endl;
	}
}

void ArrayMass::PushArrayProg(list<int> num)
{
	int j = 0;
	for (int i : num)
	{
		arr[j] = i;
		j++;
	}
}

void ArrayMass::PrintArray()
{
	for (int i = 0; i < count; i++)
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

ArrayMass::~ArrayMass()
{
	count = 0;
	arr = NULL;
}

int main()
{
	setlocale(LC_ALL, "");
	cout << "Введите количество элементов первого массива" << endl;
	int n;
	cin >> n;
	ArrayMass ar1(n);
	ar1.PushArray();
	cout << "Введите количество элементов второго массива" << endl;
	cin >> n;
	ArrayMass ar2(n);
	ar2.PushArray();
	cout << "\n\n\n";
	ar1.PrintArray();
	cout << "\n\n";
	ar2.PrintArray();
	cout << endl;

	ArrayMass rez = ArrayMass::GetIntersection(ar1, ar2);
	cout << "Пересечение:" << endl;
	rez.PrintArray();

	rez = ArrayMass::GetUnion(ar1, ar2);
	cout << "Объединение:" << endl;
	rez.PrintArray();
}


