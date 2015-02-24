Readme 
=========

Assignment 2 Implementation of BigQ Class - TPMMS Sort (Spring 2015 DBI)

TEAM:
=========
Sharath Chandra Darsha 	 UFID: 45194064

Suresh Koppisetty	 UFID: 18111766	

Important Note:
=========
We tested with 10M  and 1GB data, but only included 10MB Data with the code.Please set the correct path if you wanna test with 1GB Data/ or your own data.

Please make sure that the Data Path in the test.h is valid before you test.

Current Settings:
=========
char *catalog_path = "../source/catalog"; 
char *tpch_dir ="../DATA/10M/"; // dir where dbgen tpch files (extension *.tbl) can be found
char *dbfile_dir = ""; 


Folder Structure:
=========
./
./README
./Makefile
./source/
./bin/
./bin/testcases/
./DATA/10M/

Steps to compile:
=========
starting from the root folder

1. make clean				// Clean any previously compiled code 
2. make all				// Compile all the files necessary  
3. cd bin
4. ./test  		

5. sh sorttest.sh 		
// if you wanna do complete automated testing for following sortorders, please run above shell script - Settings are in the /bin/testcases folder

dbfile      |  sortby                                  |  CNF
---------------------------------------------------------------------------------
region      |  r_name 	 	                       | (r_name)
       
partsupp    |  ps_suppkey, ps_partkey 		       | (ps_suppkey) AND (ps_partkey)

lineitem    |  l_shipdate, l_extendedprice, l_quantity | (l_shipdate) AND 
							 (l_extendedprice) AND 
							 (l_quantity)


Executable Files:
========
2. test - test script to run the code (sort using BigQ) for various database tables.
3. sorttest.sh  - shell script to do automated testing with testcases from ./bin/testcases folder


Settings:
=========
The following variables control the various file locations and they are declared in test.h  (just after the #include header declarations):
	o dbfile_dir -- this is where the created heap db-files will be stored. By default, this is set to "" (thus all the heap dbfiles will be created in the "bin" directory).
	o tpch_dir -- this stores the directory path where the tpch-files can be found. The "/DATA/" directory already has the required table files generated by tpchgen and the path should be accessible by the program. We supplied only 10M data along with the code.
	o catalog_path -- this stores the catalog file path. By default this is set to "source" folder. 


Results with 1G Data
=========
suresh@suresh-Lenovo-G580:~/SimpleDb/bin$ sh sorttest.sh 
 
** IMPORTANT: MAKE SURE THE INFORMATION BELOW IS CORRECT **
 catalog location: 	../source/catalog
 tpch files dir: 	../DATA/1G/
 heap files dir: 	
 

 select test option: 
 	 1. sort 
 	 2. sort + display 
 	 3. sort + write 
	 
 select dbfile to use: 
	 1. nation 
	 2. region 
	 3. customer 
	 4. part 
	 5. partsupp 
	 6. orders 
	 7. lineitem 
 	 	
 specify runlength:
	 
 specify sort ordering (when done press ctrl-D):
	  
 tpch file will be loaded from ../DATA/1G/region.tbl
 producer: opened DBFile region.bin
 producer: inserted 5 recs into the pipe

TPMMS Merge start

TPMMS Merge done

 consumer: removed 5 recs from the pipe
 consumer: 5 recs out of 5 recs in sorted order 
 
** IMPORTANT: MAKE SURE THE INFORMATION BELOW IS CORRECT **
 catalog location: 	../source/catalog
 tpch files dir: 	../DATA/1G/
 heap files dir: 	
 

 select test option: 
 	 1. sort 
 	 2. sort + display 
 	 3. sort + write 
	 
 select dbfile to use: 
	 1. nation 
	 2. region 
	 3. customer 
	 4. part 
	 5. partsupp 
	 6. orders 
	 7. lineitem 
 	 	
 specify runlength:
	 
 specify sort ordering (when done press ctrl-D):
	  
 tpch file will be loaded from ../DATA/1G/lineitem.tbl
 producer: opened DBFile lineitem.bin
 producer: 100000
 producer: 200000
 producer: 300000
 producer: 400000
 producer: 500000
 producer: 600000
 producer: 700000
 producer: 800000
 producer: 900000
 producer: 1000000
 producer: 1100000
 producer: 1200000
 producer: 1300000
 producer: 1400000
 producer: 1500000
 producer: 1600000
 producer: 1700000
 producer: 1800000
 producer: 1900000
 producer: 2000000
 producer: 2100000
 producer: 2200000
 producer: 2300000
 producer: 2400000
 producer: 2500000
 producer: 2600000
 producer: 2700000
 producer: 2800000
 producer: 2900000
 producer: 3000000
 producer: 3100000
 producer: 3200000
 producer: 3300000
 producer: 3400000
 producer: 3500000
 producer: 3600000
 producer: 3700000
 producer: 3800000
 producer: 3900000
 producer: 4000000
 producer: 4100000
 producer: 4200000
 producer: 4300000
 producer: 4400000
 producer: 4500000
 producer: 4600000
 producer: 4700000
 producer: 4800000
 producer: 4900000
 producer: 5000000
 producer: 5100000
 producer: 5200000
 producer: 5300000
 producer: 5400000
 producer: 5500000
 producer: 5600000
 producer: 5700000
 producer: 5800000
 producer: 5900000
 producer: 6000000
 producer: inserted 6001215 recs into the pipe

TPMMS Merge start

TPMMS Merge done

 consumer: removed 6001215 recs from the pipe
 consumer: 6001215 recs out of 6001215 recs in sorted order 
 
** IMPORTANT: MAKE SURE THE INFORMATION BELOW IS CORRECT **
 catalog location: 	../source/catalog
 tpch files dir: 	../DATA/1G/
 heap files dir: 	
 

 select test option: 
 	 1. sort 
 	 2. sort + display 
 	 3. sort + write 
	 
 select dbfile to use: 
	 1. nation 
	 2. region 
	 3. customer 
	 4. part 
	 5. partsupp 
	 6. orders 
	 7. lineitem 
 	 	
 specify runlength:
	 
 specify sort ordering (when done press ctrl-D):
	  
 tpch file will be loaded from ../DATA/1G/partsupp.tbl
 producer: opened DBFile partsupp.bin
 producer: 100000
 producer: 200000
 producer: 300000
 producer: 400000
 producer: 500000
 producer: 600000
 producer: 700000
 producer: 800000
 producer: inserted 800000 recs into the pipe

TPMMS Merge start

TPMMS Merge done

 consumer: removed 800000 recs from the pipe
 consumer: 800000 recs out of 800000 recs in sorted order 

