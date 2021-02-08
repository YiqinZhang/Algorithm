import java.util.Arrays;

public class MergeSortOpt {
  public int[] mergeSort(int[] array) {
    if (array == null || array.length == 0) {
      return array;
    }
    int[] helper = new int[array.length];
    mergeSortHelper(array, helper, 0, array.length - 1);
    return array;
  }
  private void mergeSortHelper(int[] array, int[] helper, int low, int high) {
    if (low >= high) {
      return; 
    }
    int mid = low + (high - low) / 2;
    mergeSortHelper(array, helper, low, mid);
    mergeSortHelper(array, helper, mid + 1, high);    
    merge(array, helper, low, mid, high);
  }
  private void merge(int[] array, int[] helper, int low, int mid, int high) {
    for (int i = low; i <= high; i++) {
      helper[i] = array[i];
    }
    int leftId = low;
    int rightId = mid + 1;
    while (leftId <= mid && rightId <= high) {
      if (helper[leftId] <= helper[rightId]) {
        array[low++] = helper[leftId++];
      } else {
        array[low++] = helper[rightId++];
      } 
    }
    while (leftId <= mid) {
      array[low++] = helper[leftId++];
    }
  }


public static void main(String[] args) {
	MergeSortOpt solution = new MergeSortOpt();
	int[] array = null;
	array = solution.mergeSort(array);
	System.out.println(Arrays.toString(array));

        array = new int[0];
        array = solution.mergeSort(array);
	System.out.println(Arrays.toString(array));

        array = new int[]{1,2,3,4};
        array = solution.mergeSort(array);
        System.out.println(Arrays.toString(array));

        array = new int[]{4,3,2,1};
        array = solution.mergeSort(array);
        System.out.println(Arrays.toString(array));

        array = new int[]{2,4,1,6,3};
        array = solution.mergeSort(array);
        System.out.println(Arrays.toString(array));
}
}
