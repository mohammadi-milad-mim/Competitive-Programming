[**leetCode Problem 8**](https://leetcode.com/problems/string-to-integer-atoi)      
[**_link to the video explanation of this solution that I have created_**](https://drive.google.com/file/d/1Jw6MRbgmaLLpqJLU18H5EVIQFOx2xO6u/view?usp=sharing)    
[**_link to the Google Slide explanation of this solution that I have created_**](https://docs.google.com/presentation/d/1kyYtErGdT3iP6cXjT-lLyfoH1Z_vNaKGTrWCeva_qKs/edit?usp=sharing)
# 8. String to Integer (atoi)

## Problem

Implement _atoi_ which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

**Note**
* Only the space character ' ' is considered as whitespace character.
* Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. If the numerical value is out of the range of representable values, INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.

**Example 1:**  
>**Input**: "42"  
**Output**: 42
  
**Example 2:**  
>**Input**: "   -42"  
**Output**: -42  
**Explanation**: The first non-whitespace character is '-', which is the minus sign. Then take as many numerical digits as possible, which gets 42.

**Example 3:**  
>**Input**: "4193 with words"  
**Output**: 4193  
**Explanation**: Conversion stops at digit '3' as the next character is not a numerical digit.

**Example 4:**  
>**Input**: "words and 987" 
**Output**: 0  
**Explanation**: The first non-whitespace character is 'w', which is not a numerical digit or a +/- sign. Therefore no valid conversion could be performed.


**Example 5:**  
>**Input**: "-91283472332"  
**Output**: -2147483648  
**Explanation**: The number "-91283472332" is out of the range of a 32-bit signed integer. Thefore INT_MIN (−231) is returned.

## Solution:
**Please check the video solution that I have mentioned at the top.**
### Approch One:

We will start iterating through the str from the beginning. We will skip whit spaces until reaching the first digit or sign. Then if the first non-whitespace character were a sign, we would store it.  
Start adding digits to str2 until reaching a non-digit character; we will ignore the rest.    
Then we have to cast str2 to an integer. We will check the number range and then return the proper number.    
While we are doing these steps, we have to check that the number is not empty, and a non-digit character has not appeared before digits. If it happened, we should return 0.


#### Implementation:
[link here](https://github.com/MilladMuhammadi/leetCode/blob/master/8/beginner.py)

#### Complexity Analysis:
* We will just iterate through the str. So its order is _O(n)_, where _n_ is the number of characters of str.
* Its space complexity will be _O(1)_ because we are not using any additional memory.


### Approch Two:
_I found it on other submissions code._

We can use _strip()_ function to delete whitespaces from the beginning and end of the str. This way, we do not need to start iterating from the start and skipping whitespaces. The rest is the same as the previous one.


#### Implementation:
[link here](https://github.com/MilladMuhammadi/leetCode/blob/master/0%20begginer.py)

#### Complexity Analysis:
* We have just improved the implementation, and it will still be the same, _O(n)_.
* Same as the previous.


### Approch Three:
_I found it on disscution froum._

Do you want to solve this problem with a few simple lines of code? You can use _regex_ to solve this problem. But how? I leave you with the code!

#### Implementation:
[link here](https://github.com/MilladMuhammadi/leetCode/blob/master/8/Advance.py)
