/* 
**************************************************
*   Sourav Sanyal 
*   A02262314
*   Bridge Lab
*   Utah State University
*   MS in Electrical and Computer Engineering
***************************************************
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <map>
#include <iomanip>

#include "DNA_Align.h"

DNA_Align::DNA_Align(string A, string B)
{
	this->dna_A = A;
	this->dna_B = B;

	this->len_A = A.length();
	this->len_B = B.length();

	this->similarity = 0;

	this->similarity_matrix = new int*[this->len_A + 2];
	for (int i = 0; i < (this->len_A + 1); i++)
	{
		this->similarity_matrix[i] = new int[this->len_B + 2];
	}

	for (int i = 0; i < len_A; i++)
	{
		for (int j = 0; j < len_A; j++)
		{
			similarity_matrix[i][j] = 0;
		}
	}
		
}	



DNA_Align::~DNA_Align()
{
	for (int i = 0; i < (len_A + 2); i++)
	{
		delete[] this->similarity_matrix[i];
	}
	delete[] this->similarity_matrix;
}


void DNA_Align::populate_subs_matrix(std::string subs_matrix_file)
{
	fstream subs_matrix;
	subs_matrix.open(subs_matrix_file.c_str());
	if (!subs_matrix)
	{
		std::cerr << "Error (3): Substition matrix file not found! \n";
		exit(3);
	}
	string line, parsed;
	int i = 0;
	while (getline(subs_matrix, line) )
	{
		
		
			istringstream iss(line);

			int j = 0;

			while (getline(iss, parsed, ' '))
			{
				if (parsed != "") 
				{
					if (i == 0) 
					{
						dna_int_map.insert(pair<char, int>(parsed[0], j));
					}
					if (j > 0 && i > 0)
					{
						substituition_matrix[i - 1][j - 1] = atoi(parsed.c_str());
					}
					j++;
				}
			}
			i++;
		
	}
}
		


void DNA_Align::calculate_similarity()
{
	enum Sequence basecase = MIN;

	int gap_penalty = substituition_matrix[0][basecase];

	for (int i = 0; i < (len_A + 1); i++)
	{
		similarity_matrix[i][0] = i * gap_penalty;
	}

	for (int j = 0; j < (len_B + 1); j++)
	{
		similarity_matrix[0][j] = j * gap_penalty;
	}

	int match = 0, insert = 0, del = 0 , max = 0, selected = 0;

	for (int i = 1; i < len_A + 1; i++)
	{
		for (int j = 1; j < len_B + 1; j++)
		{
			match = similarity_matrix[i - 1][j - 1] + substituition_matrix[dna_int_map[dna_A[i - 1] ] ][dna_int_map[dna_B[j - 1] ] ];

			del = similarity_matrix[i - 1][j] + gap_penalty;

			insert = similarity_matrix[i][j - 1] + gap_penalty;


			max = (match < del) ? del : match;

			selected = ((max < insert) ? insert : max);

			similarity_matrix[i][j] = selected;
		}
	}
}

void DNA_Align:: dna_align()

{
	enum Sequence basecase = MIN;
	int gap_penalty = substituition_matrix[0][basecase];
	align_A = "";
	align_B = "";
	sign = "";

	size_t i = len_A;
	size_t j = len_B;

	while (i > 0 || j > 0)

	{

		if (i > 0 && j > 0 && (similarity_matrix[i][j] == similarity_matrix[i - 1][j - 1] +substituition_matrix[dna_int_map[dna_A[i - 1]]][dna_int_map[dna_B[j - 1]]]) )
		{
			align_A = dna_A[i - 1] + align_A;
			align_B = dna_B[j - 1] + align_B;

			if (substituition_matrix[dna_int_map[dna_A[i - 1]]][dna_int_map[dna_B[j - 1]]] > 0)
			{
				if (dna_A[i - 1] != dna_B[j - 1])
				{
					sign = ":" + sign;
				}
				else
				{
					sign = "|" + sign;
					identity += 1;
				}
				similarity += 1;
			}
			else
			{
				sign = "." + sign;
			}

			i -= 1;
			j -= 1;
		}

			else if (i > 0 && similarity_matrix[i][j] == (similarity_matrix[i - 1][j] + gap_penalty))
		{
			align_A = dna_A[i - 1] + align_A;
			align_B = '-' + align_B;
			sign = " " + sign;
			gap += 1;

			i -= 1;
		}

			else
		{
			align_A = '-' + align_A;
			align_B = dna_B[j - 1] + align_B;
			sign = " " + sign;
			gap += 1;

			j -= 1;
		}
	}
}	


void DNA_Align::print_results()
{
	ofstream file ;

	file.open("output.txt");

	//cout << "\nAlignment: \n\n";

	file << "\nAlignment: \n\n";

	for (size_t i = 0; i < align_A.length(); i++)
	{
		//cout << align_A[i] << " " << sign[i] << " " << align_B[i]<< endl; 

		file << align_A[i] << " " << sign[i] << " " << align_B[i]<< endl;
	}

	//cout << "\n";
	file << "\n";

	//cout << "Score: " << similarity_matrix[len_A][len_B] << "\n";
	file << "Score: " << similarity_matrix[len_A][len_B] << "\n";

	file.close();

}




