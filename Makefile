compile :
	gcc t10_01.c ./libs/gender.c ./libs/dorm.c ./libs/student.c ./libs/repository.c -o t10_01 -Wall
	gcc t10_02.c ./libs/gender.c ./libs/dorm.c ./libs/student.c ./libs/repository.c -o t10_02 -Wall

test_01 :
	./t10_01

test_02 :
	./t10_02

	sha1sum ./storage/student-repository.txt
    sha1sum ./storage/dorm-repository.txt
    git restore ./storage/student-repository.txt
    git restore ./storage/dorm-repository.txt

