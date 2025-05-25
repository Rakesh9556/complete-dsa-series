# Search Insert Position
- sorted array re X element ku insert karipariba pain position bahar kariba 

## 1. Linear Search

```java

public class Solution {
    public static int searchInsert(int [] arr, int m){
        int n = arr.length;
        for(int i=0; i<n; i++){
           if(arr[i] >= m) {
              return i;
        }
      }
      return n;
    }
}

```

## 2. Using Lower bound

```java

public class Solution {
    public static int searchInsert(int [] arr, int m){
        int n = arr.length;
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low<=high) {
            int mid = (low+high)/2;
 
           // may be answer
            if(arr[mid] >= m) {
                ans = mid;
                high = mid-1;  // left re seacrh kariba au chotta element pain jauta m ru bada heithiba
            }
            else {
                low = mid+1;  // right  re search kariba 
            }
        }
        return ans;
    }

}

```
