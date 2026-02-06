# Graph Coloring Problem

**Student:** Amirali HajiShamsaie
<br>
**Professor:** Dr. Mina Masoudifar
<br>
**Course:** Algorithms design

---

## 📝 Problem Statement

The objective is to assign colors to the vertices of a graph such that no two adjacent vertices share the same color. The algorithm calculates the minimum number of colors required to achieve this.



## Input

*   **Adjacency Matrix:**  a matrix representing the graph structure.


## Output

###  Console Output
*   Minimum number of colors (Chromatic Number).
*   Color assignment for each vertex.


*   (TODO) : Graphical Output Not implemented yet


## ⚙️ Algorithm

The solution is implemented using a **Backtracking algorithm**.

The program starts checking with `m=1` (1 color) and increments `m` until a valid coloring is found for all vertices. This ensures the minimum number of colors is determined.
