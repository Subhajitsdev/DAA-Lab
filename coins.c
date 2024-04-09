#include<stdio.h>

int MinimumNumCoins(int coins[], int n, int target) { 
  int table[n][target + 1],i,j;
// initialising table
for ( i = 0; i < n; i++)
    table[i][0] = 0;    
for (j = 1; j <= target; j++)
    table[0][j] = j;
for (i = 1; i < n; i++) 
{  for (j = 1; j <= target; j++) 
 {  if (coins[i] <= j)
            table[i][j] = 1 + table[i][j - coins[i]]; //j-coins[i] as remaining target value will constantly chjange as coins are getting accumulated
        else
            table[i][j] = table[i - 1][j];
    }
}
return table[n - 1][target];
}
int main() {
  int coins[] = { 1, 5, 10, 25 };//denominitions
  int n = sizeof(coins) / sizeof(coins[0]);
  int target = 31;//target
  printf("Minimum no of coins is %d\n", MinimumNumCoins(coins, n, target));
  return 0;
}