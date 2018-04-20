#pragma once
template <class T>
class Array
{
private:
	T * _array;
	int _size;


public:
	Array(int size)
	{
		_array = new T[size];
		_size = size;
	}

	~Array()
	{
		if (NULL != _array)
		{
			delete[] _array;
		}

		_array = NULL;
		_size = 0;
	}
	T & operator [](int index)
	{
		return _array[index];
	}
	//기본연산자 오버로딩
	
	operator T*()
	{
		return _array;
	}
	//&레퍼런스 != NULL반환

	void Insert(T data, int index)
	{
		for (int i = _size - 1; i > index; i--)
		{
			_array[i] = _array[i - 1];
		}
		_array[index] = data;
	}
	void Remove(int index)
	{
		for (int i = index; i < _size; i++)
		{
			_array[i] = _array[i + 1];
		}

	}

	void Resize(int newSize)
	{
		int* newArray = new int[newSize];
		if (NULL == newArray) return;

		int minsize = 0;

		minsize = (!(newSize > _size)) ? newSize : _size;

		for (int i = 0; i <= minsize; i++)
		{
			newArray[i] = _array[i];
		}

		if (NULL != _array)
			delete[] _array;

		_array = newArray;

		_size = newSize;
	}

	void Set(int index, T newItem)
	{
		_array[index] = newItem;
	}

	T Get(int index)
	{
		return _array[index];
	}


	int sizeGet()
	{
		return _size;
	}

	bool saveData(const char * fileName)
	{
		FILE *fp = fopen(fileName, "w+b");
		if (NULL == fp) return false;

		int num = fwrite(_array, sizeof(T), _size, fp);

		fclose(fp);

		if (num != _size)
			return false;

		return true;
	}

	bool LoadData(const char * fileName)
	{
		FILE *fp = fopen(fileName, "rb");
		if (NULL == fp) return false;

		int num = fread(_array, sizeof(T), _size, fp);

		fclose(fp);

		if (num != _size)
			return false;

		return true;
	}
};