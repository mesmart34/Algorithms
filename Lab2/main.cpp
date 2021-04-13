#include <vector>
#include <iostream>
#include "pugixml.hpp"

using namespace std;
using namespace pugi;

static void PrintArray(const vector<int>& array)
{
	for (auto a : array)
		cout << a << " ";
	cout << endl;
}

static int iters = 0;

static void MergeSort(vector<int>& array, const int left, const int right)
{
	iters++;
	if (left >= right)
		return;
	const int middle = left + (right - left) / 2;
	MergeSort(array, left, middle);
	MergeSort(array, middle + 1, right);
	auto size1 = middle - left + 1;
	auto size2 = right - middle;
	auto arr1 = vector<int>(size1);
	auto arr2 = vector<int>(size2);
	for (auto i = 0; i < size1; i++)
		arr1[i] = array[left + i];
	for (auto i = 0; i < size2; i++)
		arr2[i] = array[middle + 1 + i];
	auto k = left, i = 0, j = 0;
	for (; i < size1 && j < size2; k++)
	{
		if (arr1[i] <= arr2[j]) {
			array[k] = arr1[i];
			i++;
		}
		else {
			array[k] = arr2[j];
			j++;
		}
	}
	while (i < size1)
	{
		array[k] = arr1[i];
		i++;
		k++;
	}
	while (j < size2)
	{
		array[k] = arr2[j];
		j++;
		k++;
	}
}

int main(int argc, const char** argv)
{
	xml_document doc;
	xml_parse_result experiments = doc.load_file("experiments.xml");
	cout << experiments.description() << endl;
	for (auto exp : doc.first_child().first_child().children())
	{
		cout << exp.attribute("name").value() << endl;
	}


	//auto arr = vector<int>{ 6, 5, 12, 10, 9, 1 };
	//for (auto i = 0; i < 1000000; i++)
	//{
	//	arr.push_back(100000 - i);
	//}
	////PrintArray(arr);
	//MergeSort(arr, 0, arr.size() - 1);
	//cout << iters << endl;
	////PrintArray(arr);
	return (0);
}