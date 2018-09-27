import os
import itertools

genome_bank_array = ["baboon_Y18001" , "Bonobo_D38116" , "Chimpanzee_D38113" , "Chimpanzee_X93335" , "Gorilla_D38114", "Gorilla_Western_Lowland_X93347"]


print "DNA1	  DNA2		  Distance"

DNA1 = "prototypical_human_sequence" 

arg1 = DNA1 + ".txt"

compile2 = "g++ DNA_Align.cpp main.cpp -o exec3"

os.system(compile2)

for x in genome_bank_array:

        arg2 = x + ".txt"

        execute3 = "./exec3 " + arg1 + " " + arg2 
     
        os.system(execute3)

        file1 = open('output.txt')
	
	destination_file_name = x +"_alignment.txt"

	write = " cp output.txt " + destination_file_name

	os.system(write)


        print DNA1 + "		 " + x + "		 " + file1.readline()


