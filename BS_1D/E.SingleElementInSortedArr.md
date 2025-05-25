# Single element ins sorted array

## 1. Brute Force Approach I 

- duplicate setebele habani jebe: arr[i-1] != arr[i] != arr[i+1] haba
- 3 ta edge case re check kariba n=1 thile, i=0 thile and i=n-1 thile
- i=0 thile i+1 index element saha compare kariba and i=n-1 thile i-1 index element saha compare kariba
- and last ku a total check kariba arr[i] != arr[i-1]  and arr[i] != arr[i+1] hauchi ki nahin


```java

public class Solution {

    public static int singleNonDuplicate(ArrayList<Integer> arr) {
    
        int n = arr.size();

        

         // first check kariba array ra size kete, jadi 1 heithiba then ame directly return karidaba se  element ku jehehut single element present achi so 0th index ku return karidaba
         if(n == 1) return arr.get(0);

        for(int i=0 ; i<n; i++) {
            
            //  first index pain check kariba
            if(i==0) {
                if(!arr.get(i).equals(arr.get(i+1))) {
                    return arr.get(i);
                }
            }

            // last index pain check kariba
            else if (i == n-1) {
                if(!arr.get(i).equals(arr.get(i-1))) {
                    return arr.get(i);
                }
            }

           // jadi i je kaunasi index heithiba except i= o and i = n ku chhadi
            else {
                // check kariba arr[i] != arr[i-1]  and arr[i] != arr[i+1], jadi equal na hauthiba then aita single element 
                if(!arr.get(i).equals(arr.get(i+1)) && !arr.get(i).equals(arr.get(i-1))) {
                    return arr.get(i);
                }

                
            }
        }
        return -1;
    }

}

```

## 2. Brute Force Approach II (using XORR)
- same element pair re asile cancel out heijibe
- a ^ a = 0
- a ^ 0 = a

```java

public class Solution {
    public static int singleNonDuplicate(ArrayList<Integer> arr) {

       int n = arr.size();
       int ans = 0;

       for(int i=0; i<n; i++) {
           ans = ans ^ arr.get(i);
        }
        return ans;
    }
}

```

## 3.

```java

public class Solution {

}

```