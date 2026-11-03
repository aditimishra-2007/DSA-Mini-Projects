# Campus Route Finder Using Graphs

## Project overview
This C++ mini project represents campus locations as vertices and paths as undirected edges. It uses an adjacency list, Breadth-First Search (BFS), and Depth-First Search (DFS).

## Requirements covered
- 9 campus locations (more than the required 8)
- Adjacency-list graph representation
- BFS shortest route for an unweighted graph
- DFS traversal of reachable locations
- User-selected source and destination
- Disconnected-location detection
- Three example test cases
- Time and space complexity explanation

## Locations
Main Gate, Library, Block 1, Block 2, Cafeteria, Auditorium, Parking, Lab, Hostel.

Hostel is intentionally isolated to demonstrate an unreachable destination.

## How to compile and run
Using g++:

```bash
g++ main.cpp -o campus_route
./campus_route
```

On Windows, run:

```bash
g++ main.cpp -o campus_route.exe
campus_route.exe
```

## How to use
1. Run the program.
2. Choose option 1 to see the exact location names.
3. Choose option 3 to find a shortest route using BFS.
4. Choose option 4 to see reachable locations using DFS.
5. Choose option 5 to identify locations not reachable from a selected start.
6. Choose option 0 to exit.

Enter location names exactly as displayed, including spaces and capital letters.

## Sample test cases

### Test 1: Direct route
- Menu choice: 3
- Source: Main Gate
- Destination: Library
- Expected: `Main Gate -> Library`
- Expected number of edges: `1`

### Test 2: Multi-stop route
- Menu choice: 3
- Source: Main Gate
- Destination: Auditorium
- Expected: A shortest route with 3 edges, such as `Main Gate -> Library -> Cafeteria -> Auditorium`.
- Note: BFS finds a route with the minimum number of edges. If multiple shortest routes exist, the exact route can depend on adjacency order.

### Test 3: Unreachable destination
- Menu choice: 3
- Source: Main Gate
- Destination: Hostel
- Expected: `No route exists between Main Gate and Hostel.`

## Algorithms and complexity

Let V be the number of vertices (locations) and E be the number of edges (paths).

| Operation | Time complexity | Extra space |
|---|---:|---:|
| BFS using adjacency list | O(V + E) | O(V) |
| DFS using adjacency list | O(V + E) | O(V) |
| Adjacency-list storage | — | O(V + E) |

BFS uses a queue and visits vertices level by level. In an unweighted graph, the first route found to a destination uses the minimum number of edges. The parent array is used to reconstruct that route.

DFS uses a stack and explores one path as far as possible before backtracking.

## Adjacency list vs adjacency matrix

| Feature | Adjacency list | Adjacency matrix |
|---|---|---|
| Space | O(V + E) | O(V²) |
| Check whether an edge exists | O(degree of vertex) | O(1) |
| Iterate over neighbors | Efficient | O(V) per vertex |
| Best suited for | Sparse graphs | Dense graphs |

## Files
- `main.cpp` — complete source code
- `README.md` — project explanation, instructions, test cases, and complexity

## GitHub upload
Create a new public repository named `Campus-Route-Finder-Graphs`, then upload `main.cpp` and `README.md`.
