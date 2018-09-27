import os
import itertools

genome_bank_array = ["baboon_Y18001" , "Bonobo_D38116" , "Chimpanzee_D38113" , "Chimpanzee_X93335" , "Gorilla_D38114", "Gorilla_Western_Lowland_X93347"]

print "DNA1	  DNA2		  Distance"

DNA1 = "prototypical_human_sequence" 

arg1 = DNA1 + ".txt"

compile2 = "g++ DNA_Align.cpp main.cpp -o exec2"

os.system(compile2)

for x in genome_bank_array:

        arg2 = x + ".txt"

        execute2 = "./exec2 " + arg1 + " " + arg2 
     
        os.system(execute2)

        file1 = open('score.txt')
	

        print DNA1 + "		 " + x + "		 " + file1.readline()


