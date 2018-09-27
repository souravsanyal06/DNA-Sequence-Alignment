# DNA-Sequence-Alignment
Aligning Mitochondrial genome DNA sequences of Humans and Apes:

The instructions for creating and running a living organism is encoded in DNA sequences. Most multicellular organisms are made of eukaryotic cells that contain mitochondria, an organelle that manages cellular metabolism. Interestingly, mitochondria contain their own unique DNA sequence which is passed down through the mother. In this assignment, you are to implement a simple DNA alignment algorithm and apply it to analyze a set of mitochondrial DNA. 

Implement the basic version of the DNA alignment algorithm that uses O(n^2) space described in https://en.wikipedia.org/wiki/Needleman%E2%80%93Wunsch_algorithm (Links to an external site.)Links to an external site.. Use the following scoring scheme to measure similarity: 

Given in score_scheme.txt
 
Write the traceback routine and the code to print out the alignment vertically.  Test the algorithm on some very simple sequences to confirm the results.

Approximate the size of the solution matrix where the O(n^2) algorithm becomes impractical.

Next review the mitochondrial DNA sequences from the following sources:

Prototypical human: http://www.ncbi.nlm.nih.gov/nuccore/251831106 (Links to an external site.)Links to an external site.

Neandertal: http://www.ncbi.nlm.nih.gov/nuccore/196123578 (Links to an external site.)Links to an external site. 

Human diversity: http://www.mtdb.igp.uu.se/ (Links to an external site.)Links to an external site. (click on the "Download mtDNA sequences" link to get to the data page)

Great Apes: http://www.mtdb.igp.uu.se/ (Links to an external site.)Links to an external site. (at the bottom of the page)

In all these files, the DNA sequence is given at the bottom of the file following the keyword "ORIGIN". The text must be read in and cleaned up by removing the gaps, new lines and line numbers.

In this assignment, you will apply your algorithms to measure the alignment distance between DNA sequences from these data sets.

First study the relationship between Human and Neandertal sequences (see http://genome.ucsc.edu/Neandertal/ (Links to an external site.)Links to an external site. for some background). Download the sequence from http://www.ncbi.nlm.nih.gov/nuccore/196123578 (Links to an external site.)Links to an external site. and http://www.ncbi.nlm.nih.gov/nuccore/251831106 (Links to an external site.)Links to an external site., compute the distance between the two sequences and generate their alignment (as a text file).

Next study the relationship between the diversity of human mitochondrial sequences available from http://www.mtdb.igp.uu.se/ (Links to an external site.)Links to an external site.. Pick 10 sequences and run the alignment algorithm to compute all pairwise distances between the sequences. Produce a table of your results.

Finally, apply your algorithm to study the distance between a prototypical human sequence (http://www.ncbi.nlm.nih.gov/nuccore/251831106 (Links to an external site.)Links to an external site.) and samples taken from the great apes (http://www.mtdb.igp.uu.se/ (Links to an external site.)Links to an external site., bottom of page). Produce a table similar to the study of human diversity that includes all pairwise distances. Additionally, produce six text files each containing the alignments between the prototypical human and the 6 great ape sequences.

Write a brief summary discussing your observations on the algorithm performance and the scientific impact of this efficient alignment algorithm.

