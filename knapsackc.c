void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sortItems(int n, int weights[], int values[], double ratio[])
{
  int i,j;
  for (i = 0; i &lt; n - 1; i++)
  {
    for (j = 0; j &lt; n - i - 1; j++)
    {
      if (ratio[j] &lt; ratio[j + 1])
      {
      swap(&amp;weights[j], &amp;weights[j + 1]);
      swap(&amp;values[j], &amp;values[j + 1]);
      double temp = ratio[j];
      ratio[j] = ratio[j + 1];
      ratio[j + 1] = temp;
      }
    }
  }
}
// Function to solve the continuous knapsack problem using greedy approximation
void knapsackContinuous(int W, int weights[], int values[], int n)
{
  double ratio[n];
  int i;
  for (i = 0; i &lt; n; i++) 
  {
  ratio[i] = (double) values[i] / weights[i];
  }
    sortItems(n, weights, values, ratio);
  int currentWeight = 0;
  double finalValue = 0.0;
  printf(&quot;Items included:\n&quot;);
  for (i = 0; i &lt; n; i++) 
  {
    if (currentWeight + weights[i] &lt;= W)
      {
      currentWeight += weights[i];
      finalValue += values[i];
      printf(&quot;Item %d (weight: %d, value: %d)\n&quot;, i + 1, weights[i], values[i]);
      } 
    else
      {
      int remain = W - currentWeight;
      finalValue += values[i] * ((double) remain / weights[i]);
      printf(&quot;Item %d (weight: %d, value: %.2f) (fractional)\n&quot;, i + 1, remain, values[i]
      * ((double) remain / weights[i]));
      break;
      }
  }
  printf(&quot;Maximum value in Knapsack = %.2f\n&quot;, finalValue);
}
int main()
{
  int values[] = {10,5,15,7,6,18,3};
  int weights[] = {2,3,5,7,1,4,1};
  int W =15;
  int n = sizeof(values) / sizeof(values[0]);
  knapsackContinuous(W, weights, values, n);
  return 0;
}
