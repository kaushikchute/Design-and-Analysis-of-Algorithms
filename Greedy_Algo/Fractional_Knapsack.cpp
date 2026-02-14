# include <iostream>
using namespace std;
# include <algorithm>
void solve() 
  {
    // Define the number of items and the maximum capacity of the knapsack
    int n = 8; 
    double capacity = 50;
    
    // Arrays to store values, weights, calculated ratios, and the final value taken per item
    double values[] = {60, 100, 120,32,88,76,97,67};
    double weights[] = {10, 20, 30,33,45,23,32,44};
    double ratios[8];
    double answer[8]={0};
    double totalval=0;

    // Displaying the input values to the console
    cout<<"values :  ";
    for (int i = 0; i < n; i++)
	 {
       cout<<values[i]<<" ";
     }
     
     cout<<endl;
     cout<<"weights : ";
     
    for (int i = 0; i < n; i++)
	 {
       cout<<weights[i]<<" ";
     }
         cout<<endl<<endl;

    // 1. Calculate the value-to-weight ratio for each item
    for (int i = 0; i < n; i++)
	 {
        ratios[i] = values[i] / weights[i];
     }

    // 2. Sort items in descending order based on their ratio (Greedy approach)
    for (int i = 0; i < n - 1; i++)
	 {
        for (int j = i+1; j < n; j++) 
		{
            if (ratios[i] < ratios[j]) 
			{
                // Synchronize swaps across all parallel arrays
                swap(ratios[j], ratios[i]);
                swap(values[j], values[i]);
                swap(weights[j],weights[i]);
            }
        }
    }
    
    int z=0;
    
   double  curr_capacity=capacity;
   
   // 3. Process items while there is remaining capacity and items left to check
   while(curr_capacity>0 && z < n)
   {
    // Case: The current item can fit entirely in the knapsack
   	if(weights[z] <= curr_capacity)
   	{
   		answer[z]=values[z]; // Take the full value
   		curr_capacity -= weights[z]; // Subtract item weight from current capacity
   	
   		totalval+= values[z]; // Add full value to total profit
   			z++; // Increment index to next item
	   	
	}
    // Case: Only a fraction of the item can fit in the remaining capacity
	else{
	  
	  // Store the proportional value in the answer array
	  answer[z]= curr_capacity*ratios[z];
	  totalval+=curr_capacity*ratios[z]; // Add fractional profit to total
	  curr_capacity=0; // Set capacity to zero as the bag is now full
	  
	}
	
	
	
}
// Display the values of the items (or parts of items) added to the bag
cout<<"the items added in bag are having values :"<<endl;
	
	 for (int i = 0; i < n; i++)
	 {
        cout<<answer[i]<<" ";
     }
     cout<<endl;
     
// Output the final total value and details of the last item processed
cout <<"\ntotal value of filled bag : "<<totalval<<endl;
cout<< "the fractional part object is : "<<z<< " \nwith weight "<< weights[z]<<" \nand value "<<values[z]<<endl;
}
    
    
    
    int main ()
    {
    	solve();
	}
