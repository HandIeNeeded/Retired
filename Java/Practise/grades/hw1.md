hw1 grading rubric

hw1 Feedback
============

#### Successful use of Git, GitHub, and build automation tools (4/5)
  * Your commit history could be more made more useful. A useful commit history separates work into multiple commits, instead of one or two for the whole assignment. Each commit should have a concise, but descriptive name about what was changed. Committing your work incrementally protects you from data loss or network problems, which might otherwise cause you to lose work or fail to meet the homework deadlines (which are strictly enforced). For more information on writing useful commit messages, see https://git-scm.com/book/ch5-2.html#Commit-Guidelines or http://chris.beams.io/posts/git-commit/

#### Basic proficiency in Java (18/20)
   * -0.1 TreeMap is not necessary here. HashMap has better performance, so is preferred unless the ordering properties of TreeMap are explicitly needed.
   * Your package statement is incorrect Webcompare.java:7, should be edu.cmu.cs.cs214.hw1.webcom
   * Interfaces and classes should be organized into separate files. 
#### Fulfilling the technical requirements of the program specification (14/15)
   * ClosestMatches computes cosine similarity multiple times for the same pair of documents. There should not be more than n(n-1)/2 calls to the cosine similarity method.
#### Documentation and code style (10/10)
  * Avoid using confusing naming (i.e. abbreviations) and adhere to the CamlCase naming convention for your methods and variables.


---

#### Total (46/50)

Late days used: 0 (5 left)

---

#### Additional Notes

Graded by: Tianyu Li (tli2@andrew.cmu.edu)

To view this file with formatting, visit the following page: https://github.com/CMU-15-214/menglanw/blob/master/grades/hw1.md
