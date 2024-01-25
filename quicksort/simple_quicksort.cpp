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
	if (nums[end] >= pivot) end--;
	swap(nums[l], nums[end]);

	return end;
}

template <typename T>
void quicksort(vector<T>& nums, int l, int r) {
	// base case is always sorted
	if (l >= r) return;

	// choose pivot as the initial element
	int pivot_idx = l;

	int mid = partition(nums, pivot_idx, l, r);

	quicksort(nums, l, mid - 1);
	quicksort(nums, mid + 1, r);
}

template <typename T>
void quicksort(vector<T>& nums) {
	quicksort(nums, 0, nums.size() - 1);
}
