int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j)
    {
         while (a[i] <= pivot && i <= high)
         {
            i++;
         }
         while (a[j] > pivot) {
            j--;
        }
         if (i < j)
         {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

 void qs(int a[],int low,int high)
 {
	 int mid;
	 if(low<high)
	 {
		 mid = partition(a, low, high);
		 qs(a,low,mid-1);
		 qs(a,mid+1,high);
	 }
 }
