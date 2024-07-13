
// LuvBabbar_lec-24

/*

SIEVE OF ERATOSTHENES

*/

//We'll assumen all the nos are prime
//Then we'll start from 2
// 2 is marked as Prime so we'll count it
//Then we'll mark all multiples of 2 as non-prime
//Then we'll move to 3
//3 is marked as prime so we'll count it
//Then we'll mark all multiples of 3 as non-prime
//We'll keep doing this until sqrt(n)
//If we land on some number that is marked non-prime = We'll move to next one
//If the number we land on is marked as Prime = We'll count it and then mark all it's multiples as non-prime


#include<bits/stdc++.h>
using namespace std;
int main(){

    int n;
    cin>>n;
    int t=sqrt(n)+1;

    vector<bool> arr(n+1,true);
    arr[0]=arr[1]=false;
    int count =0;
    for(int i{2};i<t;i++){
        if(arr[i]){
            int j=i*i;
            while(j<n){
                arr[j]=false;
                j+=i;
            }
        }
    }
    for(int i{2};i<n;i++){
        if(arr[i]){
            count++;
        }
    }
    cout<<count;

    return 0;
}


/*

GCD/HCF == EUCLID'S THEOREM

*/

//gcd(a,b)=gcd(a-b,b) --> gcd(a%b,b)
// a*b=lcm(a,b)*gcd(a,b) so we can find lcm(a,b)=a*b/gcd(a,b)

#include<bits/stdc++.h>
using namespace std;

int fgcd(int a,int b){
    if(b==0){return a;}
    else if(a==0){
        return b;
    }
    else if(a<0 or b<0){
        return -1;
    }
    if(b>a){
        return fgcd(a,b-a);
    }
    else{
        return fgcd(a-b,b);
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<fgcd(a,b)<<endl;
    return 0;
}

/* 

Modulo Arithmetics

*/

// https://codeforces.com/blog/entry/72527

// Why do we modulo by 10^9+7 in some questions?
//So that our answer is in range and we prevent overflow
// 10^9+7 is a prime number
// (a+b)%m = a%m+b%m
// a%m*b%m=(a*b)%m

/*

Fast Exponentiation

*/

//When we have to find a^b, we use a loop where result=result*a and run it b times
//Therefore our Time Complexity is O(n)
//But by using fast exponentiation, we can do this in O(logn)

#include<bits/stdc++.h>
using namespace std;

long long int m;
//We have to find (n^w)%m
//if(w==even) = we'll do square of n^i recursively until i==w(we'll check this by dividing w/2 after every square )
//if(w==odd) = we'll do same as even but we'll just multiply our answer with extra x(because n==1 and we wanted 0)
long long int expo(long long int n,long long  int w){
    if(w==0) return 1;
    else if(w&1) return expo(((n)%m)*((n)%m),w>>1)*n;
    else{
        return expo(((n)%m)*((n)%m)%m,w>>1);
    }
}

int main(){
    long long int n,w;
    cin>>n>>w>>m;
    cout<<expo(n,w);
    return 0;
}

/*
Segmented Sieve
*/

// C++ program to print  all primes smaller than
// n using segmented sieve
// Step 1: Sieve up to sqrt(n)

// https://chatgpt.com/share/1a4ef732-6ce0-457e-ae92-e548748a3e9b
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int limit = sqrt(n) + 1;
    vector<bool> is_prime(limit, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i < limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    // Collect primes up to sqrt(n)
    vector<int> primes;
    for (int i = 2; i < limit; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    // Step 2: Segmented Sieve for range [2, n]
    int segment_size = limit;
    vector<bool> segment(segment_size, true);
    int count = 0;

    for (int low = 2; low < n; low += segment_size) {
        fill(segment.begin(), segment.end(), true);

        int high = min(low + segment_size, n);

        for (int prime : primes) {
            int start = max(prime * prime, (low + prime - 1) / prime * prime);
            for (int j = start; j < high; j += prime) {
                segment[j - low] = false;
            }
        }

        for (int i = low; i < high; i++) {
            if (segment[i - low]) {
                count++;
            }
        }
    }

    cout << count;

    return 0;

}



/*
Pigeonhole Principle
*/
// Detecting duplicates
#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}

int main() {
    std::vector<int> nums = {1, 3, 4, 2, 2};
    if (containsDuplicate(nums)) {
        std::cout << "Duplicate found" << std::endl;
    } else {
        std::cout << "No duplicates" << std::endl;
    }
    return 0;
}

//Birthday Paradox
#include <iostream>
#include <vector>
#include <unordered_set>
#include <ctime>
#include <cstdlib>

bool hasSharedBirthday(const std::vector<int>& birthdays) {
    std::unordered_set<int> seen;
    for (int birthday : birthdays) {
        if (seen.find(birthday) != seen.end()) {
            return true;
        }
        seen.insert(birthday);
    }
    return false;
}

int main() {
    std::srand(std::time(0));
    const int PEOPLE = 23;
    const int DAYS_IN_YEAR = 365;
    std::vector<int> birthdays(PEOPLE);

    for (int i = 0; i < PEOPLE; ++i) {
        birthdays[i] = std::rand() % DAYS_IN_YEAR;
    }

    if (hasSharedBirthday(birthdays)) {
        std::cout << "At least two people share a birthday." << std::endl;
    } else {
        std::cout << "No shared birthdays." << std::endl;
    }

    return 0;
}

//Find Missing Elements
#include <iostream>
#include <vector>

int findMissingNumber(const std::vector<int>& nums) {
    int n = nums.size();
    int totalSum = (n * (n + 1)) / 2;
    int arraySum = 0;
    for (int num : nums) {
        arraySum += num;
    }
    return totalSum - arraySum;
}

int main() {
    std::vector<int> nums = {1, 2, 4, 5, 6};
    std::cout << "Missing number: " << findMissingNumber(nums) << std::endl;
    return 0;
}

//Pigeonhole Sort
#include <iostream>
#include <vector>

void pigeonholeSort(std::vector<int>& nums) {
    int min = *std::min_element(nums.begin(), nums.end());
    int max = *std::max_element(nums.begin(), nums.end());
    int range = max - min + 1;

    std::vector<int> holes(range, 0);

    for (int num : nums) {
        holes[num - min]++;
    }

    int index = 0;
    for (int i = 0; i < range; ++i) {
        while (holes[i]-- > 0) {
            nums[index++] = i + min;
        }
    }
}

int main() {
    std::vector<int> nums = {8, 3, 2, 7, 4, 6, 8};
    pigeonholeSort(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
Catalan Number 
*/
// https://www.geeksforgeeks.org/c-program-for-program-for-nth-catalan-number/

/*
INC-EXCLUSION PRINCIPLE
*/

// https://www.geeksforgeeks.org/inclusion-exclusion-principle-and-programming-applications/

/*

Factorial of Large Numbers

*/

//Multiply method https://www.geeksforgeeks.org/factorial-large-number/

// C++ program to compute factorial of big numbers
#include <iostream>
using namespace std;

// Maximum number of digits in output
#define MAX 500

int multiply(int x, int res[], int res_size);

// This function finds factorial of large numbers
// and prints them
void factorial(int n)
{
	int res[MAX];

	// Initialize result
	res[0] = 1;
	int res_size = 1;

	// Apply simple factorial formula n! = 1 * 2 * 3
	// * 4...*n
	for (int x = 2; x <= n; x++)
		res_size = multiply(x, res, res_size);

	cout << "Factorial of given number is \n";
	for (int i = res_size - 1; i >= 0; i--)
		cout << res[i];
}

// This function multiplies x with the number
// represented by res[].
// res_size is size of res[] or number of digits in the
// number represented by res[]. This function uses simple
// school mathematics for multiplication.
// This function returns the
// new value of res_size
int multiply(int x, int res[], int res_size)
{
	int carry = 0; // Initialize carry

	// One by one multiply n with individual digits of res[]
	for (int i = 0; i < res_size; i++) {
		int prod = res[i] * x + carry;

		// Store last digit of 'prod' in res[]
		res[i] = prod % 10;

		// Put rest in carry
		carry = prod / 10;
	}

	// Put carry in res and increase result size
	while (carry) {
		res[res_size] = carry % 10;
		carry = carry / 10;
		res_size++;
	}
	return res_size;
}

// Driver program
int main()
{
	factorial(100);
	return 0;
}


//Linked List
#include <bits/stdc++.h>
using namespace std;

//* Node Class
class Node {
public:
	int data;
	Node* prev;
	Node(int n)
	{
		data = n;
		prev = NULL;
	}
};

//* Function to perform desired operation
void Multiply(Node* head, int i)
{
	Node *temp = head,
		*prevPtr = head; // Temp variable for keeping head
	
	int carry = 0;

	//* Perform operation until temp becomes NULL
	while (temp != NULL) {
		int prod = temp->data * i + carry;
		temp->data = prod % 10; //* Stores the last digit
		carry = prod / 10;
		prevPtr = temp; //* Change Links
		temp = temp->prev; //* Moving temp to next node
	}

	//* If carry is greater than 0 then we create new nodes
	//* to store remaining digits.
	while (carry != 0) {
		prevPtr->prev = new Node((int)(carry % 10));
		carry /= 10;
		prevPtr = prevPtr->prev;
	}
}

//* Using head recursion to print the linked list's data in reverse
void print(Node* head)
{
	if (head == NULL) 
		return;
	print(head->prev);
	cout << head->data; // Print linked list in reverse order
}

// Driver code
int main()
{
	int n = 100;
	Node *head = new Node(1); // Create a node and initialise it by 1
	
	for(int i = 2; i <= n; i++)
		Multiply(head, i); // Run a loop from 2 to n and
							// multiply with head's i
	cout << "Factorial of " << n << " is : \n";
	print(head); // Print the linked list
	cout << endl;
	return 0;
}
