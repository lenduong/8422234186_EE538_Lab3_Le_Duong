# Lab3

Le Duong
Student ID: 8422234186
email: lnduong@usc.edu

I used ChatGPT to generate pseudo code for me to implement on each question. For Q1-3, I gave chatGPT the instruction of the lab and asks it give me the pseudo code, so the prompts are all the same (just me telling it to give the pseudo code after I give it the assignment descriptions and questions). 

Q2 Response:

```
Q2 Pseudocode
1. Define abstract class Person with private name and age data.
2. Give Person const getters, a pure virtual displayInfo function, a virtual
   introduce function, and a virtual destructor.
3. Publicly derive Student and Teacher from Person.
4. Initialize the Person part and each derived class's data in constructor
   initialization lists.
5. Override displayInfo in each derived class using the exact required format.

Q3 Pseudocode
1. Read n, then repeat n times: read a role and its fields.
2. Construct the matching Student or Teacher and store its address as Person*.
3. Traverse the Person pointers in input order.
4. For each pointer, call displayInfo and then introduce so virtual dispatch
   selects the appropriate derived implementations.
5. Delete each object through its Person pointer; the virtual destructor makes
   destruction safe.

```