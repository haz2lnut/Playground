int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	*returnSize = 2;
	// Bubble sort
	for(int i = 0; i < numsSize-1; i++) {
		for(int j = i+1; j < numsSize; j++) {
			if(nums[i] + nums[j] == target) {
				nums[0] = i;
				nums[1] = j;
				return nums;
			}
		}
	}
	return nums;
}
