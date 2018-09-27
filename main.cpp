/* 
 **************************************************
 *    Sourav Sanyal 
 *    A02262314
 *    Bridge Lab
 *    Utah State University
 *    MS in Electrical and Computer Engineering
 * ***************************************************
 */

#include <fstream>
#include <iostream>
#include<string>
#include <string>
#include <cstdlib>

#include "DNA_Align.h"

using namespace std; 

int main(int argc, char **argv) 
{

fstream compare_one, compare_two;

compare_one.open(argv[1]);
compare_two.open(argv[2]);
	

	
	if (!compare_one || !compare_two)
	{
		cerr << "Error (2): Necessary files not found! \n";
		exit(2);
	}
	
	string dna_A = "", dna_B = "", line;

	        getline(compare_one,dna_A); 

                getline(compare_two,dna_B);


	DNA_Align *dna_match = new DNA_Align(dna_A, dna_B);
	dna_match->populate_subs_matrix("score_scheme.txt");
	dna_match->calculate_similarity();
	dna_match->dna_align();
	dna_match->print_results();
	return 0;
}
