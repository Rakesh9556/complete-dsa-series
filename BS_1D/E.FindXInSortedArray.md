# Binary Search to find X in sorted array

## 1. Iterative Approach

```java

public class Solution{
    public static int binarySearch(int nums[]. int target){
        int n = nums.length;
        int low = 0;
        int high = n-1;
        
        while(low<=high) {
            int mid = (low+high)/2;

            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid + 1;
            else high = mid -1;
        }
        return -1;
    }
}

```

## 2. Recursive Approach


``` java

public class Solution {
    public static int binarySearch(int nums[], int low, int high, int target){
        if (low>high) return -1; // base case

        int mid = (low+high)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid] > target)
           return binarySearch(nums, low, mid-1, target);
        else return binarySearch(nums, mid+1, high, target);
    }

    public static int search(int nums[], int target) {
        int n = nums.length;
        return binarySearch(nums, 0, n-1, target);
    }
}

```