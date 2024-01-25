#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int partition(vector<T>& nums, int pivot_idx, int l, int r) {
	// put pivot into beginning
	if (l != pivot_idx) swap(nums[l], nums[pivot_idx]);
	T pivot = nums[l];

	// partition
	int start = l + 1, end = r;
	while (start < end) {
		if (nums[start] < pivot) {
			start++;
		}
		else {
			swap(nums[start], nums[end]);
			end--;
		}
	}

	// put pivot in between
	if (l != end && nums[end] >= pivot) end--;
	swap(nums[l], nums[end]);

	return end;
}

template <typename T>
void quicksort(vector<T>& nums, int l, int r) {
	// base case is always sorted
	if (l >= r) return;

	// paranoid partition
	int mid, temp_l = l, temp_r = r;
	while ((mid = partition(nums, ((temp_r + temp_l) / 2), temp_l, temp_r)) >= 0) {
		if (r - l < 4 || ((r - l) / 4) + l < mid && mid < ((r - l) * 3 / 4) + l) break;
		if (mid <= ((r - l) / 4) + l) temp_l = mid + 1;
		else temp_r = mid - 1;
	}

	quicksort(nums, l, mid - 1);
	quicksort(nums, mid + 1, r);
	if (mid > 1000) cout << "x";
}

template <typename T>
void quicksort(vector<T>& nums) {
	quicksort(nums, 0, nums.size() - 1);
}
