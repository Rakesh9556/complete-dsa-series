# Implementing Upper Bound
- lower bound setebele haba jebe element at index i bada haba key element thu
- arr[i] > key
- amaku sabu thu smallest number ra index bahar karibara achhi jauta ki key element tu bada heithiba

## 1. Linear Search

```java

public class Solution {
    public static int upperBound(int []arr, int x, int n){
        // Write your code here.
        for(int i=0; i<n; i++){
            if(arr[i] > x ){
                return i;
            }
        }
        return n;
    }

}

```

## 2. Binary Search

```java

public class Solution {
    public static int upperBound(int []arr, int x, int n){
        int low = 0;
        int high = n-1;
        int ans = n;

        while(low<=high) {
            int mid = (low+high)/2;
            
            // may be answer heipare kahinki na current arr[mid] thu bi chhota element thai pare jauta ki X thu bada
            if(arr[mid] > x) {
                ans = mid;
                high = mid-1; // left re check kariba ahuri chhota element achhi ki jauta X thu bada
            }
            else {
                low = mid + 1; // right re check kariba element, jauta ki X thu bada heithiba
            }
        }
        return ans;
    }

}

```