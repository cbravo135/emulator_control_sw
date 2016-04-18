#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "eth_lib.h"
#include "utils.h"
#include "commands.h"

using namespace std;

int main(int argc,char *argv[])
{
	eth_open("/dev/schar3");
	eth_reset();

    int addr = atoi(argv[1]);

	int e = write_command(1,addr);
	cout << "write command 1 status = " << e << endl;

	char* pkt;
	e = read_command(&pkt);
	cout << "read command 1 status = " << e << endl;
	
	dumphex(e, pkt, & std::cout);

	eth_close();

  	return e;
}
