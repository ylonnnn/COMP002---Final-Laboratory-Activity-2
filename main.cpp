#include <algorithm>
#include <iomanip>
#include <iostream>

int main() {

  int row_size, col_size;

  std::cout << "WELCOME!\n\nEnter the row size of an array: ";
  std::cin >> row_size;

  std::cout << "Enter the column size of an array: ";
  std::cin >> col_size;

  // Initialize the 2D array and variables that will be used for calculation
  int arr[row_size][col_size];
  int sums[row_size], even_total = 0, even_n = 0, odd_total = 0, odd_n = 0;

  std::cout << "\n";

  // Array Initialization
  for (int i = 0; i < row_size; i++) {

    std::cout << "Data entry for row " << i + 1 << "\n";

    // Calculate the sum of each row
    int sum = 0;
    for (int j = 0; j < col_size; j++) {

      int num;
      std::cout << "Enter a number for [" << i << "][" << j << "]: ";
      std::cin >> num;

      arr[i][j] = num;
      sum += num;

      // Add even and odd numbers to their corresponding total variables, and
      // their occurrence counters
      if (num % 2 == 0) {
        even_total += num;
        even_n++;
      } else {
        odd_total += num;
        odd_n++;
      }
    }

    // Assign the sum of each row to the corresponding index in another array
    // dedicated for the sum of each rows
    sums[i] = sum;

    std::cout << "\n";
  }

  std::cout << "Array Content\n";

  int highest = 0, lowest = 0;

  for (int i = 0; i < row_size; i++) {

    // Determine the index (row) of the highest and the lowest sum
    highest = sums[highest] == std::max(sums[highest], sums[i]) ? highest : i;
    lowest = sums[lowest] == std::min(sums[lowest], sums[i]) ? lowest : i;

    // Display the values of the row
    for (int j = 0; j < col_size; j++) {
      std::cout << arr[i][j] << "\t";
    }

    std::cout << "\n";
  }

  // Display the row with the lowest sum
  std::cout << "The lowest sum of each row is in row: " << lowest + 1
            << " and the sum is: " << sums[lowest] << "\n";

  // Display the row with the highest sum
  std::cout << "The highest sum of each row is in row: " << highest + 1
            << " and the sum is: " << sums[highest] << "\n";

  // Display the sum of all even numbers
  std::cout << "The total sum of all even numbers in Array is: " << even_total
            << "\n";

  // Display the sum of all odd numbers
  std::cout << "The total sum of all odd numbers in Array is: " << odd_total
            << "\n";

  // Display the average all even numbers
  std::cout << std::setprecision(2) << std::fixed
            << "The average of all even numbers in Array is: "
            << (float)(even_total) / even_n << "\n";

  // Display the average all odd numbers
  std::cout << "The average of all odd numbers in Array is: "
            << (float)(odd_total) / odd_n << "\n";

  return 0;
}