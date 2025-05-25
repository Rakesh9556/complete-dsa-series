# Floor and Ceiling
- Floor(ground) : sabu thu bada element jauta ki {key element} thu chota (arr[i] <= key)  
- Ceil(top) : sabu thu chhota element jauta ki {key element} thu bada (arr[i] >= key) --- also lower bound 

## 1. Using Lower bound

```java

public class Solution {
        public static int findFloor(int[] a, int n, int x) {
      int low = 0;
      int high = n-1;
      int ans = -1;

      while(low<=high) {
        int mid = (low+high)/2;

       // may be the answer
        if(a[mid] <= x){
          ans = a[mid];
          low = mid +1; // may be right ku au larger element thaipare jauta ki X thu chhota hauthiba
        }
        else {
          high = mid -1;   // left re search kariba
        }
      }
      return ans;
    }

    public static int findCeil(int[] a, int n, int x) {
      int low = 0;
      int high = n-1;
      int ans = -1;

      while(low<=high) {
        int mid = (low+high)/2;

       // may be the answer
        if(a[mid] >= x){
          ans = a[mid];
          high = mid - 1; // may be left ku au smalller element thaipare jauta ki X thu bada hauthiba
        }
        else {
          low = mid + 1;   // right re search kariba
        }
      }
      return ans;
    }
    
    public static int[] getFloorAndCeil(int[] a, int n, int x) {
      int ans[] = new int[2];
      ans[0] = findFloor(a, n, x);
      ans[1] = findCeil(a, n, x); 
      return ans;
    }

}

```
