# First and Last position in a sorted array
-  iteration kari find karipariba
- floor and ceil use kari ame first and last occurance ku find karipariba 

## 1. Brute Force Approach

```java

public class Solution {
    public static int[] firstAndLastPosition(ArrayList<Integer> arr, int n, int k) {
        int ans[] = new int[2];
        ans[0] = -1;
        ans[1] = -1;
        
        for(int i=0; i<n; i++) {
            if(arr.get(i) == k) {
                // first occurance gote thara store haba taku barambar update karibani so condition use kariba
                if(ans[0] == -1) {
                    ans[0] = i;
                }
                // and last occurance stetebele store haba jetebele list ku traverse karsarila pare jauuthi last time element == k haba
                ans[1] = i;
            }
        }
    }

}

```

## 2. Optimal Approach

```java

public class Solution {
     public static int floor(ArrayList<Integer> arr, int n, int k) {
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low<=high) {
            int mid = (low+high)/2;
 
        // may be answer heipare
            if(arr.get(mid) == k) {
                ans = mid;
                high = mid -1;  // left side re ahuri element thaipare jauta ki equal hauthiba 
            }
            else if(arr.get(mid) > k) {
                high = mid -1;
            }
            else{
                low = mid+1; //right re search kariba
            }
        }
        return ans;
    }

    public static int ceil(ArrayList<Integer> arr, int n, int k) {
        int low = 0;
        int high = n-1;
        int ans = -1;

        while(low<=high) {
            int mid = (low+high)/2;
 
        // may be answer heipare
            if(arr.get(mid) == k) {
                ans = mid;
                low = mid + 1;  // right side re ahuri element thaipare jauta ki equal hauthiba 
            }
            else if(arr.get(mid) < k) {
                low = mid + 1;
            }
            else{
                high = mid -1;   // left re search kariba
            }
        }
        return ans;
    }
    
    
    public static int[] firstAndLastPosition(ArrayList<Integer> arr, int n, int k) {
        // Write your code here.
        int ans[] = new int[2];
        ans[0] = floor(arr, n, k);
        ans[1] = ceil(arr, n, k);

        return ans;

    }

}

```

