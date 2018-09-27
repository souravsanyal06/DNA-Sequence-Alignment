/* 
 *************************************************
 *   Sourav Sanyal 
 *   A02262314
 *   Bridge Lab
 *   Utah State University
 *   MS in Electrical and Computer Engineering
 ****************************************************
 */

#include <iostream>
#include <string>
#include<map>
#include<cstring>

using namespace std;

enum Sequence
{
	A, C,G,T, MIN
};

class DNA_Align
{
private:

	string dna_A;
	string dna_B;

	string align_A;
	string align_B;
	string sign ; 
	
	size_t len_A,len_B;

	int substituition_matrix[24][24];
	int similarity ; 
	int gap ;
	int identity ;
	int **similarity_matrix;
	map<char, int> dna_int_map;
	

public:
	
	DNA_Align(string A,string B);
	~DNA_Align();
	
	void calculate_similarity();
	void populate_subs_matrix(std::string subs_matrix_file);
	void dna_align();
	void print_results();
};
	
