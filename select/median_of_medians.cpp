#include <iostream>
#include <vector>
#include <algorithm>
// Alpay Nacar
using namespace std;

template <typename T>
T median_of_medians(vector<T>& nums, int start, int end) {
	if (end - start + 1 < 25) {
		sort(nums.begin() + start, nums.begin() + end + 1);
		return nums[(start + end) / 2];
	}
	vector<T> medians;
	for (int i = 0; i+4 <= end; i += 5) {
		medians.push_back(median_of_medians(nums, i, i+4));
	}
	return median_of_medians(medians, 0, medians.size()-1);
}
