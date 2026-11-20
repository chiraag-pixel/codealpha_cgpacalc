# CGPACalculator

CGPA calculator in C++ 

You enter the number of semesters, then the courses for each one (name, grade, credits). It prints each semester's GPA and the overall CGPA at the end.

Grades use a 10 point scale:

|Grade|O|A+|A|B+|B|C|P|F|
|-|-|-|-|-|-|-|-|-|
|Points|10|9|8|7|6|5|4|0|

GPA = sum of (grade points x credits) / total credits
CGPA = same thing but over all semesters

## Run

```
g++ cgpa\_calculator.cpp -o cgpa
./cgpa
```



