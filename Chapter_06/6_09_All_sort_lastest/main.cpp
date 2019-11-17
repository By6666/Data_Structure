#include <iostream>
#include <vector>

template <class T>
void BubbleSot(std::vector<T>& data);
void SelectSort(std::vector<int>& data);
void InsertSort(std::vector<int>& data);
void ShellSort(std::vector<int>& data);

namespace QuickSort {
	void Sort(std::vector<int>& data, int start, int end);
	void Sort_self(std::vector<int>& data, int start, int end);
}

namespace MeargeSort {
	void Mearge(std::vector<int>& data, int start, int mid, int end, std::vector<int>& reserve_stg);
	void Sort(std::vector<int>& data, int start, int end, std::vector<int>& reserve_stg);
}


int main() {
	int init[] = /*{ 5,12,16,84,1,25,6,58,32,47,13 }*/{ 11,10,9,8,7,6,5,4,3,2,1 };

	std::vector<int> data(init, init + 11);
	std::vector<int> reserve_container;
	reserve_container.reserve(data.size());

	std::cout << "init data : ";
	for (auto &elem : init) {
		std::cout << elem << "  ";
	}
	std::cout << std::endl;

	//BubbleSot(data);
	//std::cout << "Bubble sort : ";
	//for (auto &elem : data) {
	//	std::cout << elem << "  ";
	//}
	//std::cout << std::endl;

	//SelectSort(data);
	//std::cout << "Select sort : ";
	//for (auto &elem : data) {
	//	std::cout << elem << "  ";
	//}
	//std::cout << std::endl;

	//InsertSort(data);
	//std::cout << "Insert sort : ";
	//for (auto &elem : data) {
	//	std::cout << elem << "  ";
	//}
	//std::cout << std::endl;

	//ShellSort(data);
	//std::cout << "Shell sort : ";
	//for (auto &elem : data) {
	//	std::cout << elem << "  ";
	//}
	//std::cout << std::endl;

	//QuickSort::Sort_self(data, 0, data.size()-1);
	//std::cout << "Quick sort : ";
	//for (auto &elem : data) {
	//	std::cout << elem << "  ";
	//}
	//std::cout << std::endl;

	MeargeSort::Sort(data, 0, data.size() - 1, reserve_container);
	std::cout << "Mearge sort : ";
	for (auto &elem : data) {
		std::cout << elem << "  ";
	}
	std::cout << std::endl;


	system("pause");
	return 0;
}



// Bubble sort
template <class T = int>
void BubbleSot(std::vector<T>& data) {
	for (int i = 0; i < data.size(); ++i) {
		for (int j = 0; j < data.size() - 1; ++j) {
			if (data[j] > data[j + 1]) std::swap(data[j], data[j + 1]);
			else continue;
		}
	}
}


// Select Sort
void SelectSort(std::vector<int>& data) {
	for (int i = 0; i < data.size() - 1; ++i) {
		for (int j = i + 1; j < data.size(); ++j) {
			if (data[i] > data[j]) std::swap(data[i], data[j]);
			else continue;
		}
	}
}

// Insert sort
void InsertSort(std::vector<int>& data) {
	for (int i = 1; i < data.size(); ++i) {
		int prev_index = i - 1;
		int temp = data[i];

		while (prev_index >= 0 && data[prev_index] > temp) {
			data[prev_index + 1] = data[prev_index];
			--prev_index;
		}
		data[prev_index + 1] = temp;
	}
}

// Shell sort
void ShellSort(std::vector<int>& data) {
	int div = 2;
	int jump = data.size() / div;

	while (jump != 0) {
		for (int i = jump; i < data.size(); ++i) {
			int prev_index = i - jump;
			int temp = data[i];

			while (prev_index >= 0 && data[prev_index] > temp) {
				data[prev_index + jump] = data[prev_index];
				prev_index -= jump;
			}
			data[prev_index + jump] = temp;
		}
		jump /= div;
	}
}


// Quick sort
void QuickSort::Sort(std::vector<int>& data, int start, int end) {
	if (start >= end) return;

	int i = start, j = end, key = data[start];

	while (i < j) {
		while (i < j && data[j] >= key) --j;
		data[i] = data[j];
		while (i < j && data[i] <= key) ++i;
		data[j] = data[i];
	}
	data[i] = key;
	Sort(data, start, i - 1);
	Sort(data, i + 1, end);

}

// Quick sort by self
void QuickSort::Sort_self(std::vector<int>& data, int start, int end) {
	if (start >= end) return;

	int i = start, j = end, temp = data[start];

	while (i < j) {
		while (i < j && data[j] >= temp) --j;
		while (i < j && data[i] <= temp) ++i;
		if (i < j) std::swap(data[i], data[j]);
	}

	std::swap(data[i], data[start]);
	Sort_self(data, start, i - 1);
	Sort_self(data, i + 1, end);
}



// Mearge Sort

void MeargeSort::Sort(std::vector<int>& data, int start, int end, std::vector<int>& reserve_stg) {
	if (start >= end) return;
	int mid = (start + end) >> 1;

	Sort(data, start, mid, reserve_stg);
	Sort(data, mid + 1, end, reserve_stg);

	Mearge(data, start, mid, end, reserve_stg);

}

void MeargeSort::Mearge(std::vector<int>& data, int start, int mid, int end, std::vector<int>& reserve_stg) {
	int i = start, j = mid + 1;
	reserve_stg.clear();
	while (i <= mid && j <= end) {
		if (data[i] < data[j]) reserve_stg.push_back(data[i++]);
		else reserve_stg.push_back(data[j++]);
	}

	while (i > mid && j <= end) reserve_stg.push_back(data[j++]);

	while (i <= mid && j > end) reserve_stg.push_back(data[i++]);

	for (auto& elem : reserve_stg)
		data[start++] = elem;
}
