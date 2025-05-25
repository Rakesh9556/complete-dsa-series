# Number of occurance 
- iteration re find karipariba
 

## 1. Brute Approach

```java

public class Solution {
    public static int count(int arr[], int n, int x) {
        //Your code goes here
        int cnt = 0;

        for(int i=0; i<n; i++) {
            if(arr[i] == x) {
                cnt ++;
            }
        }
        return cnt;
    }
}

```

## 2. Optimal Approach using binary search

- as ame previous problem ru first au last occurance bahar kariba janiche so
- total occurance = lastOccurance - firstOccurance + 1
- jadi element present nahin array re then result ku {-1, -1} return kariba

```java

public class Solution {
     public static int firstOccurance(int arr[], int n, int x) {
       int low = 0;
       int high = n-1;
       int ans = -1;

       while(low<=high) {
           int mid = low + (high-low)/2;

           if(arr[mid] == x) {
               ans = mid;
               high = mid - 1;  // left re check kariba 
           }
           else if (arr[mid] < x) {
               low = mid+1; // right re check kariba
           }
            else {
                high = mid-1;
            }
       }
       return ans;
   }

    public static int lastOccurance(int arr[], int n, int x) {
       int low = 0;
       int high = n-1;
       int ans = -1;

       while(low<=high) {
           int mid = low + (high-low)/2;

           if(arr[mid] == x) {
               ans = mid;
               low = mid + 1;  // right re check kariba 
           }
           else if (arr[mid] < x) {
               low = mid+1; // right re check kariba
           }
            else {
                high = mid-1;
            }
       }
       return ans;
   }
    

    public static int[] firstAndLastPosition (int  arr[], int n, int x) {
        int first = firstOccurance(arr, n, x);
        if(first == -1) {
            return new int[] {-1, -1};
        }
        int last = lastOccurance(arr, n, x);
        return new int[] {first, last};
    }


    public static int count(int arr[], int n, int x) {
        int ans[] = firstAndLastPosition(arr, n, x);
        if(ans[0] == -1) return 0;
        return (ans[1] - ans[0] + 1);
    }

}

```


## 3. Using lowerBound and upperBound

- lowerBound and upperBound ra algorithm use kari solve kariba
- lowerBound re amaku first occuring index milijiba
- upperBound re amaku last occuring index ra next index miliba, so [up - 1] --> hauchi amara last occuring index


```java

public class Solution {
 public static int lowerBound(int arr[], int n, int x) {
       int low = 0;
       int high = n-1;
       int ans = n;

       while(low<=high) {
           int mid = low + (high-low)/2;

        // may be answer heipare
           if(arr[mid] >= x) {
               ans = mid;
               high = mid - 1;  // left re check kariba 
           }
           else{
               low = mid+1; // right re check kariba
           }
       }

       return ans;
    }

    public static int upperBound(int arr[], int n, int x) {
       int low = 0;
       int high = n-1;
       int ans = n;

       while(low<=high) {
           int mid = low + (high-low)/2;

        // may be answer heipare
           if(arr[mid] > x) {
               ans = mid;
               high = mid -1;  // left re check kariba 
           }
           else {
               low = mid+1; // right re check kariba
           }
       }
       return ans;
    }
    public static int[] firstAndLastOccurance(int arr[], int n, int x) {
        int lb =  lowerBound(arr, n, x);
        if(lb == n || arr[lb] != x) return new int[] {-1, -1};
        return new int[] {lb, upperBound(arr, n, x) - 1};
    }
        
    public static int count(int arr[], int n, int x) {
        int ans[] = firstAndLastOccurance(arr, n, x);

       // jadi first index -1 thiba then element nahin so 0 return kariba
        if (ans[0] == -1) return 0;

        return (ans[1] - ans[0] + 1);
        
    }

}

```