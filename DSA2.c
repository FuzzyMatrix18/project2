#include <stdio.h>

// Function to calculate the level of a number in the triangular number pattern
int calculateLevel(int num, int triangularNum) {
  int level = 0;
  int sum = 0;
  while (sum < num) {
    level++;
    sum += level;
  }
  if (sum == num) {
    return level;
  } else {
    return -1; // Invalid number
  }
}

// Function to calculate the number of elements in the largest equilateral triangle with a given top number
int calculateEquilateralElements(int num, int triangularNum) {
  int level = calculateLevel(num, triangularNum);
  if (level == -1) {
    return -1;
  }
  int elements = (level - 1) * (level - 1) + 1;
  return elements;
}

// Function to find the starting number of the largest equilateral triangle with a given top number
int calculateEquilateralStart(int num, int triangularNum) {
  int level = calculateLevel(num, triangularNum);
  if (level == -1) {
    return -1;
  }
  int start = num - (level - 1) * (level - 1);
  return start;
}

// Function to print the numbers in the largest equilateral triangle with a given top number
void printEquilateralTriangle(int num, int triangularNum) {
  int start = calculateEquilateralStart(num, triangularNum);
  int elements = calculateEquilateralElements(num, triangularNum);
  if (start == -1) {
    printf("Invalid number.\n");
    return;
  }
  for (int i = 0; i < elements; i++) {
    printf("%d ", start + i);
  }
  printf("\n");
}

int main() {
  int triangularNum, num;
  
  // Input triangular number
  printf("Enter the triangular number (like 153): ");
  scanf("%d", &triangularNum);
  
  // Input a natural number
  printf("Enter a natural number between 1 and %d: ", triangularNum);
  scanf("%d", &num);
  
  // Calculate and print the level of the number
  int level = calculateLevel(num, triangularNum);
  if (level == -1) {
    printf("Invalid number.\n");
  } else {
    printf("The level of %d is %d.\n", num, level);
  }
  
  // Print the numbers in the largest equilateral triangle
  printEquilateralTriangle(num, triangularNum);

  return 0;
}