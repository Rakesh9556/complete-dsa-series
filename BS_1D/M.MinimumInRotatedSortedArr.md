# Minimum in Rotated Sorted Array

## 1. Brute Force Approach (Linear Search)

```java

public class Solution {
    public static int findMin(int []arr) {
        int n = arr.length;
        int res = Integer.MAX_VALUE;

        for(int i=0; i<n; i++) {
            if(arr[i] < res) {
                res = arr[i];
            }
        }
        return res;
    }
}

```

## 2. Optimal Approach (Binary Search)

- search in rotated sorted array concept use heichi

```java

public class Solution {
    public static int findMin(int []arr) {
        // Write your code here.
        int low = 0;
        int high = arr.length -1;

        int ans = Integer.MAX_VALUE;

        while(low <= high) {
            int mid = low +(high-low)/2;

            // left part check kariba sorted achhi ki nahin
            if(arr[low] <= arr[mid]) {
                // jadi sorted achi then arr[low] re sabu thu smallest find haba
                ans = Math.min(ans, arr[low]);

                // so amaku smallest element darakar so jadi left sorted thiba then upara condion  dwara ame left part ra sabu thu sammlest ku access kaeisariche
                // so left part ku eliminate karidaba
                low = mid + 1;
            }

            // jadi left part sorted achhi
            else {
                // jadi sorted achhi tahale sabu thu minimum eleement mid re thiba
                // so minimum ku store kariba
                ans = Math.min(ans, arr[mid]);

                // so jadi right part sorted achhi then ame upara step re ame right part ra sabu thu minimum element store karisariche
                // so ebe right part ku eliminate karidaba
                high = mid-1; 
            }
        }
        return ans;
    }

}

```

## 3. Binary Search optimised

- jadi ame dekhiba j rotated pare bi jadi low index re thiba element small hue high index re thiba element thu, then ame direst ans re arr[low] ku minimum set karidaba and sethi break karidaba searching ku kahinki na ama answer milijaithiba

```java

public class Solution {
    public static int findMin(int []arr) {
        // Write your code here.
        int low = 0;
        int high = arr.length -1;

        int ans = Integer.MAX_VALUE;

        while(low <= high) {
            int mid = low +(high-low)/2;

            // jadi whole array sorted achhi
            if(arr[low] <= arr[high]) {
                ans = Math.min(ans, arr[low]);   // optimised
                break;
            }

            // left part check kariba sorted achhi ki nahin
            if(arr[low] <= arr[mid]) {
                // jadi sorted achi then arr[low] re sabu thu smallest find haba
                ans = Math.min(ans, arr[low]);

                // so amaku smallest element darakar so jadi left sorted thiba then upara condion  dwara ame left part ra sabu thu sammlest ku access kaeisariche
                // so left part ku eliminate karidaba
                low = mid + 1;
            }

            // jadi left part sorted achhi
            else {
                // jadi sorted achhi tahale sabu thu minimum eleement mid re thiba
                // so minimum ku store kariba
                ans = Math.min(ans, arr[mid]);

                // so jadi right part sorted achhi then ame upara step re ame right part ra sabu thu minimum element store karisariche
                // so ebe right part ku eliminate karidaba
                high = mid-1; 
            }
        }
        return ans;
    }

}

```