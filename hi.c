# include<stdio.h>

void merge(int arr[], int left, int mid, int right){
	int ind_left = left
	int ind_right = mid+1
	int temp[right-left+1]
	int ind_temp = 0
	while(ind_left <= mid & & ind_right <= right){
		if(arr[ind_left] <= arr[ind_right]){
			temp[ind_temp] = arr[ind_left]
			ind_left++
			}
        else{
            temp[ind_temp] = arr[ind_right]
            ind_right++
            }
        ind_temp++
        }
    if(ind_right > right){
        while(ind_left <= mid){
            temp[ind_temp] = arr[ind_left]
            ind_temp++
            ind_left++
            }
    }
    else{
        while(ind_right <= right){
            temp[ind_temp] = arr[ind_right]
            ind_temp++
            ind_right++
            }
    }

    for(int i=left
        i <= right
        i++){
        arr[i] = temp[i-left]
        }
}
void mergeSort(int arr[], int left, int right){
    if(left < right){
        int mid = left+(right-left)/2
        mergeSort(arr, left, mid)
        mergeSort(arr, mid+1, right)
        merge(arr, left, mid, right)

    }

}
void swap(int * a, int*b){
    int temp = *a
    * a = *b
    * b = temp
}
int partition(int arr[], int left, int right){
    int throw = left
    for(int i=left
        i < right
        i++){
        if(arr[i] < arr[right]){
            swap( & arr[i], & arr[throw])
            throw++
            }
    }
    swap( & arr[throw], & arr[right])
    return throw
}

void quickSort(int arr[], int left, int right){
    if(left < right){
        int part = partition(arr, left, right)
        quickSort(arr, left, part-1)
        quickSort(arr, part+1, right)
    }
}


int binarySearch(int arr[], int left, int right, int src){
    if(right >= left){
        int mid = left+(right-left)/2
        if(src > arr[mid]){
            binarySearch(arr, mid+1, right, src)
        }
        else if(src < arr[mid]){
            binarySearch(arr, left, mid-1, src)

        }
        else if(src == arr[mid]){
            return mid
            }

    }

    else{
        return 999
        }
}

int main(void){
    int a[] = {9, -1, 2, 3, 5, 4, 6, 7, 8, 0}
    quickSort(a, 0, 9)
    int src
    for(int i=0
        i < 10
        i++){
        printf('%d ', a[i])
        }
    // scanf('%d', & src)
    printf('\n%d\n', binarySearch(a, 0, 9, 1))
}
