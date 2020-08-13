#include <iostream>

#include "Array.h"
#include "Vector.h"
#include <string>

struct Vector3 
{
	float x, y, z;

	Vector3() 
		:x(0), y(0), z(0) {}

	Vector3(float scale)
		:x(scale), y(scale), z(scale) {}

	Vector3(float x1, float y1, float z1)
		:x(x1), y(y1), z(z1) {}

	Vector3(const Vector3& other)
		:x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Copy" << std::endl;
	}

	Vector3(Vector3&& other) noexcept
		:x(other.x), y(other.y), z(other.z)
	{
		std::cout << "Move " << std::endl;
	}

	~Vector3()
	{
		std::cout << "Destroy " << std::endl;
	}

	Vector3& operator =(const Vector3& other)
	{
		std::cout << "copy operator " << std::endl;
		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}

	Vector3& operator =( Vector3&& other) noexcept
	{
		std::cout << "move operator " << std::endl;
		x = other.x;
		y = other.y;
		z = other.z;

		return *this;
	}
};

template<typename T>
void printVector(const Vector<T>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << vector[i] << std::endl;

	std::cout << "-----------------------" << std::endl;
}

template<>
void printVector(const Vector<Vector3>& vector)
{
	for (size_t i = 0; i < vector.Size(); i++)
		std::cout << " x: " << vector[i].x << " y: " << vector[i].y << " z: " << vector[i].z << std::endl;

	std::cout << "-----------------------" << std::endl;
}

int main()
{
	Vector<std::string> data;
	data.PushBack("Hello");
	data.PushBack("World");
	printVector(data);


	Vector<Vector3> vector;
	vector.PushBack(Vector3(1.0f));
	vector.PushBack(Vector3(1.0f, 2.0f, 3.0f));
	vector.PushBack(Vector3());

	vector.PopBack();

	vector.EmplaceBack(0);
	printVector(vector);

	vector.Clear();
	vector.EmplaceBack(1.0f);

	printVector(vector);
	std::cin.get();
	
}