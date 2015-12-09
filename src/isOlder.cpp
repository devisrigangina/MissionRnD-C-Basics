/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int date(char *);
int isOlder(char *dob1, char *dob2) {
	int i;
	if (date(dob1) == 1 && date(dob2) == 1)
	{
		i = 6;
		while (1)
		{
			if (dob1[i] - '0' == dob2[i] - '0')
			{
				i++;
				if (i == 9)
					i = 3;
				else if (i == 4)
					i = 0;
				else if (i == 2)
					return 0;
			}
			else
			{
				if (dob1[i] - '0' > dob2[i] - '0')
					return 1;
				else
					return 2;
			}
		}
	}
	else
		return -1;

}
int date(char *dob)
{
	int i,d=1,db,dd,mm,yy,c=0;
	for (i = dob[0]; dob[i] != '\0'; i++)
	{
		if (dob[i] != '-')
		{
			dob[i] = dob[i] - 48;
			d = d + dob[i] * 10;
		}
		else
		{
			c++;
			if (c == 1)
				dd = d;
			else if (c == 2)
				mm = d;
			else
				yy = d;
		}
	}
	int bissextile = (yy % 4 == 0) ? 1 : 0;

	if (dd > 31 || dd<1 || mm>12 || mm < 1)
		return 0;
	else
		if ((mm == 2 && dd < 30 && bissextile) || (mm == 2 && dd < 29 && bissextile == 0))
			return 1;
		else
			if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd < 31)
				return 1;
			else
				if (dd < 31 && mm != 2)
					return 1;
				else
					return 0;

}