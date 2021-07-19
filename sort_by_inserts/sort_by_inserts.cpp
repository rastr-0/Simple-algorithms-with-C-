#include <iostream>
#include <vector>

std::vector<long>& sort_by_inserts(std::vector<long>&);

int main(){
	long size;
	std::cin >> size;
	std::vector<long> arr(size);
	for(auto& i : arr)
		std::cin >> i;
	arr = sort_by_inserts(arr);
	for(auto i : arr)
		std::cout << i << std::endl;
	return 0;
}
std::vector<long>& sort_by_inserts(std::vector<long>& arr){
	long size = arr.size();
	for(long i = 1; i < size; i++){
		long j = i - 1;
		while(arr[j] > arr[j + 1] && j >= 0){
			std::swap(arr[j], arr[j + 1]);
		       j--;	
		}
	}
	return arr;
}
