void selection(int arr[], int n) {
	int i, j, m; 
	for (i = 0; i < n-1; i++) {
    		m = i;
    		for (j = i+1; j < n; j++) {
        			if (arr[j] < arr[m]) {
            			m = j;
        			}
    		}
    	// Swap the found minimum element with the first element
            int temp = arr[m];
    	arr[m] = arr[i];
    	arr[i] = temp;
	}
}
