//gfg

// In a candy store, there are N different types of candies available and the prices of 
// all the N different types of candies are provided to you.
// You are now provided with an attractive offer.
// For every candy you buy from the store and get K other candies ( all are different types ) for free.
// Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money 
// you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum 
// amount of money you have to spend to buy all the N different candies.
// In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.
vector<int> candyStore(int c[], int n, int k) {
    sort(c, c + n);
    int mini = 0, maxi = 0;
    int buy = 0, free = n - 1;
    
    // Calculate the minimum spending
    while (buy <= free) { // Change the condition to <=
        mini += c[buy];
        buy++;
        free -= k;
    }

    buy = n - 1;
    free = 0;
    
    // Calculate the maximum spending
    while (buy >= free) { // Change the condition to >=
        maxi += c[buy];
        buy--;
        free += k;
    }

    return {mini, maxi};
}