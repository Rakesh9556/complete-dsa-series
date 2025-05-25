# Search in rotated sorted array II
- rotated sorted array deithiba (contain duplicates), and gote key element deithiba, jadi key elemet present achhi then true return kariba otherwise false

## 1. Brute Approach (Linear search)

```java

public class Solution {
    public static boolean searchInARotatedSortedArrayII(int []A, int key) {
        int n = A.length;

        for (int i=0; i<n; i++) {
            if(A[i] == key) {
                return true;
            }
        }
        return false;
    }
}

```

## 2. Optimal Approach (Binary Search)
- same previous part1 bhali solve kariba but ethire gote edge case handle karibaku padiba jehetu duplicate elements present achi so

```java

public class Solution {
    public static boolean searchInARotatedSortedArrayII(int []A, int key) {
        int n = A.length;
        int low = 0;
        int high = n-1;

        while(low<=high) {
            int mid = low +  (high -low)/2;

            if(A[mid] == key) return true;

            // edge case
            if (A[low] == A[mid] &&  A[high] == A[mid]) {
                low = low + 1;
                high = high - 1;
                continue;
            }

            // jadi equal helani 
            // then check kariba left part  sorted achhi ki nahin
            if(A[low] <= A[mid]) {
                // jadi sorted achhi tahale check kariba j key element present achhi na nahin
                if(A[low] <= key && key <= A[mid]) {
                    //jadi key element present achhi then seaarch space left ku kariba
                    high = mid-1;
                }
                // jadi key element left part rfe present nahin, then search space ku right ku kariba
                else {
                    low = mid+1;
                }
            }

            // jadi right part soted achhi 
            else{
                // then check kariba j element right part re achhi na nahin
                if(A[mid] <= key && key <= A[high]) {
                    // jadi element present achhi then search space ku right ku kariba
                    low = mid+1;
                }
                // jadi element right part re nahin then search space ku left ku karidaba
                else {
                    high = mid-1;
                }
            }

        }
        return false;
    }

}

```

## 3.

```java

public class Solution {

}

```