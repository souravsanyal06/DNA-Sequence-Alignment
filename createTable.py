import os
import itertools

genome_bank_array = ["Algeria_EF064321" , "Armenia_AM263183" , "Chinese_AF346972" , "Egypt_EF060316" , "Fillipino_AF382012" , "Japanese_AF346989" , "Morocco_AF381983" , "Native_American_AY195748" , "Navajo_AY195787" , "South_American_Guarani_AF346984"]

print "DNA 1		  DNA2 				 Distance"

compile2 = "g++ DNA_Align_Score_only.cpp main.cpp -o exec2"

os.system(compile2)

for pair in itertools.combinations(genome_bank_array, 2 ):

        arg1 = pair[0]+ ".txt"
        arg2 = pair[1]+ ".txt"

        execute2 = "./exec2 " + arg1 + " " + arg2 
     
        os.system(execute2)

        file1 = open('score.txt')

        print pair[0] + " 		" + pair[1]+  "				 " + file1.readline()


