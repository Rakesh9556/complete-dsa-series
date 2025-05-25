# Search in rotated sorted array I

## 1. Using Linear Seacrh

```java

public class Solution {
     public static int search(ArrayList<Integer> arr, int n, int k) {
        // Write your code here.
        for(int i=0; i<n; i++) {
            if(arr.get(i) == k) return i;
        }
        return -1;
    }
}

```

## 2. Optimal Approach (using binary search)

- jehetu array roteation heichi so first amaku sorted half find karibaku padiba
- se sorted haldf re ame amara key element ku search kariba, jadi key element present nathiba then se half ku eliminate karidaba
- next half re ame element ku search kariba and a half re element nathile aku eliminate karidaba

```java

public class Solution {
    public static int search(ArrayList<Integer> arr, int n, int k) {
        
        int low = 0;
        int high = n-1;

        while (low <= high) {
            int mid = low + (high-low)/2;

            if(arr.get(mid) == k)  return mid;

            // check kariba left part sorted achhi na nahin
            if(arr.get(low) <= arr.get(mid)) {
                // then check kariba a left part re element achhi ki nahin
                if(arr.get(low) <= k && k <= arr.get(mid)) { 
                    // jadi element achhi then search space ku left side karidaba
                    high = mid -1;
                } 
                // jadi element left part re nahin then search space  right ku karidaba
                else {
                    low = mid+1;
                }
            }
            
            // so jadi right part sorted achhi
            else {  
                // then check kariba j element right part re achhi  ki nahin
                if( arr.get(mid) <= k && k <= arr.get(high)) {
                    // jadi element achhi then search space  right ku karidaba
                    low = mid +1;
                }
                // jadi element right part re nahin then search space left ku karidaba
                else {
                    high = mid-1;
                }

            }
        }
        return -1;
    }

}

```

