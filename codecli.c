#include <stdio.h>
#include <zmq.h>
#include <unistd.h>
#include <string.h>


int main(){
	void *context = zmq_ctx_new();
	void *requester = zmq_socket(context,ZMQ_REQ);
	zmq_connect(requester,"");
	int request_nbr;
	
	return 0;
}
