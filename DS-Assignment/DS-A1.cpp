#include<iostream>
#include<Windows.h>
#include<cmath>
#include<stdexcept>
#include <chrono>
#include <cstdlib>
#include<vector>
using namespace std;
using namespace std::chrono;


template <typename T>
class staticarray
{
private:
	T* arr;
	int count;
	int size;
public:
	staticarray(int size)
	{
		this->size = size;
		arr = new T[size]{};
		this->count = 0;
	}

	staticarray(const staticarray& A)
	{
		size = A.size;
		count = A.count;
		arr = new T[size]{};
		for (int i = 0; i < count; i++)
		{
			arr[i] = A.arr[i];
		}
	}

	staticarray operator=(const staticarray& A)
	{
		if (this != &A)
		{
			delete[] arr;
			size = A.size;
			count = A.count;
			arr = new T[size]{};
			for (int i = 0; i < count; i++)
			{
				arr[i] = A.arr[i];
			}
		}
		return *this;
	}

	~staticarray()
	{
		delete[] arr;
	}

	void insertatfirst(T value)
	{
		if (size <= count)
		{
			throw exception("Array is full");
		}
		else
			if (count == 0)
			{
				arr[0] = value;
				count++;
			}
			else
				if (count > 0)
				{
					for (int i = count; i > 0; i--)
					{
						arr[i] = arr[i - 1];
					}
					arr[0] = value;
					count++;
				}
	}

	void insertatlast(T value)
	{
		if (size == count)
		{
			throw exception("Array is full");
		}
		else
			if (size > count)
			{
				arr[count] = value;
				count++;
			}
	}

	void insertatmiddle(T value)
	{
		if (size == count)
		{
			throw exception("Array is full");
		}
		else
			if (size > count)
			{
				int mid = count / 2;
				ceil(mid);
				for (int i = count; i > mid; i--)
				{
					arr[i] = arr[i - 1];
				}
				arr[mid] = value;
				count++;
			}
	}

	void insertatanyposition(int index, T value)
	{
		if (size == count)
		{
			throw exception("Array is full");
		}
		else
			if (size > count)
			{
				if (index < 0 || index >= size)
				{
					throw exception("Index out of range");
				}
				for (int i = count; i > index; i--)
				{
					arr[i] = arr[i - 1];
				}
				arr[index] = value;
				count++;
			}
	}

	void deleteatfirst()
	{
		if (count == 0)
		{
			throw exception("Array is empty");
		}
		else
			if (count > 0)
			{
				for (int i = 0; i < count; i++)
				{
					arr[i] = arr[i + 1];
				}
				count--;
			}
	}

	void deleteatlast()
	{
		if (count == 0)
		{
			throw exception("Array is empty");
		}
		else
			if (count > 0)
			{
				arr[count - 1] = 0;
				count--;
			}
	}

	void deleteatmiddle()
	{
		if (count == 0)
		{
			throw exception("Array is empty");
		}
		else
			if (count > 0)
			{
				int mid = count / 2;
				ceil(mid);
				mid--;
				for (int i = mid; i < count; i++)
				{
					arr[i] = arr[i + 1];
				}
				count--;
			}
	}

	void deleteatanyposition(int index)
	{
		if (count == 0)
		{
			throw exception("Array is empty");
		}
		else
			if (count > 0)
			{
				if (index < 0 || index >= size)
				{
					throw exception("Index out of range");
				}
				for (int i = index; i < count; i++)
				{
					arr[i] = arr[i + 1];
				}
				count--;
			}
	}

	void print()
	{
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	T search(T value)
	{

		for (int i = 0; i < count; i++)
		{
			if (arr[i] == value)
			{
				return i;
			}
		}
		throw exception("Value not found");
	}


};

template <typename G>
class growarray
{
private:
	G* arr;
	int size;
	int count;
public:
	growarray(int size = 0)
	{
		this->size = size;
		arr = new G[size]{};
		this->count = 0;
	}

	growarray(const growarray& A)
	{
		size = A.size;
		count = A.count;
		arr = new G[size]{};
		for (int i = 0; i < count; i++)
		{
			arr[i] = A.arr[i];
		}
	}

	growarray operator=(const growarray& A)
	{
		if (this != &A)
		{
			delete[] arr;
			size = A.size;
			count = A.count;
			arr = new G[size]{};
			for (int i = 0; i < count; i++)
			{
				arr[i] = A.arr[i];
			}
		}
		return *this;
	}

	~growarray()
	{
		delete[] arr;
	}

	void insertatfirst(G value)
	{
		if (count >= size)
		{
			G* temp = new G[size + 1]{};
			for (int i = 0; i < size; i++)
			{
				temp[i + 1] = arr[i];
			}
			temp[0] = value;
			delete[] arr;
			arr = temp;
			count++, size++;
		}
		else
			if (count == 0)
			{
				arr[0] = value;
				count++;
			}
			else
				if (count > 0)
				{
					for (int i = count; i > 0; i--)
					{
						arr[i] = arr[i - 1];
					}
					arr[0] = value;
					count++;
				}

	}

	void insertatlast(G value)
	{
		if (count >= size)
		{
			G* temp = new G[size + 1]{};
			for (int i = 0; i < count; i++)
			{
				temp[i] = arr[i];
			}
			temp[count] = value;
			delete[] arr;
			arr = temp;
			count++, size++;
		}
		else if (count < size)
		{
			arr[count] = value;
			count++;
		}
	}

	void insertatmiddle(G value)
	{
		if (count >= size)
		{


			int mid = size / 2;
			ceil(mid);
			G* temp = new G[size + 1]{};
			for (int i = 0; i < mid; i++)
			{
				temp[i] = arr[i];
			}
			temp[mid] = value;
			for (int i = mid; i < count; i++)
			{
				temp[i + 1] = arr[i];
			}
			delete[] arr;
			arr = temp;
			count++, size++;

		}
		else
			if (count < size)
			{
				int mid = count / 2;
				ceil(mid);
				for (int i = count; i > mid; i--)
				{
					arr[i] = arr[i - 1];
				}
				arr[mid] = value;
				count++;
			}
	}

	void insertatanyposition(int index, G value)
	{
		if (count >= size)
		{
			G* temp = new G[size + 1]{};
			for (int i = 0; i < index; i++)
			{
				temp[i] = arr[i];
			}
			temp[index] = value;
			for (int i = index; i < count; i++)
			{
				temp[i + 1] = arr[i];
			}
			delete[] arr;
			arr = temp;
			count++, size++;
		}
		else
			if (count < size)
			{
				if (index < 0 || index >= size)
				{
					throw exception("Index out of range");
				}
				for (int i = count; i > index; i--)
				{
					arr[i] = arr[i - 1];
				}
				arr[index] = value;
				count++;
			}
	}

	void deleteatfirst()
	{
		if (count == 0)
		{
			throw exception("Array is empty");
		}
		else if (count > 0)
		{
			for (int i = 0; i < count; i++)
			{
				arr[i] = arr[i + 1];
			}
			count--;
		}

	}

	void deleteatlast()
	{
		if (count == 0)
		{
			throw exception("Array is empty");
		}
		else if (count > 0)
		{
			arr[count - 1] = 0;
			count--;
		}
	}

	void deleteatmiddle()
	{
		if (count == 0)
		{
			throw exception("Array is empty");
		}
		else if (count > 0)
		{
			int mid = count / 2;
			ceil(mid);
			for (int i = mid; i < count; i++)
			{
				arr[i] = arr[i + 1];
			}
			count--;
		}
	}

	void deleteatanyposition(int index)
	{
		if (count == 0)
		{
			throw exception("Array is empty");
		}
		else if (count > 0)
		{
			if (index < 0 || index >= size)
			{
				throw exception("Index out of range");
			}
			for (int i = index; i < count; i++)
			{
				arr[i] = arr[i + 1];
			}
			count--;
		}
	}

	G search(G value)
	{

		for (int i = 0; i < count; i++)
		{
			if (arr[i] == value)
			{
				return i;
			}
		}
		throw exception("Value not found");
	}

	int getsize()
	{
		return size;
	}

	void print()
	{
		for (int i = 0; i < count; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}


	class Iterator
	{
	private:
		G* ptr;

		Iterator(G* ptr)
		{
			this->ptr = ptr;
		}
	public:
		friend class growarray;

		Iterator& operator++()
		{
			ptr++;
			return *this;
		}

		const Iterator operator++(int)
		{
			Iterator temp = *this;
			ptr++;
			return temp;
		}

		Iterator& operator--()
		{
			ptr--;
			return *this;
		}

		const Iterator operator--(int)
		{
			Iterator temp = *this;
			ptr--;
			return temp;
		}

		bool operator==(const Iterator& other)
		{
			return this->ptr == other.ptr;
		}

		bool operator!=(const Iterator& other)
		{
			return !(this->ptr == other.ptr);
		}

		G& operator*()
		{
			return *ptr;
		}
	};

	/*class ReverseIterator
	{
	private:
		G* ptr;

		ReverseIterator(G* ptr)
		{
			this->ptr = ptr;
		}
	public:
		friend class growarray;
		ReverseIterator& operator++()
		{
			ptr--;
			return *this;
		}

		const ReverseIterator operator++(int)
		{
			ReverseIterator temp = *this;
			ptr--;
			return temp;
		}

		bool operator==(const ReverseIterator& other)
		{
			return this->ptr == other.ptr;
		}

		bool operator!=(const ReverseIterator& other)
		{
			return !(this->ptr == other.ptr);
		}
		G& operator*()
		{
			return *ptr;
		}
	};*/

	Iterator begin()
	{
		return Iterator(arr);
	}

	Iterator end()
	{
		return Iterator(arr + count);
	}

	Iterator rbegin()
	{
		return Iterator(arr + count - 1);
	}

	Iterator rend()
	{
		return Iterator(arr - 1);
	}


};


template <typename D>
class Vector
{
private:
	D* arr;
	size_t size;
	size_t capacity;

	void resize()
	{
		D* temp = new D[capacity * 2]{};
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
		capacity *= 2;
	}
public:

	Vector()
	{
		this->size = 0;
		this->capacity = 1;
		arr = new D[capacity]{};
	}

	Vector(const Vector& Other)
	{
		size = Other.size;
		capacity = Other.capacity;
		arr = new D[capacity]{};
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = Other.arr[i];
		}
	}

	Vector operator=(const Vector& Other)
	{
		if (this != &Other)
		{
			delete[] arr;
			size = Other.size;
			capacity = Other.capacity;
			arr = new D[capacity]{};
			for (size_t i = 0; i < size; i++)
			{
				arr[i] = Other.arr[i];
			}
		}
		return *this;
	}

	~Vector()
	{
		delete[] arr;
	}
	void insert(D value)
	{
		if (size == capacity)
		{
			resize();
		}
		arr[size] = value;
		size++;
	}

	D operator[](int index)const
	{
		if (index < 0 || index >= size)
		{
			throw exception("Index out of range");
		}
		else
		{
			return arr[index];
		}
	}

	D& operator[](int index)
	{
		if (index < 0 || index >= size)
		{
			throw exception("Index out of range");
		}
		else
		{
			return arr[index];
		}
	}

	friend ostream& operator<<(ostream& out, const Vector& Other)
	{
		cout << "\nArray: \n";
		for (int i = 0; i < Other.size; i++)
		{
			out << Other.arr[i] << " ";
		}
		out << endl;
		return out;
	}


	


};


int loadData(int n)
{
	Vector<size_t> a;
	auto start = high_resolution_clock::now();

	for (size_t i = 0; i < n; i++)
	{
		a.insert(rand() % 1000);
	}
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);
	return duration.count();
}





int main()
{
	cout << "1. Static Array" << endl;
	cout << "2. Dynamic Array" << endl;
	cout << "3. Vector" << endl;
	cout << "Enter Choice: ";
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << "Enter Size of Array:";
		int size;
		cin >> size;
		staticarray<int> a(size);
		cout << "1. Insert at first" << endl;
		cout << "2. Insert at last" << endl;
		cout << "3. Insert at middle" << endl;
		cout << "4. Insert at any position" << endl;
		cout << "5. Delete at first" << endl;
		cout << "6. Delete at last" << endl;
		cout << "7. Delete at middle" << endl;
		cout << "8. Delete at any position" << endl;
		cout << "9. Search" << endl;
		cout << "10. Print" << endl;

		int choose;
		cout << "Enter Choice or -1 to exit: ";
		cin >> choose;

		while (choose != -1)
		{
			try
			{
				if (choose == 1)
				{
					int value;
					cout << "Enter value to insert: ";
					cin >> value;
					a.insertatfirst(value);
					a.print();
				}
				else if (choose == 2)
				{
					int value;
					cout << "Enter value to insert: ";
					cin >> value;
					a.insertatlast(value);
					a.print();
				}
				else if (choose == 3)
				{
					int value;
					cout << "Enter value to insert: ";
					cin >> value;
					a.insertatmiddle(value);
					a.print();
				}
				else if (choose == 4)
				{
					int value;
					int index;
					cout << "Enter value to insert: ";
					cin >> value;
					cout << "Enter index to insert: ";
					cin >> index;
					a.insertatanyposition(index, value);
					a.print();
				}
				else if (choose == 5)
				{
					a.deleteatfirst();
					a.print();
				}
				else if (choose == 6)
				{
					a.deleteatlast();
					a.print();
				}
				else if (choose == 7)
				{
					a.deleteatmiddle();
					a.print();
				}
				else if (choose == 8)
				{
					int index;
					cout << "Enter index to delete: ";
					cin >> index;
					a.deleteatanyposition(index);
					a.print();
				}
				else if (choose == 9)
				{
					int value;
					cout << "Enter value to search: ";
					cin >> value;
					cout << "Value found at index: ";
					cout << a.search(value) << endl;
				}
				else if (choose == 10)
				{
					cout << "\nArray: \n";
					a.print();
					cout << endl;
				}
				else
				{
					cout << "Invalid Choice" << endl;
				}
			}
			catch (const exception& e)
			{
				cout << e.what() << endl;
			}

			cout << "Enter Choice or -1 to exit: ";
			cin >> choose;
		}

	}
	if (choice == 2)
	{
		growarray<int> a(10);
		cout << "1. Insert at first" << endl;
		cout << "2. Insert at last" << endl;
		cout << "3. Insert at middle" << endl;
		cout << "4. Insert at any position" << endl;
		cout << "5. Delete at first" << endl;
		cout << "6. Delete at last" << endl;
		cout << "7. Delete at middle" << endl;
		cout << "8. Delete at any position" << endl;
		cout << "9. Search" << endl;
		cout << "10. Print" << endl;
		cout << "11. Print through Iterator" << endl;
		cout << "12. Print through Reverse Iterator" << endl;
		cout << "13. Change through Iterator" << endl;

		int choose;
		cout << "Enter Choice or -1 to exit: ";
		cin >> choose;

		while (choose != -1)
		{
			try
			{
				if (choose == 1)
				{
					int value;
					cout << "Enter value to insert: ";
					cin >> value;
					a.insertatfirst(value);
					a.print();
				}
				else if (choose == 2)
				{
					int value;
					cout << "Enter value to insert: ";
					cin >> value;
					a.insertatlast(value);
					a.print();
				}
				else if (choose == 3)
				{
					int value;
					cout << "Enter value to insert: ";
					cin >> value;
					a.insertatmiddle(value);
					a.print();
				}
				else if (choose == 4)
				{
					int value;
					int index;
					cout << "Enter value to insert: ";
					cin >> value;
					cout << "Enter index to insert: ";
					cin >> index;
					a.insertatanyposition(index, value);
					a.print();
				}
				else if (choose == 5)
				{
					a.deleteatfirst();
					a.print();
				}
				else if (choose == 6)
				{
					a.deleteatlast();
					a.print();
				}
				else if (choose == 7)
				{
					a.deleteatmiddle();
					a.print();
				}
				else if (choose == 8)
				{
					int index;
					cout << "Enter Index: ";
					cin >> index;
					a.deleteatanyposition(index);
					a.print();
				}
				else if (choose == 9)
				{
					int value;
					cout << "Enter value to search: ";
					cin >> value;
					cout << "Value found at index: ";
					cout << a.search(value) << endl;
				}
				else if (choose == 10)
				{
					cout << "\nArray: \n";
					a.print();
					cout << endl;
				}
				else if (choose == 11)
				{
					cout << "Array through Iterator:";
					cout << "\n";
					for (growarray<int>::Iterator i = a.begin(); i != a.end(); i++)
					{
						cout << *i << " ";
					}
					cout << "\n";
				}
				else if (choose == 12)
				{
					cout << "Array through Reverse Iterator:";
					cout << "\n";
					for (growarray<int>::Iterator i = a.rbegin(); i != a.rend(); i--)
					{
						cout << *i << " ";
					}
					cout << "\n";
				}
				else if (choose == 13)
				{
					cout << "Enter Index to change through Iterator: ";
					int index;
				xy:
					cin >> index;
					if (index >= a.getsize())
					{
						cout << "Index out of range" << endl;
						cout << "Enter Again: ";
						goto xy;
					}
					growarray<int>::Iterator i = a.begin();
					for (int j = 0; j < index; j++)
					{
						i++;
					}
					cout << "Enter Value to change: ";
					int value;
					cin >> value;
					*i = value;
				}
				else
				{
					cout << "Invalid Choice" << endl;
				}
			}
			catch (const exception& e)
			{
				cout << e.what() << endl;
			}

			cout << "Enter Choice or -1 to exit: ";
			cin >> choose;
		}
	}
	if (choice == 3)
	{
		Vector<int> a;
		cout << "1. Insert" << endl;
		cout << "2. To get element" << endl;
		cout << "3. To set element" << endl;
		cout << "4. Print" << endl;
		cout << "5. Load Data And Estimation of time" << endl;
		int choose;
		cout << "Enter Choice or -1 to exit: ";
		cin >> choose;
		while (choose != -1)
		{
			try
			{
				if (choose == 1)
				{
					int value;
					cout << "Enter value to insert: ";
					cin >> value;
					a.insert(value);
				}
				else if (choose == 2)
				{
					int index;
					cout << "Enter index to get element: ";
					cin >> index;
					cout << a[index] << endl;
				}
				else if (choose == 3)
				{
					int index;
					int value;
					cout << "Enter index to set element: ";
					cin >> index;
					cout << "Enter value to set: ";
					cin >> value;
					a[index] = value;
				}
				else if (choose == 4)
				{
					cout << a;
				}
				else if (choose==5)
				{
					int t1 = loadData(10 * 1024 * 1024);
					cout << "Time taken to load 10MB data: " << t1 << " microseconds" << endl;

					int t2 = loadData(20*1024*1024);
					cout << "Time taken to load 20MB data: " << t2 << " microseconds" << endl;

					int t3 = loadData(30*1024*1024);
					cout << "Time taken to load 30MB data: " << t3 << " microseconds" << endl;

					int t4 = loadData(40 * 1024 * 1024);
					cout << "Time taken to load 40MB data: " << t4 << " microseconds" << endl;

					cout << "Prediction for larger data sizes:" << endl;
					cout << "Estimated time for loading 1 GB: " << (1024) * loadData(1024 * 1024) << " ms" << endl;
					cout << "Estimated time for loading 1 TB: " << (1024 * 1024) * loadData(1024 * 1024) << " ms" << endl;

				}
				else
				{
					cout << "Invalid Choice" << endl;
				}
			}
			catch (const exception& e)
			{
				cout << e.what() << endl;
			}
			cout << "Enter Choice or -1 to exit: ";
			cin >> choose;
		}
	}

	return 0;
}



