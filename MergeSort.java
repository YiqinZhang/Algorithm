public class Solution {
  public int[] mergeSort(int[] array) {
    if (array == null || array.length == 0) {
      return array;
    }
    return mergeSortHelper(array, 0, array.length - 1);
  }
  private int[] mergeSortHelper(int[] array, int low, int high) {
    if (low == high) {
      return new int[]{array[low]}; 
    }
    int mid = low + (high - low) / 2;
    int[] left = mergeSortHelper(array, low, mid);
    int[] right = mergeSortHelper(array, mid + 1, high);    
    return merge(left, right);
  }
  private int[] merge(int[] left, int[] right) {
    int[] res = new int[left.length + right.length];
    int leftId = 0;
    int rightId = 0;
    int index = 0;
    while (leftId < left.length && rightId < right.length) {
      if (left[leftId] <= right[rightId]) {
        res[index++] = left[leftId++];
      } else {
        res[index++] = right[rightId++];
      } 
    }
    while (leftId < left.length){
      res[index++] = left[leftId++];
    }
    while (rightId < right.length){
      res[index++] = right[rightId++];
    }
    return res;
  }
}

