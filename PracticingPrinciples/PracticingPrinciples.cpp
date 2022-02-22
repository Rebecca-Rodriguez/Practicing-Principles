#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <climits>
#include "ABS.h"
#include "ABQ.h"
using namespace std;

struct Person
{
    string name;
    Person() { name = "Joe"; }
    ~Person() {}
};

void AppendString(string stringToModify)
{
    stringToModify += " World!";
}

class myClass
{
private:
    int* ptr;
public:
    myClass() { ptr = new int(5); }
    // this is NOT the default constructor. since this was called, you need to create a default constructor for the program to work
    myClass(int value) { ptr = new int(value); }
};

// base class
struct Foo
{
    string name;
    Foo() {}
    virtual string print() { return name; }             // virtual keyword signals polymorphism
};

// derived class
struct Bar : public Foo
{
    Bar(string inputName) { name = inputName; }
    string print() { return name + " is awesome!"; }
};

// derived class
struct FooBar : public Foo
{
    FooBar(string inputName) { name = inputName; }
};

class Foo2
{
public:
    int classValue;
    const Foo2& SomeClassFunction()
    {
        this->classValue = 3;
        return *this;               // need to return a dereference to pointer "this" when usign a function reference
    }
};

void swappyBoi(int* swapA, int* swapB)
{
    /*  this is how you get the swap to work
    int temp = *swapA;
    *swapA = *swapB;
    *swapB = temp;
    */

    // all this is doing is swapping memory addresses
    swapA = swapB;
    swapB = swapA;
}

class Solution {
public:
    bool isPalindrome(string s) {
        string a;
        for (char c : s)
            if (isalnum(c))
                a += tolower(c);
        int end = a.length() - 1;
        for (int j = 0; j < a.length() / 2; j++)
        {
            if (a[j] != a[end]) return false;
            end--;
        }
        return true;
    }
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = { 0 };
        for (int i = 0; i < n; i++) {
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }    
    int firstUniqChar(string s) {
        vector<int> v(26, 0);
        for (char c : s)
        {
            v[c - 'a']++;
        }
        for (int i = 0; i < s.length(); i++)
        {
            if (v[s[i] - 'a'] == 1) return i;
        }
        return -1;
    }
    int reverse(int x) {
        int rev = 0;
        while (x)
        {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || rev == INT_MAX / 10 && pop > 7) return 0;
            if (rev < INT_MIN / 10 || rev == INT_MIN / 10 && pop < -8) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
    void reverseString(vector<char>& s) {
        for (int front = 0; front < s.size() / 2; front++) {
            swap(s[front], s[s.size() - front - 1]);
        }
    }
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // take row 0 and put in col n-1
        for (int r = 0; r < n / 2; r++) {
            for (int c = r; c < n - r - 1; c++) {
                swap(matrix[r][c], matrix[c][n - 1 - r]);
                swap(matrix[r][c], matrix[n - 1 - r][n - 1 - c]);
                swap(matrix[r][c], matrix[n - 1 - c][r]);
            }
        }
    }
    bool isValidSudoku(vector<vector<char> >& board) {
        int rows[9][9] = { 0 }, cols[9][9] = { 0 }, boxes[9][9] = { 0 };

        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[row].size(); ++col) {
                if (board[row][col] != '.') {
                    int num = board[row][col] - '0' - 1;
                    int k = row / 3 * 3 + col / 3;
                    if (rows[row][num] || cols[col][num] || boxes[k][num])
                        return false;
                    rows[row][num] = cols[col][num] = boxes[k][num] = 1;
                }
            }
        }
        return true;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int> s;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = 1; j < nums.size(); j++) {
                if (i != j) {
                    int sum = nums[i] + nums[j];
                    if (sum == target) {
                        s.insert(i);
                        s.insert(j);
                    }
                }
            }
        }
        vector<int> solution(s.begin(), s.end());
        return solution;
    }
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroFoundAt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
                nums[lastNonZeroFoundAt++] = nums[i];
        }
        for (int i = lastNonZeroFoundAt; i < nums.size(); i++)
            nums[i] = 0;
    }
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if (digits[i] == 9)
                digits[i] = 0;
            else {
                digits[i] += 1;
                return digits;
            }
        }
        digits.push_back(0);
        digits[0] = 1;
        return digits;
    }
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        nums1.erase(set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums1.begin()), nums1.end());
        return nums1;
    }
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for (int x : nums)
        {
            a ^= x;
        }
        return a;
    }
    bool containsDuplicate(vector<int>& nums) {
        unordered_set <int> set;
        for (int x : nums)
        {
            if (set.find(x) != set.end())
            {
                return true;
            }
            set.insert(x);
        }
        return false;
    }
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1])
                maxprofit += prices[i] - prices[i - 1];
        }
        return maxprofit;
    }
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

class Stepik {
public:
    
    
    bool inLanguage(char* theString)
    {
        // determine whether theString has the same number of A's as B's (STACK)
        std::stack<char> s;
        for (char* it = theString; *it; it++) {
            if (*it != 'A' && *it != 'B') return false;
            if (s.empty()) s.push(*it);
            else if (*it != s.top()) s.pop();
            else if (*it == s.top()) s.push(*it);
        }
        if (!s.empty()) return false;
        return true;
    }
    bool checkValidity(queue<int> q)
    {
        // A Valid queue is one in which the numbers are inserted in ascending order
        int prev = INT_MIN;
        while (!q.empty()) {
            if (prev > q.front()) return false;
            prev = q.front();
            q.pop();
        }
        return true;
    }
    int TripleNum(int* num)
    {
        return *num * 3;
    }
    int* TripleNum(int num) const
    {
        int* ptr = new int;
        *ptr = num * 3;
        return ptr;
        delete ptr;
    }
    int* TimesThree(int& num)
    {
        int* ptr = &num;
        *ptr *= 3;
        return ptr;
    }
    long factorial(long num)
    {
        if (num == 1 || num == 0) return 1;
        return (num * factorial(num - 1));
    }
    bool checkPalindrome(string s)
    {
        if (s.length() <= 1) return true;
        if (s[0] != s[s.length() - 1]) return false;
        return checkPalindrome(s.substr(1, s.length() - 2));
    }
};

/*------------------------------------------------------- Linked Lists -------------------------------------------------------*/
class Node {
public:
    int value;
    Node* next = NULL;
};

Node* add(Node* head, int index, int valueInput)
{
    Node* newNode = new Node();
    newNode->value = valueInput;

    if (index == 0) {
        newNode->next = head;
        return newNode;
    }
    Node* curr = head;
    for (int i = 0; i < index - 1; i++) {
        if (curr != nullptr) curr = curr->next;
        else return nullptr;
    }

    if (curr != nullptr) {
        newNode->next = curr->next;
        curr->next = newNode;
        return head;
    }
    return nullptr;
}

float median(Node* head)
{
    Node* slow = head;
    Node* fast = head;
    while (fast->next != nullptr && fast->next->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    if (fast->next != nullptr)
        return (slow->value + slow->next->value) / 2.0;
    else
        return slow->value;
}

float interQuartile(Node* head)
{
    Node* q1 = head;
    Node* q2 = head; //median
    Node* q3 = head;

    Node* curr = head;

    int count = 0;
    float currData, q1Data, q2Data, q3Data;

    while (curr != nullptr)
    {
        q1Data = q1->value;
        q2Data = q2->value;
        q3Data = q3->value;
        count++;
        curr = curr->next;

        if (count % 2 == 0)
        {
            q2 = q2->next;
        }
        if (count % 3 == 0)
        {
            if (count % 2 == 0 && curr != nullptr)
                q3 = q3->next->next->next;
            else if (curr == nullptr)
                q3 = q2->next->next;
            else
                q3 = q3->next->next;
        }
        if (count % 4 == 0 && curr != nullptr)
        {
            q1 = q1->next;
        }

    }
    if (count > 4 && count <= 9) q1 = head->next;
    if (count == 11) q3 = q3->next;

    float result, avg1, avg3;
    int secCount = count / 2;
    if (secCount % 2 == 0) {
        avg1 = ((q1->value + q1->next->value) / 2.0);
        avg3 = ((q3->value + q3->next->value) / 2.0);
    }
    else
    {
        avg1 = q1->value;
        avg3 = q3->value;
    }

    return avg3 - avg1;
}

//------------------------------------- Binary Search Trees -------------------------------------//
class TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertNode(TreeNode* root, int key)
{
    if (root == nullptr)
        return new TreeNode(key);
    if (key < root->val)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);
    return root;
}

void inorder(TreeNode* head)
{
    if (head == nullptr)
        cout << "";
    else
    {  
        inorder(head->left);
        cout << head->val << " ";
        inorder(head->right);
    }
}

bool validateBST(TreeNode* root, int min, int max)
{
    if (root == nullptr)
        return true;
    if (root->val <= min || root->val >= max)
        return false;
    return validateBST(root->left, min, root->val) && validateBST(root->right, root->val, max);
}

string traverse(TreeNode* root)
{
    if (root == nullptr)
        return "";
    string leftSubTree = traverse(root->left);
    string rootValue = to_string(root->val);
    string rightSubTree = traverse(root->right);
    return leftSubTree + rootValue + rightSubTree;
}

void Flip(TreeNode* root) {
    if (root == nullptr) return;
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    Flip(root->left);
    Flip(root->right);
}

void sumOfRightLeaves(TreeNode* root)
{
    queue<TreeNode*> q;
    int sum = 0;
    if (root != nullptr)
        q.push(root);
    while (!q.empty())
    {
        if (q.front()->right != nullptr && q.front()->right->right == nullptr && q.front()->right->left == nullptr)
            sum += q.front()->right->val;
        if (q.front()->left != nullptr)
            q.push(q.front()->left);
        if (q.front()->right != nullptr)
            q.push(q.front()->right);

        q.pop();
    }
    cout << sum;
}

/*------------------------------------------------------- Main -------------------------------------------------------*/
int main()
{
    //------------------------------------- Question 1: Uses the People struct -------------------------------------//
    {
        vector<Person*> people;
        for (int i = 0; i < 5; i++)
        {
            Person* newPerson = new Person();
            people.push_back(newPerson);
        }
        // Hw do you access the final person's name using the vector?
        cout << people[4]->name << endl;
    }
    //------------------------------------- Question 3: Uses AppendString -------------------------------------//
    {
        string hello = "Hello";
        AppendString(hello);            // this will not do anything because not being assigned to anything
        cout << hello << endl;          // also the function has a void return type
    }
    //------------------------------------- Question 4: Uses myClass -------------------------------------//
    {
        // example of constructors and the big three
        myClass obj;                        // calls the default constructor; originally missing and had to add
        myClass obj1 = myClass(1);          // calls the constructor with a parameter
        myClass cpy = obj;                  // calls the copy constructor; the copy constructor was not defined
        cpy = obj1;                         // calls the assignment operator; not defined
    }
    //------------------------------------- Question 5: What is causign error -------------------------------------//
    {
        int* num = new int(1);
        while (*num < 123)          // this needs to be *num instead of num to work; needs to be dereferenced
        {
            num = new int(*num + 1);
            (*num)++;
        }
        cout << *num << endl;
    }
    //------------------------------------- Question 6: ABS and ABQ -------------------------------------//
    {
        ABS<int> intStack;
        ABQ<int> intQueue;

        for (int i = 0; i < 5; ++i)
            intStack.push(i);

        for (int j = 0; j < intStack.getSize(); ++j)
            intQueue.enqueue(intStack.pop());

        for (int k = 0; k < intQueue.getSize(); ++k)
            cout << intQueue.dequeue();
    }
    //------------------------------------- Question 7: Example of Maps -------------------------------------//
    {
        map<int, string> groceries;
        groceries.emplace(5, "Yellow");
        groceries.emplace(5, "Oranges");
        groceries.emplace(2, "Bananas");
        groceries.emplace(1, "Juice");
        groceries.emplace(7, "Apples");
        groceries.emplace(2, "Steak");
        groceries.emplace(3, "Bananas");
        // will print in order of key, then in the order from top down
        for (int i = 0; i < groceries.size(); i++)
            cout << i << ": " << groceries[i] << endl;
    }
    //------------------------------------- Question 8: Inheritance & Polymorphism -------------------------------------//
    {
        Foo* bar = new Bar("Bar");
        Foo* fooBar = new FooBar("FooBar");
        cout << bar->print() << endl;
        cout << fooBar->print() << endl;
    }
    //------------------------------------- Question 9: Pointers & References -------------------------------------//
    {
        int a = 5, b = 9;
        int* x = &b;                // pointer to the memory address of b
        int& y = a;                 // reference to a
        *x++;                       // increment the pointer?
        y++;                        // increment the actual value b/c it is a reference
        cout << x << endl;          // prints out the address of b
        cout << y << endl;          // prints out the new value of y = 6
    }
    //------------------------------------- Question 11: Functional References -------------------------------------//
    {
        Foo2 foo2;
        // since we pass foo2 by reference, we can use the direct membership operator (the period)
        cout << foo2.SomeClassFunction().classValue << endl;
        // foo2.SomeClassFunction().classValue = 5;     // this does not work b/c the function cannot be modified (const)
        foo2.classValue = 5;
        cout << foo2.classValue << endl;
    }
    //------------------------------------- Question 12: Bitwise Operations -------------------------------------//
    {
        int val = 13;
        cout << ((val >> 2) << 3) << (sizeof(val) & 9) << endl;
    }
    //------------------------------------- Question 15: Nested For Loops -------------------------------------//
    {
        int N = 10;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N * 2; j++)
            {
                cout << j << " ";
                break;          // does not go through all 20 b/c of the break statement. Completes first line and then goes back to first loop
            }
        }
        cout << endl;
    }
    //------------------------------------- Question 16: Pointers & Arrays -------------------------------------//
    {
        int array[10] = { 0 };              // initialize each value in array to 0
        int* arrayPointer = array;          // arrayPointer will point to start of array (array[0])
        for (int i = 0; i < 10; i++)
        {
            *arrayPointer = i;              // this dereferences the pointer and assigns i to the array element
            (*arrayPointer)++;              // if this was not dereferenced, it would move to the next pointer
        }
        // b/c the loop increments the value inside the pointer, the pointer never moves past first index
        cout << "Q16: " <<  array[0] << " " << array[9] << endl;
    }
    //------------------------------------- Question 17: Swap by Pointers -------------------------------------//
    {
        int a = 10;
        int b = 20;
        swappyBoi(&a, &b);                  // pass in the memory address to the function that takes in pointers
        cout << a << " " << b << endl;      // returns the original values b/c function only swapped memory addresses
    }
    //------------------------------------- Question 18: Example of Maps -------------------------------------//
    {
        map<string, int> population;
        population.emplace("Orlando", 10);
        population.emplace("San Francisco", 1333);
        population.emplace("Anchorage", 1);
        population.emplace("New York City", 8000);
        population.emplace("New York City", 10);
        population.emplace("San Francisco", 50);
        for (auto iter = population.begin(); iter != population.end(); iter++)
        {
            // remember maps groups things together based on the key
            // this will print the keys alphabetically, but only the first instance of the key will print
            cout << iter->first << " " << iter->second << ";";
        }
        cout << endl;
    }
    //------------------------------------- Binary Search Trees -------------------------------------//
    TreeNode* binaryRoot = nullptr;
    binaryRoot = insertNode(binaryRoot, 50);
    binaryRoot = insertNode(binaryRoot, 20);
    binaryRoot = insertNode(binaryRoot, 14);
    binaryRoot = insertNode(binaryRoot, 22);
    return 0;
}