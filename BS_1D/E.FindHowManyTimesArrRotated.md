# Find how many times array has been rotated

- kete thara rotated heichi janiba pain hele amaku array re lowest element ku dekhibaku padiba seita kau index re present achi

- no. of timess rotated = index of smallest eleemnt 

## 1. Brute Force Approach (using linear search)
- linear search re smallest element ku find karidaba and tara index ku return kariba

```java

public class Solution {

    public static int findKRotation(int []arr){
        int n = arr.length;
        int mini = Integer.MAX_VALUE;

        for(int i=0; i<n; i++) {
            if(arr[i] < mini) {
                mini = arr[i];
            }
        }
        
        for (int i=0; i<n; i++) {
            if(arr[i] == mini) {
                return i;
            }
        }
        return -1;
    }

}

```

## 2. Optimal Approach (using binary search)

```java

public class Solution {
     public static int findKRotation(int []arr){
        int low = 0;
        int high = arr.length -1; 
        int ans = Integer.MAX_VALUE;
        int index = -1;

        while( low <=high) {
            int mid = low + (high-low) /2;
            

            // optimised
            if(arr[low] <= arr[high]) {
                // jadi pura array sorted thiba then minimum element low index re present thiba, so
                if(arr[low] < ans) {
                    ans = arr[low];
                    index = low;
                }
                break;
            }

            // check kariba left part sorted achhi ki nahin
            if(arr[low] <= arr[mid]) {
                // jadi left part sorted achi then amara minimu element low index thiba, so
                if(arr[low] < ans) {
                    ans = arr[low];
                    index = low;
                }

                // so left part re ame smallest element ku store karideiche so ebe left part re kichhi bi smallest elemnt nahin so left part ku eliminate akridaba
                low = mid + 1;
            }
            
            // jadi right part sorted achhi
            else {
                // so jadi right part sorted achhi then minimium element mid index re found haba
                if(arr[mid] < ans) {
                    ans = arr[mid];
                    index = mid;
                }

                // so right part re ame minimum element ku store karideiche so right re au kichhi minimum element nahin so ame right part ku eleiminate karidaba
                high = mid-1;
            }
        }
        return index;

    }

}

```

## 3.

```java

public class Solution {

}

```