# <div align=center>Omer and Ofir Advanced programming project</div>

# <div align=center>Advanced-Programming-1-Project</div>
<div align=center>
  <img src="https://i.imgur.com/UWgstMt.png" width="200" align ="center"/><img src="https://cdn.dribbble.com/users/1292677/screenshots/6139167/media/5387dc7e035b3efe9d94516044de66a4.gif" width="400px" align="center"/><img src="https://i.imgur.com/UWgstMt.png" width="200" align ="center"/>
</div>
ㅤ
<div align=center>🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁🏁</div>
ㅤ

  So far, we have uploaded the first assignment for the project.
The assignment was to make a software that calculates distances between 2 vectors of the *same size* with 5 different algorithms:

 1. **Canberra**
 2. **Minkowski**
 3. **Euclidean**
 4. **Chebyshev**
 5. **Manhattan**


This is a rundown about everything we have and did in the first assignment:

# 📁 Files


<img src="https://i.imgur.com/aHewclO.png" width="300"/>


> This is a screenshot of the files we have created in the assignment.

# ⚡ Algorithms
**Euclidean**

<img src="https://i.imgur.com/EXQEowM.png" width="600"/>

> The distance between any two points on the real line is the absolute value of the numerical difference of their coordinates, their absolute difference. Thus if p and q are two points on the real line, then the distance between them is given by this formula, and the same for *n* number of points.

**Manhattan**

<img src="https://i.imgur.com/LzyrKnq.png" width="300"/>

>The taxicab distance, *d1*, between two vectors **p** , **q** in an *n*-dimensional real vector space with fixed Cartesian coordinate system, is the sum of the lengths of the projections of the line segment between the points onto the coordinate axes.

**Chebyshev**

<img src="https://i.imgur.com/ukNkEdp.png" width="230"/>

>Mathematically, the Chebyshev distance is a metric induced by the supremum norm or uniform norm. It is an example of an injective metric. In two dimensions, i.e. plane geometry, if the points **p** and **q** have Cartesian coordinates (*x<sub>1</sub>*,*y<sub>1</sub>*) and (*x<sub>2</sub>*,*y<sub>2</sub>*), their Chebyshev distance is the maximum distance between the *x*'s and the *y*'s of the two vectors.

**Canberra**

<img src="https://i.imgur.com/oFLYRNo.png" width="230"/>

>The Canberra distance *d* between vectors **p** and **q** in an *n*-dimensional real vector space is given by summing up the absolute values of *p<sub>i</sub>*-*q<sub>i</sub>*, and dividing it by *p<sub>i</sub>*+*q<sub>i</sub>*.

**Minkowski**

<img src="https://i.imgur.com/dqTIJb9.png" width="230"/>

>For **p≥1**, the Minkowski distance is a metric as a result of the Minkowski inequality. When **p<1**, the distance between **(0,0)** and **(1,1)** is **2<sup>1/p</sup>>2** but the point **(0,1)** is at a distance **1** from both of these points. Since this violates the triangle inequality, for **p>1** it is not a metric. However, a metric can be obtained for these values by simply removing the exponent of **1/p**.

## 💻 How to run the program

**Linux:**

Paste this command to the terminal:

    g++ -std=c++11 -I[path for the directory of the project] distance/cpp/Canberra.cpp distance/h/Canberra.h distance/cpp/Chebyshev.cpp distance/h/Chebyshev.h distance/cpp/Euclidean.cpp distance/h/Euclidean.h distance/cpp/DistanceClass.cpp distance/h/DistanceClass.h distance/cpp/Main.cpp distance/h/Main.h distance/cpp/Manhattan.cpp distance/h/Manhattan.h distance/cpp/Minkowski.cpp distance/h/Minkowski.h

❤️ **insert your own path on the computer in the path place.** ❤️

an example for a path:

    /home/ofir/CLionProjects/Advanced-Programming-1-Project

and then:

    ./a.out


## ✍ Examples for input

The program is coded to accept many kind of incorrect input, and the rest of the input is being thrown out with an error message, but it is still possible to **re-input** the vectors after making a mistake.
Here are some examples for input:

|                |Input							 |Error message|
|----------------|-------------------------------|-----------------------------|
|Double (or more) spaces   |`5ㅤ 5`               |**no error**, the vector is: 5 5|
|Spaces at the end or beggining|`5 5ㅤ`            |**no error**, the vector is: 5 5            |
|Chars          |`5g y6.7`|**error message:** The input was not a number.|
|Double dots| `5.5.5 6`|**error message:** The input was not a number.|
|Different size vectors|`First vector: 5 5`ㅤㅤㅤ `Second vector: 6 6 6`| **error message:** The vectors aren't the same size

## 📊 UML diagrams


**Dictionary:** 

```mermaid
flowchart
id5{Package}
CPP[CPP file]
Header(Header file)
style id5 fill:#bbf,stroke:#f66,stroke-width:2px,color:#fff,stroke-dasharray: 5 5
```
This is a UML diagram of the current Classes and Packages:
```mermaid
flowchart LR;
id1{distance}-->id2(cpp)
id1{distance}-->id3(h)
id2{cpp}-->canberra.cpp
id2{cpp}-->minkowski.cpp
id2{cpp}-->euclidean.cpp
id2{cpp}-->manhattan.cpp
id2{cpp}-->chebyshev.cpp
id2{cpp}-->distanceClass.cpp
distanceClass.cpp-->canberra.cpp
distanceClass.cpp-->minkowski.cpp
distanceClass.cpp-->euclidean.cpp
distanceClass.cpp-->manhattan.cpp
distanceClass.cpp-->chebyshev.cpp
id2{cpp}-->main.cpp
id3{h}-->canberra.h(canberra.h)
id3{h}-->minkowski.h(minkowski.h)
id3{h}-->euclidean.h(euclidean.h)
id3{h}-->manhattan.h(manhattan.h)
id3{h}-->chebyshev.h(chebyshev.h)
id3{h}-->distanceClass.h(distanceClass.h)
id3{h}-->main.h(main.h)
style id1 fill:#bbf,stroke:#f66,stroke-width:2px,color:#fff,stroke-dasharray: 5 5
style id2 fill:#bbf,stroke:#f66,stroke-width:2px,color:#fff,stroke-dasharray: 5 5
style id3 fill:#bbf,stroke:#f66,stroke-width:2px,color:#fff,stroke-dasharray: 5 5

```

