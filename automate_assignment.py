import os

#Problem 1

compile1 = "g++ DNA_Align.cpp main.cpp -o exec1 "

os.system(compile1)

execute1 = "./exec1 homosapiens_neanderthalensis_mitochondrion.txt homosapiens_mitochondrion.txt"

print("\nAligning DNA Sequences of Human vs Neanderthal Mitochondria\n")

print("\nPlease be patient\n")

os.system(execute1)

copy_clean = " cp output.txt human_neanderthal_mitochondria_alignment.txt ; rm -rf output.txt "

os.system(copy_clean)

print("\nFinished Aligning DNA Sequences of Human vs Neanderthal Mitochondria\n")

print("\nOpen human_neanderthal_mitochondria_alignment.txt to view the result\n")

print("\n............................................\n") 
   
#Problem2


print("\n Calculating DNA Distence between all possible pairs from 10 human races\n")

print("\n This may take up to half an hour as the DNA is aligned using O(mn) time complexity\n")

create_table = " python createTable.py > DNA_distance_table_intrahuman.txt"

os.system(create_table)

print("\n Finished creating table. Open DNA_distance_table_intrahuman.txt to view results\n")

print("\n.............................................\n")


#Problem3

print("\n Calculating DNA Distance between prototypical human sequence and 6 species of Great Apes\n")

create_table_Human_Great_Apes = " python createTable_Human_Great_Apes.py > DNA_Distance_Table_Human_Great_Apes.txt"

os.system(create_table_Human_Great_Apes)

print("\n Finished creating table. Open DNA_Distance_Table_Human_Great_Apes.txt to view results\n")

create_files = " python createfiles_Human_Great_Apes.py "

os.system(create_files)

print("\n Finished creating files. Open #GreatApesSpecies_alignment.txt to view results\n")


print("\n Finished calculating DNA Distance between prototypical human sequence and 6 species of Great Apes\n")	

print("\n ..................................................\n")





