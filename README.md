## LockAndKey_NutAndBolt_AlgoAnalysis
**Nuts and Bolts Problem:** Given a set of n nuts of different sizes and n bolts such that there is a one-to-one correspondence between the nuts and the bolts, find for each nut its corresponding bolt. Assume that we can only compare nuts to bolts: we cannotcompare nuts to nuts and bolts to bolts.<br/>
The same thing can be the set of Lock and Key apir as that of Nut and Bolt.<br/>
**Alternative way of framing the question:** We are given a box which contains bolts and
nuts. Assume there are n nuts and n bolts and that each nut matches exactly one bolt (and
vice versa). By trying to match a bolt and a nut we can see which one is bigger, but we
cannot compare two bolts or two nuts directly. Design an efficient algorithm for matching
the nuts and bolts.<br/>
**Solution1_Brute_Force_Approach**: Start with the first bolt and compare it with each nut until we find a match. In the worst case, we require n comparisons. Repeat this for successive bolts on all remaining gives **O(n^2) complexity**.<br/>
**Solution2_DivideAndConquer**: This solution is very similar to randomized Quick Sort. For simplicity let us assume that bolts and nuts are represented in two arrays B and N.
The algorithm first performs a partition operation as follows: pick a random boltB[t]. Using this bolt, rearrange the array of nuts into three groups of elements:<br/>
1. First the nuts smaller than B[i]
2. Then the nut that matches B[i], and
3. Finally, the nuts larger than B[i].
<br/>
Next, using the nut that matches B[i], perform a similar partition on the array of bolts. This pair of partitioning operations can easily be implemented in O(n) time, and it leaves the bolts and nuts nicely partitioned so that the “pivot” bolt and nut are aligned with each other and all other bolts and nuts are on the correct side of these pivots – smaller nuts and bolts precede the pivots, and larger nuts and bolts follow the pivots. Our algorithm then completes by recursively applying itself to the subarray to the left and right of the pivot position to match these remaining bolts and nuts. We can assume by induction on n that these recursive calls will properly match the remaining bolts.<br/>
To analyze the running time of our algorithm, we can use the same analysis as that of randomized Quick Sort. Therefore, applying the analysis from Quick Sort, the time complexity of our algorithm is **O(nlogn)**.<br/>
