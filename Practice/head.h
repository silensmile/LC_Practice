#pragma once
#include<vector>
#include<string>
#include<iostream>

struct ListNode;

int Huakuai();
int Bingjiling();
int DFS_test1();
int DFS_test2();
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
void listnodetest();

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2);
void findMedianSortedArraysTest();

int mySqrt(int x);
void mySqrtTest();

int arrangeCoins(int n);
void arrangeCoinsTest();

int singleNonDuplicate(std::vector<int>& nums);
void singleNonDuplicateTest();

std::vector<int> twoSum(std::vector<int>& numbers, int target);
void twoSumTest();

std::string reverseVowels(std::string s);
void reverseVowelsTest();

bool judgeSquareSum(int c);
void judgeSquareSumTest();

bool validPalindrome(std::string s);
void validPalindromeTest();

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
void mergeTest();

bool hasCycle(ListNode *head);
void hasCycleTest();

std::string findLongestWord(std::string s, std::vector<std::string>& d);
void findLongestWord();

std::vector<int> topKFrequent(std::vector<int>& nums, int k);
void topKFrequentTest();

class MyQueue;
void MyQueueTest();

bool isValid(std::string s);
void isValidTest();

std::vector<int> dailyTemperatures(std::vector<int>& T);
void dailyTemperaturesTest();

std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2);
void nextGreaterElementsTest();

int findLHS(std::vector<int>& nums);
void findLHSTest();

bool isIsomorphic(std::string s, std::string t);
void isIsomorphicTest();

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
void mergeTwoListsTest();

bool isPalindrome(ListNode* head);
void isPalindromeTest();

std::pair<int, int> Pigeon(int n);