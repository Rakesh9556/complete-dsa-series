# Implementing Lower Bound

- lower bound setebele haba jetebele elemennt at index i bada equal ki bada haba key element tharu
- a[i] >= key
- jadi lower bound nathiba then ame array ra size ku return karidaba

## 1. Using linear search

```java

public class Solution {
    public static int lowerBound(int []arr, int n, int x) {
        for(int i=0; i<n; i++){
            if(arr[i] >= x)  return i;
        }
        return n;
    }

}

```

## 2. Using binary search

```java

public class Solution {
     public static int lowerBound(int []arr, int n, int x) {
        // Write your code here
        int low = 0;
        int high = n-1;
        int ans = n;
    

        while(low<=high) {
            int mid = (low+high)/2;
            
            if(arr[mid] >= x) {
                ans = mid;
                high = mid-1;
            } 
            else {
                low = mid + 1;
            }
        }
        return ans;
    }

}

```