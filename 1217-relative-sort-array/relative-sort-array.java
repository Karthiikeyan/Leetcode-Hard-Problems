class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
       int i1 = 0, i2 = 0;//i1 for putting in arr1 and i2 for traversing in arr2
       int n = arr2.length;
       while(i2 < n){
        i1 = swap(arr1, arr2[i2++], i1);
       }
        Arrays.sort(arr1,i1, arr1.length);
        return arr1;
    }
    int swap(int[] arr, int target, int from){
       for(int i = from; i < arr.length; i++){
         if(arr[i] == target){
                int temp = arr[from];
                arr[from++] =  arr[i];
                arr[i] = temp;
            }
       }
       return from;
    }
}