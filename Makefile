######################################################################
#
#
#
#
#
#
######################################################################

all: LabF01 LabF02 LabF03

LabF01:
	gcc LabF01.c -o LabF01 -Wall -Wextra -std=c11

LabF02:
	gcc LabF02.c -o LabF02 -Wall -Wextra -std=c11

LabF03:
	gcc LabF03.c -o LabF03 -Wall -Wextra -std=c11

clean:
	rm -f LabF01 LabF02 LabF03

